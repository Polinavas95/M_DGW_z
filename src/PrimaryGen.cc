#include <Randomize.hh>
#include "PrimaryGen.hh"
PrimaryGen::PrimaryGen() {
    gun = new G4ParticleGun(1);
    G4cout << "Primary particles generator is created successfully\t\tOK!!!" << G4endl;
}

PrimaryGen::~PrimaryGen()
{ }

void PrimaryGen::GeneratePrimaries(G4Event* anEvent) {

    gun->GeneratePrimaryVertex(anEvent);
}
