#include <EventAction.hh>
#include <StepAction.hh>
#include "ActionInit.hh"

ActionInit::ActionInit()
{ }

ActionInit::~ActionInit()
{ }

void ActionInit::Build() const
{
    SetUserAction(new PrimaryGen());

    RunAction * run=new RunAction;
    SetUserAction(run);

    EventAction* eventAction=new EventAction(run);
    SetUserAction(eventAction);

    SetUserAction(new StepAction(eventAction));
}