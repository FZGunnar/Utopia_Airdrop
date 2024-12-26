class CfgPatches
{
	class Custom_Proxies
	{
		units[]=
		{
			"Airdrop_Flaregun",
			"Flare_Bullet_1",
			"Flare_Bullet_2",
			"Flare_Bullet_3",
			"Flare_Bullet_4",
			"Flare_Bullet_5",
			"Flare_Bullet_6",
			"Flare_Bullet_7",
			"Flare_Bullet_8",
			"Flare_Bullet_9",
			"Flare_Bullet_10"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = 
		{
			"DZ_Data"
		};
	};
};

class CfgSlots {
	class Slot_Airdrop_Flaregun
	{
		name = "Airdrop_Flaregun";
		displayName = "Airdrop_Flaregun";
		ghostIcon = "set:Airdrop_Flaregun image:Flaregun";
	};
	class Slot_Flare_Bullet_1 {
		name = "Flare_Bullet_1";
		displayName = "Flare_Bullet_1";
		ghostIcon = "set:Flare_Bullet image:Bullet";
	};
	class Slot_Flare_Bullet_2 {
		name = "Flare_Bullet_2";
		displayName = "Flare_Bullet_2";
		ghostIcon = "set:Flare_Bullet image:Bullet";
	};
	class Slot_Flare_Bullet_3 {
		name = "Flare_Bullet_3";
		displayName = "Flare_Bullet_3";
		ghostIcon = "set:Flare_Bullet image:Bullet";
	};
	class Slot_Flare_Bullet_4 {
		name = "Flare_Bullet_4";
		displayName = "Flare_Bullet_4";
		ghostIcon = "set:Flare_Bullet image:Bullet";
	};
	class Slot_Flare_Bullet_5 {
		name = "Flare_Bullet_5";
		displayName = "Flare_Bullet_5";
		ghostIcon = "set:Flare_Bullet image:Bullet";
	};
	class Slot_Flare_Bullet_6 {
		name = "Flare_Bullet_6";
		displayName = "Flare_Bullet_6";
		ghostIcon = "set:Flare_Bullet image:Bullet";
	};
	class Slot_Flare_Bullet_7 {
		name = "Flare_Bullet_7";
		displayName = "Flare_Bullet_7";
		ghostIcon = "set:Flare_Bullet image:Bullet";
	};
	class Slot_Flare_Bullet_8 {
		name = "Flare_Bullet_8";
		displayName = "Flare_Bullet_8";
		ghostIcon = "set:Flare_Bullet image:Bullet";
	};
	class Slot_Flare_Bullet_9 {
		name = "Flare_Bullet_9";
		displayName = "Flare_Bullet_9";
		ghostIcon = "set:Flare_Bullet image:Bullet";
	};
	class Slot_Flare_Bullet_10 {
		name = "Flare_Bullet_10";
		displayName = "Flare_Bullet_10";
		ghostIcon = "set:Flare_Bullet image:Bullet";
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyAirdrop_Flaregun: ProxyAttachment
	{
		inventorySlot[] = {"Airdrop_Flaregun"};
		model = "Utopia_Airdrop\Models\Flare\Proxies\Airdrop_Flaregun.p3d";
	};
	class ProxyFlare_Bullet_1: ProxyAttachment
	{
		inventorySlot[] = {"Flare_Bullet_1"};
		model = "Utopia_Airdrop\Models\Flare\Proxies\Flare_Bullet_1.p3d";
	};
	class ProxyFlare_Bullet_2: ProxyAttachment
	{
		inventorySlot[] = {"Flare_Bullet_2"};
		model = "Utopia_Airdrop\Models\Flare\Proxies\Flare_Bullet_2.p3d";
	};
	class ProxyFlare_Bullet_3: ProxyAttachment
	{
		inventorySlot[] = {"Flare_Bullet_3"};
		model = "Utopia_Airdrop\Models\Flare\Proxies\Flare_Bullet_3.p3d";
	};
	class ProxyFlare_Bullet_4: ProxyAttachment
	{
		inventorySlot[] = {"Flare_Bullet_4"};
		model = "Utopia_Airdrop\Models\Flare\Proxies\Flare_Bullet_4.p3d";
	};
	class ProxyFlare_Bullet_5: ProxyAttachment
	{
		inventorySlot[] = {"Flare_Bullet_5"};
		model = "Utopia_Airdrop\Models\Flare\Proxies\Flare_Bullet_5.p3d";
	};
	class ProxyFlare_Bullet_6: ProxyAttachment
	{
		inventorySlot[] = {"Flare_Bullet_6"};
		model = "Utopia_Airdrop\Models\Flare\Proxies\Flare_Bullet_6.p3d";
	};
	class ProxyFlare_Bullet_7: ProxyAttachment
	{
		inventorySlot[] = {"Flare_Bullet_7"};
		model = "Utopia_Airdrop\Models\Flare\Proxies\Flare_Bullet_7.p3d";
	};
	class ProxyFlare_Bullet_8: ProxyAttachment
	{
		inventorySlot[] = {"Flare_Bullet_8"};
		model = "Utopia_Airdrop\Models\Flare\Proxies\Flare_Bullet_8.p3d";
	};
	class ProxyFlare_Bullet_9: ProxyAttachment
	{
		inventorySlot[] = {"Flare_Bullet_9"};
		model = "Utopia_Airdrop\Models\Flare\Proxies\Flare_Bullet_9.p3d";
	};
	class ProxyFlare_Bullet_10: ProxyAttachment
	{
		inventorySlot[] = {"Flare_Bullet_10"};
		model = "Utopia_Airdrop\Models\Flare\Proxies\Flare_Bullet_10.p3d";
	};
};