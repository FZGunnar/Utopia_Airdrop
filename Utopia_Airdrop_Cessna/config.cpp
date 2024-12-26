class CfgPatches
{
	class Utopia_Airdrop_Cessna
	{
		units[]= 
		{
			"Utopia_Airdrop_Cessna"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]= {"DZ_Data","Utopia_Airdrop"};
	};
};
class CfgMods
{
	class Utopia_Airdrop_Cessna
	{
		dir="Utopia_Airdrop_Cessna";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="Utopia_Airdrop_Cessna";
		credits="Utopia";
		author="Genesis";
		authorID="76561198273516768";
		version="0.3";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"Utopia_Airdrop_Cessna/Scripts/4_World"
				};
			};
		};
	};
};


