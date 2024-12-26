class UtopiaAirdropItem
{
    string name;
    int quantity;
    ref array<ref UtopiaAirdropAttachment> attachments;

    void UtopiaAirdropItem(string _name, int _quantity)
    {
        name = _name;
        quantity = _quantity;

        attachments = new array<ref UtopiaAirdropAttachment>();
    }
}