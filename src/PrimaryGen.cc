#include <Randomize.hh>
#include <G4Neutron.hh>
#include "PrimaryGen.hh"
PrimaryGen::PrimaryGen() {

    gun = new G4ParticleGun(1);

}

PrimaryGen::~PrimaryGen(){

 }

void PrimaryGen::GeneratePrimaries(G4Event* anEvent) {
    G4double q1=2 * G4UniformRand() - 1;
    G4double q2=2 * G4UniformRand() - 1;
    G4double q3=2 * G4UniformRand() - 1;
    G4double l=sqrt(pow(q1,2)+pow(q2,2)+pow(q3,2));

    gun->SetParticleDefinition(G4Neutron::NeutronDefinition());
    gun->SetParticlePosition(G4ThreeVector(50.*cm, 0, 0));
    gun->SetParticleEnergy(14. * MeV);
    gun->SetParticleMomentumDirection(G4ThreeVector(q1 / l, q2 / l, q3 / l));
    gun->GeneratePrimaryVertex(anEvent);
}


