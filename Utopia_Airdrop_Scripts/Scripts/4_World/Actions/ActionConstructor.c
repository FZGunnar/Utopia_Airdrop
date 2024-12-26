modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert(AIR_ActionCustomOpen);
        actions.Insert(Case_ActionCustomClose);
        actions.Insert(Case_ActionCustomOpen);
        actions.Insert(ActionRemoveNetting);
    }
};
