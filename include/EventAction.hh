//
// Created by student on 27.04.18.
//

#ifndef M_DGW_4_EVENTACTION_HH
#define M_DGW_4_EVENTACTION_HH


#include "RunAction.hh"
#include "StepAction.hh"
#include <G4UserEventAction.hh>
#include <G4String.hh>
using namespace std;
class RunAction;

class EventAction : public G4UserEventAction {
public:
    EventAction(RunAction* runAct);
    ~EventAction();

    virtual void BeginOfEventAction(const G4Event* anEvent);
    virtual void EndOfEventAction(const G4Event* anEvent);
    void Dat(G4String Name,G4double energy);
private:
    map<G4String, G4double> *res;
    G4double EnergyDep;
    RunAction * run;

};



#endif //M_DGW_4_EVENTACTION_HH
