modded class UtopiaMarkerManager
{
    private static int s_currentMarkerId = 0;

    #ifdef BASICMAP
    private static ref map<int, BasicMapMarker> mapMarkerBasicMap = new map<int, BasicMapMarker>();
    #endif

    #ifdef BASICMAP
    static int AddBMMarker(BasicMapMarker marker)
    {
        ++s_currentMarkerId;
        mapMarkerBasicMap.Set(s_currentMarkerId, marker);
        UtopiaLogger().LogDebug("AddBMMarker: id" + s_currentMarkerId);
        return s_currentMarkerId;
    }
    #endif

    #ifdef BASICMAP
    static void RemoveBMMarker(int id)
    {
        BasicMapMarker marker = mapMarkerBasicMap.Get(id);
        UtopiaLogger().LogDebug("RemoveBMMarker: id" + id);
        if(!marker){
            return;
        }
        UtopiaLogger().LogDebug("Remove marker");

        BasicMap().AirdropRemoveMarker(marker);
    }
    #endif

}