//
// Created by student on 27.04.18.
//

#ifndef M_DGW_4_EVENTACTION_HH
#define M_DGW_4_EVENTACTION_HH


#include "RunAction.hh"
#include <G4UserEventAction.hh>
#include <G4String.hh>
using namespace std;
class RunAction;

class EventAction : public G4UserEventAction {
public:
    EventAction(RunAction* runAct);
    ~EventAction();
    void BeginOfEventAction(const G4Event* anEvent);
    void EndOfEventAction(const G4Event* anEvent);
    void AddEvent(G4String Name,G4double energy);
private:
    map<G4String, G4double> *res;
    RunAction * run;
    G4double EnergyDep;
};



#endif //M_DGW_4_EVENTACTION_HH
