class UtopiaAirdropContainer
{
    bool isCarDrop;
    string containerName;
    ref TStringArray lootPools;

    void UtopiaAirdropContainer(bool _carDrop, string _containerName)
    {
        isCarDrop = _carDrop;
        containerName = _containerName;
        lootPools = new TStringArray();
    }

    string PickLootPool()
    {
        return lootPools.GetRandomElement();
    }
}

class UtopiaAirdropFlareContainer : UtopiaAirdropContainer
{
    string itemName;
    string planeType; // Field for specifying the plane type for this flare-triggered drop
    ref array<string> creaturesToSpawn; // Array to hold creature classnames to be spawned

    void UtopiaAirdropFlareContainer(bool _carDrop, string _containerName, string _itemName="Bullet_Car_Flare")//skip
    {
        // Call the base class constructor
        UtopiaAirdropContainer(_carDrop, _containerName);

        // Initialize flare-specific properties
        itemName = _itemName;
        planeType = "Utopia_S64_Skycrane"; // Set a default plane type if not provided
        creaturesToSpawn = new array<string>(); // Initialize an empty array for creatures
    }
}
