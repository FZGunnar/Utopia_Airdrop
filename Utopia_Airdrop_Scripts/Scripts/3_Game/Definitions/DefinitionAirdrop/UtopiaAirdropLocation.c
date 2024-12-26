class UtopiaAirdropLocation
{
    [NonSerialized()]
    int markerId;
    string name;
    vector dropPosition;
    int radius;
    string planeType;
    ref array<ref UtopiaAirdropContainer> airdropContainers;

    ref array<string> creaturesToSpawn; // List of creatures to spawn at this location
    int numberOfCreatures;              // Number of creatures to spawn at this location

    void UtopiaAirdropLocation(string name, vector dropPosition, int radius, string planeType = "", string _calledBy = "")
    {
        this.name = name;
        this.dropPosition = dropPosition;
        this.radius = radius;
        this.planeType = planeType;

        airdropContainers = new array<ref UtopiaAirdropContainer>();
        creaturesToSpawn = new array<string>(); // Initialize the creaturesToSpawn array
        numberOfCreatures = 0; // Default number of creatures to spawn
    }

    void SetMarkerId(int id)
    {
        markerId = id;
    }

    UtopiaAirdropContainer PickContainer()
    {
        return airdropContainers.GetRandomElement();
    }
}
