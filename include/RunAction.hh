//
// Created by student on 27.04.18.
//

#ifndef M_DGW_4_RUNACTION_HH
#define M_DGW_4_RUNACTION_HH


#include <G4UserRunAction.hh>
#include <map>
#include <G4String.hh>
#include "EventAction.hh"

class RunAction : public G4UserRunAction {
public:
    RunAction();
    ~RunAction();
    void BeginOfRunAction(const G4Run* aRun) override;
    void EndOfRunAction(const G4Run* aRun) override;
    void AddEvent(G4double Energy);

private:
    std::map<G4double, G4int>* result;
    G4double tubs;
    RunAction* run;
 //   EventAction* AddEvent;
};

#endif //M_DGW_4_RUNACTION_HH
