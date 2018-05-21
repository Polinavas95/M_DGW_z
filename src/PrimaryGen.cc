#include <Randomize.hh>
#include <G4Neutron.hh>
#include "PrimaryGen.hh"
PrimaryGen::PrimaryGen() {

    gun = new G4ParticleGun(1);

}

PrimaryGen::~PrimaryGen(){

 }

void PrimaryGen::GeneratePrimaries(G4Event* anEvent) {
    G4double i = G4UniformRand();
    G4double X = 20, Y = 20, Z = 20, R = 20 * cm;

//    while (sqrt(X * X + Y * Y + Z * Z) > R) {
//        X = (-20+20*(2 * G4UniformRand() - 1));
//        Y = (20*(2 * G4UniformRand() - 1));
//        Z = (20*(2 * G4UniformRand() - 1));
//    }
    gun->SetParticleDefinition(G4Neutron::NeutronDefinition());
    gun->SetParticlePosition(G4ThreeVector(- 10.*cm, 0, 0));
    gun->SetParticleEnergy(14. * MeV);
    gun->SetParticleMomentumDirection(G4ThreeVector(1,0,0));
    gun->GeneratePrimaryVertex(anEvent);
}
//    G4double X2=6.5,Y2=7.6,Z2=7.6,R2=7.6*cm;
//    while(sqrt(X2*X2+Y2*Y2+Z2*Z2)>R2){
//        X2=(3.25*(2*G4UniformRand()-1));
//        Y2=(3.8*(2*G4UniformRand()-1));
//        Z2=(3.8*(2*G4UniformRand()-1));
//    }
//        gun->SetParticleDefinition(G4Gamma::GammaDefinition());
//        gun->SetParticlePosition(G4ThreeVector(X2+23.25,Y2,Z2));
//        gun->SetParticleEnergy();
//        gun->SetParticleMomentum(G4ThreeVector(2 * G4UniformRand() - 1, 2 * G4UniformRand() - 1, 2 * G4UniformRand() - 1));
//}

