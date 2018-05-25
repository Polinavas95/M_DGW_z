#include <G4VisAttributes.hh>
#include "DetGeometry.hh"
#include "G4Tubs.hh"
#include "G4PhysicalConstants.hh"
#include <fstream>
using namespace std;
DetGeometry::DetGeometry() {
    world_sizeXYZ   = 5 * m;
    nist            = G4NistManager::Instance();
    world_mat       = nist->FindOrBuildMaterial("G4_AIR");

    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);
    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
}

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct() {
    G4Isotope *Pb202 = new G4Isotope("Pb202", 82, 202);
    G4Isotope *Pb204 = new G4Isotope("Pb204", 82, 204);
    G4Isotope *Pb206 = new G4Isotope("Pb206", 82, 206);
    G4Isotope *Pb207 = new G4Isotope("Pb207", 82, 207);
    G4Isotope *Pb208 = new G4Isotope("Pb208", 82, 208);

    G4Element *Pb = new G4Element("Plumbum", "Pb", 5);
    Pb->AddIsotope(Pb202, 0.2 * perCent);
    Pb->AddIsotope(Pb204, 1.5 * perCent);
    Pb->AddIsotope(Pb206, 23.6 * perCent);
    Pb->AddIsotope(Pb207, 22.6 * perCent);
    Pb->AddIsotope(Pb208, 52.1 * perCent);

    G4Material *Pb1 = new G4Material("Pb1", 3.5 * g / cm3, 1, kStateSolid);
    Pb1->AddElement(Pb,5);

    G4Isotope *C12 = new G4Isotope("C12", 6, 12);
    G4Isotope *C13 = new G4Isotope("C13", 6, 13);
    G4Element *C = new G4Element("Carbon", "C", 2);
    C->AddIsotope(C12, 98.93 * perCent);
    C->AddIsotope(C13, 1.07 * perCent);
    G4Material *C1 = new G4Material("C1", 3.5 * g / cm3, 1, kStateSolid);
    C1->AddElement(C,2);

    G4Box *box = new G4Box("box", 11. * cm, 11. * cm, 11. * cm);
    auto box_log = new G4LogicalVolume(box, nist->FindOrBuildMaterial("C1"), "box_LOG");
    box_log->SetVisAttributes(G4Colour::Red());
    new G4PVPlacement(0, G4ThreeVector(0, 0, 0.), box_log, "box_PV", logicWorld, false, 0);

    G4RotationMatrix *rotation = new G4RotationMatrix(-45 * deg, 0, 0);

    G4Box *box1 = new G4Box("box1", 20. * cm, 5. * cm, 7. * cm);
    auto box1_log = new G4LogicalVolume(box1, nist->FindOrBuildMaterial("Pb1"), "box1_LOG");
    box1_log->SetVisAttributes(G4Colour::Red());
    new G4PVPlacement(rotation, G4ThreeVector(40.*cm, -50.*cm, -50.*cm), box1_log, "box1_PV", logicWorld, false, 0);

    G4Tubs *tubs = new G4Tubs("tubs", 0, 7.6 * cm, 6.5 * cm, 0, 2 * pi);
    auto tubs_log = new G4LogicalVolume(tubs, nist->FindOrBuildMaterial("G4_BGO"), "tubs_LOG");
    //tubs_log->SetVisAttributes(G4Colour::Red());
    new G4PVPlacement(rotation, G4ThreeVector( 30.* cm, -60.*cm, -50.*cm), tubs_log, "tubs_PV", logicWorld, false, 0);

    ofstream fout("../result.txt");
    fout<<"\n"<<Pb1;
    fout<<"\n"<<C1;
//    fout<<"\n\n\n\n"<<box_log->GetMass(false)/g<<endl;
//    fout<<"\n\n\n\n"<<box1_log->GetMass(false)/g<<endl;
    fout.close();


    return physWorld;
}


