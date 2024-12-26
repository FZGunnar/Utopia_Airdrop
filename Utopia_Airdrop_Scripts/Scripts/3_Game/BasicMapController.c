#ifdef BASICMAP
modded class BasicMapController
{

	bool AirdropRemoveMarkerByVector(vector pos, float distance = 10, bool overrideSettings = false){
		//UtopiaLogger().LogDebug("AirdropRemoveMarkerByVector");
		//UtopiaLogger().LogDebug("pos: " + pos);
		for (int j = 0; j < Markers.Count(); j++)
		{
			for (int k = 0; k < Markers.GetElement(j).Count(); k++)
			{
				//UtopiaLogger().LogDebug("Name:" + Markers.GetElement(j).Get(k).GetName() + " distance: " + vector.Distance(Markers.GetElement(j).Get(k).GetPosition(), pos));
				//UtopiaLogger().LogDebug("pos marker: " + Markers.GetElement(j).Get(k).GetPosition());
				if (vector.Distance(Markers.GetElement(j).Get(k).GetPosition(), pos) < distance && (Markers.GetElement(j).Get(k).Editable() || overrideSettings))
				{
					OnMarkerDelete(Markers.GetElement(j).Get(k));
					//UtopiaLogger().LogDebug("OnMarkerDelete");
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(Markers.GetElement(j).RemoveOrdered, k); //So that way OnMarkerDelete is called before the delete encase this is the last ref
					return true;
				}
			}
		}
		return false;
	}

	bool AirdropRemoveMarker(BasicMapMarker marker){
		for (int j = 0; j < Markers.Count(); j++){
			for (int k = 0; k < Markers.GetElement(j).Count(); k++){
				if (marker == Markers.GetElement(j).Get(k)){
					OnMarkerDelete(marker); 
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(Markers.GetElement(j).RemoveOrdered, k);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(UpdateServerMarker, 500, false);
					return true;
				}
			}
		}
		return false;
	}

	void UpdateServerMarker()
	{
		array<autoptr BasicMapMarker> ServerMarkers = new array<autoptr BasicMapMarker>;
		array<autoptr BasicMapCircleMarker> ServerCircleMarkers = new array<autoptr BasicMapCircleMarker>;
		if (Markers.Get(SERVER_KEY)){
			BasicMapCircleMarker cMarker;
			for ( int j = 0; j < Markers.Get(SERVER_KEY).Count(); j++){
				if (Markers.Get(SERVER_KEY).Get(j).IsInherited(BasicMapCircleMarker) && Class.CastTo(cMarker, Markers.Get(SERVER_KEY).Get(j)) && cMarker.GetRadius() > 0){
					ServerCircleMarkers.Insert(cMarker);
				} else {
					ServerMarkers.Insert(Markers.Get(SERVER_KEY).Get(j));
				}
			}
		}

		GetRPCManager().SendRPC("BasicMap", "RPCSyncServerData", new Param3< array<autoptr BasicMapMarker>,  array<autoptr BasicMapCircleMarker>, ref BasicMapConfig>( ServerMarkers, ServerCircleMarkers, GetBasicMapConfig() ), true, null);
	}

	BasicMapMarker CreateAirdropServerMarker(string name, vector position) {

		array<autoptr BasicMapMarker> ServerMarkers = new array<autoptr BasicMapMarker>;
		array<autoptr BasicMapCircleMarker> ServerCircleMarkers = new array<autoptr BasicMapCircleMarker>;
		//UtopiaLogger().LogDebug("CreateAirdropServerMarker: " + name + " " + position);
		string markerIcon = "Utopia_Airdrop\\Datasets\\airdrop.paa";//skip
		bool isEditable = false; 
		BasicMapMarker serverMarker = new BasicMapMarker(name, position, markerIcon, {255, 188, 0}, 255, isEditable);
		AddMarker(BasicMapController.SERVER_KEY, serverMarker);
		
		if (Markers.Get(SERVER_KEY)){
				BasicMapCircleMarker cMarker;
				for ( int j = 0; j < Markers.Get(SERVER_KEY).Count(); j++){
					if (Markers.Get(SERVER_KEY).Get(j).IsInherited(BasicMapCircleMarker) && Class.CastTo(cMarker, Markers.Get(SERVER_KEY).Get(j)) && cMarker.GetRadius() > 0){
						ServerCircleMarkers.Insert(cMarker);
					} else {
						ServerMarkers.Insert(Markers.Get(SERVER_KEY).Get(j));
					}
				}
		}

		GetRPCManager().SendRPC("BasicMap", "RPCSyncServerData", new Param3< array<autoptr BasicMapMarker>,  array<autoptr BasicMapCircleMarker>, ref BasicMapConfig>( ServerMarkers, ServerCircleMarkers, GetBasicMapConfig() ), true, null);
		return serverMarker;
	}
}
#endif