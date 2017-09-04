//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file OpNovice/src/OpNoviceDetectorConstruction.cc
/// \brief Implementation of the OpNoviceDetectorConstruction class
//
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "OpNoviceDetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Element.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpticalSurface.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"
#include "G4VPhysicalVolume.hh"
#include "G4RotationMatrix.hh"
#include "G4SubtractionSolid.hh"
 G4bool checkOverlaps = true;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorConstruction::OpNoviceDetectorConstruction(G4double tw_p, G4double th_p, G4double tl_p)
 : G4VUserDetectorConstruction()

//OpNoviceDetectorConstruction::OpNoviceDetectorConstruction(G4double th_p)
// : G4VUserDetectorConstruction()


{
  fExpHall_x = fExpHall_y = fExpHall_z = 1.5*m;
  tw = tw_p;
  th = th_p;
  tl = tl_p;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorConstruction::~OpNoviceDetectorConstruction(){;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* OpNoviceDetectorConstruction::Construct()
{





  // Get nist material manager (ez ad anyagot)
  G4NistManager* nist = G4NistManager::Instance();
// ------------- Materials -------------

  G4double a, z, density;
  G4int nelements;

  G4double density_psm;
  G4double density_pmma;

// Air
//
  G4Element* N = new G4Element("Nitrogen", "N", z=7 , a=14.01*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8 , a=16.00*g/mole);

  G4Material* air = new G4Material("Air", density=1.29*mg/cm3, nelements=2);
  air->AddElement(N, 70.*perCent);
  air->AddElement(O, 30.*perCent);

// Water
//
  G4Element* H = new G4Element("Hydrogen", "H", z=1 , a=1.01*g/mole);
  G4Material* water = new G4Material("Water", density= 1.0*g/cm3, nelements=2);
  water->AddElement(H, 2);
  water->AddElement(O, 1);

//Si
//
  G4Material* tank2_mat = nist->FindOrBuildMaterial("G4_Si");
  //G4Element* Si = new G4Element("Silicium", "Si", z=14 , a=28.01*g/mole);
  //G4Material* Si = new G4Material("Silicium", density= 2.57*g/cm3, nelements=1);


//PMMA, Polystyrene
//
	G4Element* C = new G4Element("Carbon", "C", z=6 , a=12.01*g/mole);
    G4Material* pmma = new G4Material("PMMA", density_pmma = 1.190*g/cm3, nelements=3);
    pmma->AddElement(C, 33.34*perCent);
    pmma->AddElement(H, 53.33*perCent);
    pmma->AddElement(O, 13.33*perCent);

    G4Material* psm = new G4Material("Polystyrene", density_psm = 1.05*g/cm3, nelements=2);
    psm->AddElement(C, 50.00*perCent);
    psm->AddElement(H, 50.00*perCent);

    //G4Tubs* tube_in = new G4Tubs("Tube", 0*cm, (r-(0.003)), fTank_z, 0*deg, 360*deg);
    //G4Tubs* tube_ring = new G4Tubs("Tube", (r-(0.003)), r, fTank_z, 0*deg, 360*deg);

    //G4LogicalVolume* tubein_log = new G4LogicalVolume(tube_in,psm,"Tube_in");
    //G4LogicalVolume* tubering_log = new G4LogicalVolume(tube_ring,pmma,"Tube_ring");

//
// ------------ Generate & Add Material Properties Table ------------
//
  G4double photonEnergy[] =
            { 2.034*eV, 2.068*eV, 2.103*eV, 2.139*eV,
              2.177*eV, 2.216*eV, 2.256*eV, 2.298*eV,
              2.341*eV, 2.386*eV, 2.433*eV, 2.481*eV,
              2.532*eV, 2.585*eV, 2.640*eV, 2.697*eV,
              2.757*eV, 2.820*eV, 2.885*eV, 2.954*eV,
              3.026*eV, 3.102*eV, 3.181*eV, 3.265*eV,
              3.353*eV, 3.446*eV, 3.545*eV, 3.649*eV,
              3.760*eV, 3.877*eV, 4.002*eV, 4.136*eV };

  const G4int nEntries = sizeof(photonEnergy)/sizeof(G4double);

//
// Water
//
  G4double refractiveIndex1[] =
            { 1.3435, 1.344,  1.3445, 1.345,  1.3455,
              1.346,  1.3465, 1.347,  1.3475, 1.348,
              1.3485, 1.3492, 1.35,   1.3505, 1.351,
              1.3518, 1.3522, 1.3530, 1.3535, 1.354,
              1.3545, 1.355,  1.3555, 1.356,  1.3568,
              1.3572, 1.358,  1.3585, 1.359,  1.3595,
              1.36,   1.3608};

  assert(sizeof(refractiveIndex1) == sizeof(photonEnergy));

  G4double absorption[] =
           {3.448*m,  4.082*m,  6.329*m,  9.174*m, 12.346*m, 13.889*m,
           15.152*m, 17.241*m, 18.868*m, 20.000*m, 26.316*m, 35.714*m,
           45.455*m, 47.619*m, 52.632*m, 52.632*m, 55.556*m, 52.632*m,
           52.632*m, 47.619*m, 45.455*m, 41.667*m, 37.037*m, 33.333*m,
           30.000*m, 28.500*m, 27.000*m, 24.500*m, 22.000*m, 19.500*m,
           17.500*m, 14.500*m };

  assert(sizeof(absorption) == sizeof(photonEnergy));

  G4double scintilFast[] =
            { 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00 };

  assert(sizeof(scintilFast) == sizeof(photonEnergy));

  G4double scintilSlow[] =
            { 0.01, 1.00, 2.00, 3.00, 4.00, 5.00, 6.00,
              7.00, 8.00, 9.00, 8.00, 7.00, 6.00, 4.00,
              3.00, 2.00, 1.00, 0.01, 1.00, 2.00, 3.00,
              4.00, 5.00, 6.00, 7.00, 8.00, 9.00, 8.00,
              7.00, 6.00, 5.00, 4.00 };

  assert(sizeof(scintilSlow) == sizeof(photonEnergy));

  G4MaterialPropertiesTable* myMPT1 = new G4MaterialPropertiesTable();

  myMPT1->AddProperty("RINDEX",       photonEnergy, refractiveIndex1,nEntries)
        ->SetSpline(true);
  myMPT1->AddProperty("ABSLENGTH",    photonEnergy, absorption,     nEntries)
        ->SetSpline(true);
  myMPT1->AddProperty("FASTCOMPONENT",photonEnergy, scintilFast,     nEntries)
        ->SetSpline(true);
  myMPT1->AddProperty("SLOWCOMPONENT",photonEnergy, scintilSlow,     nEntries)
        ->SetSpline(true);

  myMPT1->AddConstProperty("SCINTILLATIONYIELD",5./MeV);
  myMPT1->AddConstProperty("RESOLUTIONSCALE",1.0);
  myMPT1->AddConstProperty("FASTTIMECONSTANT", 1.*ns);
  myMPT1->AddConstProperty("SLOWTIMECONSTANT",10.*ns);
  myMPT1->AddConstProperty("YIELDRATIO",0.8);

  G4double energy_water[] = {
     1.56962*eV, 1.58974*eV, 1.61039*eV, 1.63157*eV,
     1.65333*eV, 1.67567*eV, 1.69863*eV, 1.72222*eV,
     1.74647*eV, 1.77142*eV, 1.7971 *eV, 1.82352*eV,
     1.85074*eV, 1.87878*eV, 1.90769*eV, 1.93749*eV,
     1.96825*eV, 1.99999*eV, 2.03278*eV, 2.06666*eV,
     2.10169*eV, 2.13793*eV, 2.17543*eV, 2.21428*eV,
     2.25454*eV, 2.29629*eV, 2.33962*eV, 2.38461*eV,
     2.43137*eV, 2.47999*eV, 2.53061*eV, 2.58333*eV,
     2.63829*eV, 2.69565*eV, 2.75555*eV, 2.81817*eV,
     2.88371*eV, 2.95237*eV, 3.02438*eV, 3.09999*eV,
     3.17948*eV, 3.26315*eV, 3.35134*eV, 3.44444*eV,
     3.54285*eV, 3.64705*eV, 3.75757*eV, 3.87499*eV,
     3.99999*eV, 4.13332*eV, 4.27585*eV, 4.42856*eV,
     4.59258*eV, 4.76922*eV, 4.95999*eV, 5.16665*eV,
     5.39129*eV, 5.63635*eV, 5.90475*eV, 6.19998*eV
  };

  const G4int numentries_water = sizeof(energy_water)/sizeof(G4double);

  //assume 100 times larger than the rayleigh scattering for now.
  G4double mie_water[] = {
     167024.4*m, 158726.7*m, 150742  *m,
     143062.5*m, 135680.2*m, 128587.4*m,
     121776.3*m, 115239.5*m, 108969.5*m,
     102958.8*m, 97200.35*m, 91686.86*m,
     86411.33*m, 81366.79*m, 76546.42*m,
     71943.46*m, 67551.29*m, 63363.36*m,
     59373.25*m, 55574.61*m, 51961.24*m,
     48527.00*m, 45265.87*m, 42171.94*m,
     39239.39*m, 36462.50*m, 33835.68*m,
     31353.41*m, 29010.30*m, 26801.03*m,
     24720.42*m, 22763.36*m, 20924.88*m,
     19200.07*m, 17584.16*m, 16072.45*m,
     14660.38*m, 13343.46*m, 12117.33*m,
     10977.70*m, 9920.416*m, 8941.407*m,
     8036.711*m, 7202.470*m, 6434.927*m,
     5730.429*m, 5085.425*m, 4496.467*m,
     3960.210*m, 3473.413*m, 3032.937*m,
     2635.746*m, 2278.907*m, 1959.588*m,
     1675.064*m, 1422.710*m, 1200.004*m,
     1004.528*m, 833.9666*m, 686.1063*m
  };

  assert(sizeof(mie_water) == sizeof(energy_water));

  // gforward, gbackward, forward backward ratio
  G4double mie_water_const[3]={0.99,0.99,0.8};

  myMPT1->AddProperty("MIEHG",energy_water,mie_water,numentries_water)
        ->SetSpline(true);
  myMPT1->AddConstProperty("MIEHG_FORWARD",mie_water_const[0]);
  myMPT1->AddConstProperty("MIEHG_BACKWARD",mie_water_const[1]);
  myMPT1->AddConstProperty("MIEHG_FORWARD_RATIO",mie_water_const[2]);

  G4cout << "Water G4MaterialPropertiesTable" << G4endl;
  myMPT1->DumpTable();

  water->SetMaterialPropertiesTable(myMPT1);
  psm->SetMaterialPropertiesTable(myMPT1);
 

  // Set the Birks Constant for the Water scintillator

  water->GetIonisation()->SetBirksConstant(0.126*mm/MeV);

//
// PMMA
//


G4double refractiveIndex3[] =
            { 1.60, 1.60, 1.60, 1.60, 1.60, 1.60, 1.60,
              1.60, 1.60, 1.60, 1.60, 1.60, 1.60, 1.60,
              1.60, 1.60, 1.60, 1.60, 1.60, 1.60, 1.60,
              1.60, 1.60, 1.60, 1.60, 1.60, 1.60, 1.60,
              1.60, 1.60, 1.60, 1.60 };

  G4double absorption3[] =
           {3.448*m,  4.082*m,  6.329*m,  9.174*m, 12.346*m, 13.889*m,
           15.152*m, 17.241*m, 18.868*m, 20.000*m, 26.316*m, 35.714*m,
           45.455*m, 47.619*m, 52.632*m, 52.632*m, 55.556*m, 52.632*m,
           52.632*m, 47.619*m, 45.455*m, 41.667*m, 37.037*m, 33.333*m,
           30.000*m, 28.500*m, 27.000*m, 24.500*m, 22.000*m, 19.500*m,
           17.500*m, 14.500*m };

  assert(sizeof(absorption) == sizeof(photonEnergy));

  G4double scintilFast3[] =
            { 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00 };

  assert(sizeof(scintilFast) == sizeof(photonEnergy));

  G4double scintilSlow3[] =
            { 0.01, 1.00, 2.00, 3.00, 4.00, 5.00, 6.00,
              7.00, 8.00, 9.00, 8.00, 7.00, 6.00, 4.00,
              3.00, 2.00, 1.00, 0.01, 1.00, 2.00, 3.00,
              4.00, 5.00, 6.00, 7.00, 8.00, 9.00, 8.00,
              7.00, 6.00, 5.00, 4.00 };

  assert(sizeof(refractiveIndex3) == sizeof(photonEnergy));

 
  G4MaterialPropertiesTable* myMPT3 = new G4MaterialPropertiesTable();

  myMPT3->AddProperty("RINDEX",       photonEnergy, refractiveIndex3,nEntries)
        ->SetSpline(true);
  myMPT3->AddProperty("ABSLENGTH",    photonEnergy, absorption3,     nEntries)
        ->SetSpline(true);
  myMPT3->AddProperty("FASTCOMPONENT",photonEnergy, scintilFast3,     nEntries)
        ->SetSpline(true);
  myMPT3->AddProperty("SLOWCOMPONENT",photonEnergy, scintilSlow3,     nEntries)
        ->SetSpline(true);

  myMPT3->AddConstProperty("SCINTILLATIONYIELD",50./MeV);
  myMPT3->AddConstProperty("RESOLUTIONSCALE",1.0);
  myMPT3->AddConstProperty("FASTTIMECONSTANT", 1.*ns);
  myMPT3->AddConstProperty("SLOWTIMECONSTANT",10.*ns);
  myMPT3->AddConstProperty("YIELDRATIO",0.8);

  
  myMPT3->AddProperty("MIEHG",energy_water,mie_water,numentries_water)
        ->SetSpline(true);
  myMPT3->AddConstProperty("MIEHG_FORWARD",mie_water_const[0]);
  myMPT3->AddConstProperty("MIEHG_BACKWARD",mie_water_const[1]);
  myMPT3->AddConstProperty("MIEHG_FORWARD_RATIO",mie_water_const[2]);


  G4cout << "PMMA G4MaterialPropertiesTable" << G4endl;
  myMPT3->DumpTable();

  pmma->SetMaterialPropertiesTable(myMPT3);



//
// Air
//
  G4double refractiveIndex2[] =
            { 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00 };


  assert(sizeof(absorption) == sizeof(photonEnergy));

  G4MaterialPropertiesTable* myMPT2 = new G4MaterialPropertiesTable();
  myMPT2->AddProperty("RINDEX", photonEnergy, refractiveIndex2, nEntries);

  G4cout << "Air G4MaterialPropertiesTable" << G4endl;
  myMPT2->DumpTable();

  air->SetMaterialPropertiesTable(myMPT2);

//
// ------------- Volumes --------------



    G4RotationMatrix* myRotation = new G4RotationMatrix();
    myRotation->rotateX(0.*deg);
    myRotation->rotateY(0.*deg);
    myRotation->rotateZ(90.*deg);

// The experimental Hall
//
  G4Box* expHall_box = new G4Box("World",fExpHall_x,fExpHall_y,fExpHall_z);

  G4LogicalVolume* expHall_log
    = new G4LogicalVolume(expHall_box,air,"World",0,0,0);

  G4VPhysicalVolume* expHall_phys
    = new G4PVPlacement(0,G4ThreeVector(),expHall_log,"World",0,false,0);

//Scint1


  G4Box* scint = new G4Box("scint",150/2*mm,5/2*mm,75/2*mm);
  G4LogicalVolume* scint_log = new G4LogicalVolume(scint,water,"scint",0,0,0);

  G4VPhysicalVolume* scint_phys;

  scint_phys = new G4PVPlacement(0,G4ThreeVector(0.,0.,0. ),scint_log,
                      "scint",expHall_log,
                      false,0,checkOverlaps );
     
//MPPC

  G4Box* up = new G4Box("up",20/2*mm,8/2*mm,75/2*mm);
  G4LogicalVolume* up_log = new G4LogicalVolume(up,water,"up",0,0,0);

  G4VPhysicalVolume* up_phys;

  up_phys = new G4PVPlacement(0,G4ThreeVector((75+10)*mm,0,0.),up_log,
                      "up",expHall_log,
                      false,0,checkOverlaps );


//checkOverlaps   





//
/*
  G4Box* scint1 = new G4Box("scint1",tw*mm,th*mm,tl*mm);
  G4LogicalVolume* scint1_log = new G4LogicalVolume(scint1,water,"scint1",0,0,0);
  G4VPhysicalVolume* scint1_phys = new G4PVPlacement(0,G4ThreeVector(0,0,0*mm),scint1_log,"scint1",expHall_log,false,0);

  G4Box* scint2 = new G4Box("scint2",tw*mm,th*mm,tl*mm);
  G4LogicalVolume* scint2_log = new G4LogicalVolume(scint2,water,"scint2",0,0,0);
  G4VPhysicalVolume* scint2_phys = new G4PVPlacement(myRotation,G4ThreeVector(11*mm,0,0*mm),scint2_log,"scint2",expHall_log,false,0);
*/
//  G4Box* scint3 = new G4Box("scint3",5*mm,5*mm,500*mm);
//  G4LogicalVolume* scint3_log = new G4LogicalVolume(scint3,water,"scint3",0,0,0);
//  G4VPhysicalVolume* scint3_phys = new G4PVPlacement(0,G4ThreeVector(22*mm,0,0*mm),scint3_log,"scint3",expHall_log,false,0);

//  G4Box* scint4 = new G4Box("scint4",5*mm,5*mm,500*mm);
//  G4LogicalVolume* scint4_log = new G4LogicalVolume(scint4,water,"scint4",0,0,0);
//  G4VPhysicalVolume* scint4_phys = new G4PVPlacement(0,G4ThreeVector(33*mm,0,0*mm),scint4_log,"scint4",expHall_log,false,0);

//  G4Box* scint5 = new G4Box("scint5",5*mm,5*mm,500*mm);
//  G4LogicalVolume* scint5_log = new G4LogicalVolume(scint5,water,"scint5",0,0,0);
//  G4VPhysicalVolume* scint5_phys = new G4PVPlacement(0,G4ThreeVector(44*mm,0,0*mm),scint5_log,"scint5",expHall_log,false,0);


// Kollektor
/*
  G4Box* f1 = new G4Box("f1",tw*mm,th*mm,tw*mm);
  G4LogicalVolume* f1_log = new G4LogicalVolume(f1,water,"f1",0,0,0);
  G4VPhysicalVolume* f1_phys = new G4PVPlacement(0,G4ThreeVector(0,0,505*mm),f1_log,"f1",expHall_log,false,0);

  G4Box* a1 = new G4Box("a1",tw*mm,th*mm,tw*mm);
  G4LogicalVolume* a1_log = new G4LogicalVolume(a1,water,"a1",0,0,0);
  G4VPhysicalVolume* a1_phys = new G4PVPlacement(0,G4ThreeVector(0,0,-505*mm),a1_log,"a1",expHall_log,false,0);

  G4Box* f2 = new G4Box("f2",5*mm,5*mm,5*mm);
  G4LogicalVolume* f2_log = new G4LogicalVolume(f2,water,"f2",0,0,0);
  G4VPhysicalVolume* f2_phys = new G4PVPlacement(0,G4ThreeVector(0,0,495*mm),f2_log,"f2",scint2_log,false,0);

  G4Box* a2 = new G4Box("a2",5*mm,5*mm,5*mm);
  G4LogicalVolume* a2_log = new G4LogicalVolume(a2,water,"a2",0,0,0);
  G4VPhysicalVolume* a2_phys = new G4PVPlacement(0,G4ThreeVector(0,0,-495*mm),a2_log,"a2",scint2_log,false,0);
*/






// ------------- Surfaces --------------
//
// Water -> Polystyrene Tank
//
  

// scint surface
//
  G4OpticalSurface* opWaterSurfaceS = new G4OpticalSurface("WaterSurfaceS");
  opWaterSurfaceS->SetType(dielectric_dielectric);
  opWaterSurfaceS->SetFinish(polishedbackpainted);
  opWaterSurfaceS->SetModel(unified);

   
   new G4LogicalBorderSurface("WaterSurfaceS",
                                 scint_phys,expHall_phys,opWaterSurfaceS);
   

//   for (int i=0;i<10;i++) {
//     new G4LogicalBorderSurface("WaterSurfaceS",
//                                 up_phys[i],expHall_phys,opWaterSurfaceS);
//   }

//   for (int i=0;i<10;i++) {
//     new G4LogicalBorderSurface("WaterSurfaceS",
//                                 down_phys[i],expHall_phys,opWaterSurfaceS);
//   }

 // new G4LogicalBorderSurface("WaterSurfaceS",
//                                 f1_phys,expHall_phys,opWaterSurfaceS);
 
 // new G4LogicalBorderSurface("WaterSurfaceS",
  //                               a1_phys,expHall_phys,opWaterSurfaceS);





// Air Bubble
//
//    G4OpticalSurface* opAirSurface = new G4OpticalSurface("AirSurface");
//    opAirSurface->SetType(dielectric_dielectric);
//    opAirSurface->SetFinish(polished);
//    opAirSurface->SetModel(glisur);





//
// Generate & Add Material Properties Table attached to the optical surfaces
//
  const G4int num = 2;
  G4double ephoton[num] = {2.034*eV, 4.136*eV};

  //OpticalWaterSurfaceS
  G4double refractiveIndex[num] = {1.35, 1.40};
  G4double specularLobe[num]    = {0.3, 0.3};
  G4double specularSpike[num]   = {0.2, 0.2};
  G4double backScatter[num]     = {0.2, 0.2};

  G4MaterialPropertiesTable* myST1 = new G4MaterialPropertiesTable();

  myST1->AddProperty("RINDEX",                ephoton, refractiveIndex, num);
  myST1->AddProperty("SPECULARLOBECONSTANT",  ephoton, specularLobe,    num);
  myST1->AddProperty("SPECULARSPIKECONSTANT", ephoton, specularSpike,   num);
  myST1->AddProperty("BACKSCATTERCONSTANT",   ephoton, backScatter,     num);

  G4cout << "Water Surface G4MaterialPropertiesTable" << G4endl;
  myST1->DumpTable();

  opWaterSurfaceS->SetMaterialPropertiesTable(myST1);

//OpticalAirSurface
//  G4double reflectivity[num] = {0.3, 0.5};
//    G4double efficiency[num]   = {0.8, 1.0};

//    G4MaterialPropertiesTable *myST2 = new G4MaterialPropertiesTable();

//    myST2->AddProperty("REFLECTIVITY", ephoton, reflectivity, num);
//    myST2->AddProperty("EFFICIENCY",   ephoton, efficiency,   num);

//    G4cout << "Air Surface G4MaterialPropertiesTable" << G4endl;
//    myST2->DumpTable();

//    opAirSurface->SetMaterialPropertiesTable(myST2);

// always return the physical World
  return expHall_phys;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
