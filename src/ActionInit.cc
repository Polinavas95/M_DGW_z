#include <EventAction.hh>
#include <StepAction.hh>
#include "ActionInit.hh"

ActionInit::ActionInit()
{ }

ActionInit::~ActionInit()
{ }

void ActionInit::Build() const
{
    auto runAct = new RunAction;
    auto eventAction = new EventAction(runAct);
    SetUserAction(new PrimaryGen());


    SetUserAction(new StepAction(eventAction));
    SetUserAction(eventAction);
    SetUserAction(runAct);

}