class UtopiaAirdropLootPool
{
    string lootPoolName;
    int    maxItems;
    ref array<ref UtopiaAirdropItem> items;

    void UtopiaAirdropLootPool(string _lootPoolName, int _maxItems)
    {
        lootPoolName = _lootPoolName;
        maxItems = _maxItems;

        items = new array<ref UtopiaAirdropItem>();
    }
}