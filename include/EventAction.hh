//
// Created by student on 27.04.18.
//

#ifndef M_DGW_4_EVENTACTION_HH
#define M_DGW_4_EVENTACTION_HH


#include "RunAction.hh"
#include <G4UserEventAction.hh>

class RunAction;

class EventAction : public G4UserEventAction {
public:
    EventAction(RunAction* runAct);
    ~EventAction();
    void BeginOfEventAction(const G4Event* anEvent);
    void EndOfEventAction(const G4Event* anEvent);
    void AddEnDep(G4double en);
private:
    RunAction * run;
    G4double EnergyDep;
};



#endif //M_DGW_4_EVENTACTION_HH
