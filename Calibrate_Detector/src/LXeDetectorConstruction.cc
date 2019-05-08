
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
// $Id: LXeDetectorConstruction.cc 77882 2013-11-29 08:39:07Z gcosmo $
//
/// \file optical/LXe/src/LXeDetectorConstruction.cc
/// \brief Implementation of the LXeDetectorConstruction class
//
//
#include "LXeDetectorConstruction.hh"
#include "LXePMTSD.hh"
#include "LXeScintSD.hh"
#include "LXeScintillatorSD.hh"
#include "LXeDetectorMessenger.hh"
#include "LXeMainVolume.hh"
#include "LXeWLSSlab.hh"

#include "G4SDManager.hh"
#include "G4RunManager.hh"

#include "G4GeometryManager.hh"
#include "G4SolidStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"

#include "G4SubtractionSolid.hh"
#include "G4OpticalSurface.hh"
#include "G4MaterialTable.hh"
#include "G4VisAttributes.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "globals.hh"
#include "G4UImanager.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "CADMesh.hh"
#include <string>



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeDetectorConstruction::LXeDetectorConstruction()
: fLXe_mt(NULL), fMPTPStyrene(NULL)
{
  fExperimentalHall_box = NULL;
  fExperimentalHall_log = NULL;
  fExperimentalHall_phys = NULL;
  Pb1_box = NULL;
  Pb1_log = NULL;
  Pb1_phys = NULL;
  Pb2_box = NULL;
  Pb2_log = NULL;
  Pb2_phys = NULL;
  Al_box = NULL;
  Al_log = NULL;
  Al_phys = NULL;

  fLXe = fAl = Mat_Pb = fAir = fVacuum = fGlass = NULL;
  fPstyrene = fPMMA = fPethylene1 = fPethylene2 = NULL;
  CarbonFiber = Aluminum6061_T6 = Aluminum7075_T73 = StainlessSteelA2_70AISI304 = CopperElectricEN2_0060 = GlassBorosilicateN_BK7 = FR4Glass_Epoxysheet = BrassGeneric = SolarPanel = NULL;
  ADCS_mat = ANT_mat = COM_mat = EPS_mat = OBC_mat = STRU_mat = SP_mat = Payload_mat = NULL;

  fN = Al_El = fPb = fO = fC = fH = fMg = fCu = fZn = fCr = fSi = fGe = fFe = NULL;

  SetDefaults();

  fDetectorMessenger = new LXeDetectorMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeDetectorConstruction::~LXeDetectorConstruction() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::DefineMaterials(){
  G4double a;  // atomic mass
  G4double z;  // atomic number
  G4double density;
  G4double fractionmass;

  G4int polyPMMA = 1;
  G4int nC_PMMA = 3+2*polyPMMA;
  G4int nH_PMMA = 6+2*polyPMMA;

  G4int polyeth = 1;
  G4int nC_eth = 2*polyeth;
  G4int nH_eth = 4*polyeth;

  //***Elements
  fH = new G4Element("H", "H", z=1., a=1.01*g/mole);
  fC = new G4Element("C", "C", z=6., a=12.01*g/mole);
  fN = new G4Element("N", "N", z=7., a= 14.01*g/mole);
  fO = new G4Element("O"  , "O", z=8., a= 16.00*g/mole);

  //***Materials
  //Liquid Xenon

  G4int nelements;
  G4double density_CsI;
  
  	a = 126.90447*g/mole;
	G4Element* elI  = new G4Element("Iodine","I" , z= 53., a);

	a = 132.90543*g/mole;
	G4Element* elCs  = new G4Element("Oxygen"  ,"O" , z= 55., a);
    fLXe = new G4Material("LXe", density = 4.51*g/cm3, 2);
        
    fLXe->AddElement(elCs, 50.0*perCent);
    fLXe->AddElement(elI, 50.0*perCent);
  
  fAl = new G4Material("Al",z=13.,a=26.98*g/mole,density=2.7*g/cm3);
  Mat_Pb = new G4Material("Pb",z=82.,a=207.2*g/mole,density=11.35*g/cm3);
 
  //Vacuum
  fVacuum = new G4Material("Vacuum",z=1.,a=1.01*g/mole,
                          density=universe_mean_density,kStateGas,0.1*kelvin,
                          1.e-19*pascal);
  // Mg 
//  fMg = new G4Element("Mg",z=25.,a=54.9*g/mole,density=7.21*g/cm3); 
  fMg = new G4Element("Mg","Mg",z=25.,a=54.9*g/mole); 
 //Pb
 // fPb = new G4Element("Pb",z=82.,a=207.2*g/mole,density=11.35*g/cm3);
  fPb = new G4Element("Pb","Pb",z=82.,a=207.2*g/mole);
 //Aluminum
 // fAl = new G4Element("Al",z=13.,a=26.98*g/mole,density=2.7*g/cm3);
  Al_El = new G4Element("Al_el","Al_el",z=13.,a=26.98*g/mole);
  // Cu 
 // fCu = new G4Element("Mg",z=29.,a=63.54*g/mole,density=8.96*g/cm3);
  fCu = new G4Element("Mg","Mg",z=29.,a=63.54*g/mole);
  // Zn 
 // fZn = new G4Element("Zn",z=30.,a=65.38*g/mole,density=7.14*g/cm3);                                 
  fZn = new G4Element("Zn","Zn",z=30.,a=65.38*g/mole);                                 
  // Cr                        
 // fCr = new G4Element("Cr",z=24.,a=51.9*g/mole,density=7.19*g/cm3);  
  fCr = new G4Element("Cr","Cr",z=24.,a=51.9*g/mole);  
  // Si
 // fSi = new G4Element("Si",z=14.,a=28.085*g/mole,density=2.32*g/cm3);                        
  fSi = new G4Element("Si","Si",z=14.,a=28.085*g/mole);                        
  // Ge                        
 // fGe = new G4Element("Ge",z=32.,a=72.63*g/mole,density=5.323*g/cm3);
  fGe = new G4Element("Ge","Ge",z=32.,a=72.63*g/mole);
  // Fe                        
 // fFe = new G4Element("Fe",z=26.,a=55.8*g/mole,density=7.84*g/cm3);
  fFe = new G4Element("Fe","Fe",z=26.,a=55.8*g/mole);
                         
  //Air
  fAir = new G4Material("Air", density= 1.29*mg/cm3, 2);
  fAir->AddElement(fN, 70*perCent);
  fAir->AddElement(fO, 30*perCent);
  //Glass
  fGlass = new G4Material("Glass", density=1.032*g/cm3,2);
  fGlass->AddElement(fC,91.533*perCent);
  fGlass->AddElement(fH,8.467*perCent);
  //Polystyrene
  fPstyrene = new G4Material("Polystyrene", density= 1.03*g/cm3, 2);
  fPstyrene->AddElement(fC, 8);
  fPstyrene->AddElement(fH, 8);
  //Fiber(PMMA)
  fPMMA = new G4Material("PMMA", density=1190*kg/m3,3);
  fPMMA->AddElement(fH,nH_PMMA);
  fPMMA->AddElement(fC,nC_PMMA);
  fPMMA->AddElement(fO,2);
  //Cladding(polyethylene)
  fPethylene1 = new G4Material("Pethylene1", density=1200*kg/m3,2);
  fPethylene1->AddElement(fH,nH_eth);
  fPethylene1->AddElement(fC,nC_eth);
  //Double cladding(flourinated polyethylene)
  fPethylene2 = new G4Material("Pethylene2", density=1400*kg/m3,2);
  fPethylene2->AddElement(fH,nH_eth);
  fPethylene2->AddElement(fC,nC_eth);
 
  // Materials for the satellite

  
  
  //***Material properties tables

const G4int lxenum = 8;
  G4double lxe_Energy[lxenum]    = { 3.5428571428571427*eV, 3.1*eV, 2.7555555555555555*eV, 2.48*eV, 2.361904761904762*eV, 2.2545454545454544*eV, 2.066666666666667*eV, 1.9076923076923078*eV};

  G4double lxe_SCINT[lxenum] = { 0.02, 0.1, 0.3, 0.6, 0.9, 1.0, 0.7, 0.4 };
  G4double lxe_RIND[lxenum]  = { 1.59 , 1.57, 1.54, 1.54, 1.54, 1.54, 1.54, 1.54 };
 // G4double lxe_RIND[lxenum]  = { 2.1 , 2.04 , 1.96 ,1.9 ,1.83 ,1.79 ,1.7 ,1.68};
  G4double lxe_ABSL[lxenum]  = { 40.*cm, 40.*cm, 40.*cm, 40.*cm, 40.*cm, 40.*cm, 40.*cm, 40.*cm};
  fLXe_mt = new G4MaterialPropertiesTable();
  fLXe_mt->AddProperty("FASTCOMPONENT", lxe_Energy, lxe_SCINT, lxenum);
  fLXe_mt->AddProperty("SLOWCOMPONENT", lxe_Energy, lxe_SCINT, lxenum);
  fLXe_mt->AddProperty("RINDEX",        lxe_Energy, lxe_RIND,  lxenum);
  fLXe_mt->AddProperty("ABSLENGTH",     lxe_Energy, lxe_ABSL,  lxenum);
  fLXe_mt->AddConstProperty("SCINTILLATIONYIELD",54./keV);
  fLXe_mt->AddConstProperty("RESOLUTIONSCALE",1.0);
  fLXe_mt->AddConstProperty("FASTTIMECONSTANT",20.*ns);
  fLXe_mt->AddConstProperty("SLOWTIMECONSTANT",45.*ns);
  fLXe_mt->AddConstProperty("YIELDRATIO",1.0);
  fLXe->SetMaterialPropertiesTable(fLXe_mt);

  // Set the Birks Constant for the LXe scintillator

  fLXe->GetIonisation()->SetBirksConstant(0.126*mm/MeV);
 
  G4int glassNo = 3;
  G4double glass_RIND[glassNo]={1.49,1.49,1.49};
  G4double glass_AbsLength[3]={420.*cm,420.*cm,420.*cm};
  G4MaterialPropertiesTable *glass_mt = new G4MaterialPropertiesTable();
  glass_mt->AddProperty("ABSLENGTH",lxe_Energy,glass_AbsLength,glassNo);
  glass_mt->AddProperty("RINDEX",lxe_Energy,glass_RIND,glassNo);
  fGlass->SetMaterialPropertiesTable(glass_mt);

  G4int Vacuu_NO = 3;
  G4double vacuum_Energy[Vacuu_NO]={2.0*eV,7.0*eV,7.14*eV};
  G4double vacuum_RIND[Vacuu_NO]={1.,1.,1.};
  G4MaterialPropertiesTable *vacuum_mt = new G4MaterialPropertiesTable();
  vacuum_mt->AddProperty("RINDEX", vacuum_Energy, vacuum_RIND,Vacuu_NO);
  fVacuum->SetMaterialPropertiesTable(vacuum_mt);
  fAir->SetMaterialPropertiesTable(vacuum_mt);//Give air the same rindex

  const G4int wlsnum = 4;
  G4double wls_Energy[] = {2.00*eV,2.87*eV,2.90*eV,3.47*eV};
 
  G4double rIndexPstyrene[wlsnum]={ 1.5, 1.5, 1.5, 1.5};
  G4double absorption1[wlsnum]={2.*cm, 2.*cm, 2.*cm, 2.*cm};
  G4double scintilFast[wlsnum]={0.00, 0.00, 1.00, 1.00};
  fMPTPStyrene = new G4MaterialPropertiesTable();
  fMPTPStyrene->AddProperty("RINDEX",wls_Energy,rIndexPstyrene,wlsnum);
  fMPTPStyrene->AddProperty("ABSLENGTH",wls_Energy,absorption1,wlsnum);
  fMPTPStyrene->AddProperty("FASTCOMPONENT",wls_Energy, scintilFast,wlsnum);
  fMPTPStyrene->AddConstProperty("SCINTILLATIONYIELD",10./keV);
  fMPTPStyrene->AddConstProperty("RESOLUTIONSCALE",1.0);
  fMPTPStyrene->AddConstProperty("FASTTIMECONSTANT", 10.*ns);
  fPstyrene->SetMaterialPropertiesTable(fMPTPStyrene);

  // Set the Birks Constant for the Polystyrene scintillator

  fPstyrene->GetIonisation()->SetBirksConstant(0.126*mm/MeV);

  G4double RefractiveIndexFiber[wlsnum]={ 1.60, 1.60, 1.60, 1.60};
  G4double AbsFiber[wlsnum]={9.00*m,9.00*m,0.1*mm,0.1*mm};
  G4double EmissionFib[wlsnum]={1.0, 1.0, 0.0, 0.0};
  G4MaterialPropertiesTable* fiberProperty = new G4MaterialPropertiesTable();
  fiberProperty->AddProperty("RINDEX",wls_Energy,RefractiveIndexFiber,wlsnum);
  fiberProperty->AddProperty("WLSABSLENGTH",wls_Energy,AbsFiber,wlsnum);
  fiberProperty->AddProperty("WLSCOMPONENT",wls_Energy,EmissionFib,wlsnum);
  fiberProperty->AddConstProperty("WLSTIMECONSTANT", 0.5*ns);
  fPMMA->SetMaterialPropertiesTable(fiberProperty);

  G4double RefractiveIndexClad1[wlsnum]={ 1.49, 1.49, 1.49, 1.49};
  G4MaterialPropertiesTable* clad1Property = new G4MaterialPropertiesTable();
  clad1Property->AddProperty("RINDEX",wls_Energy,RefractiveIndexClad1,wlsnum);
  clad1Property->AddProperty("ABSLENGTH",wls_Energy,AbsFiber,wlsnum);
  fPethylene1->SetMaterialPropertiesTable(clad1Property);

  G4double RefractiveIndexClad2[wlsnum]={ 1.42, 1.42, 1.42, 1.42};
  G4MaterialPropertiesTable* clad2Property = new G4MaterialPropertiesTable();
  clad2Property->AddProperty("RINDEX",wls_Energy,RefractiveIndexClad2,wlsnum);
  clad2Property->AddProperty("ABSLENGTH",wls_Energy,AbsFiber,wlsnum);
  fPethylene2->SetMaterialPropertiesTable(clad2Property);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* LXeDetectorConstruction::Construct(){

  if (fExperimentalHall_phys) {
     G4GeometryManager::GetInstance()->OpenGeometry();
     G4PhysicalVolumeStore::GetInstance()->Clean();
     G4LogicalVolumeStore::GetInstance()->Clean();
     G4SolidStore::GetInstance()->Clean();
     G4LogicalSkinSurface::CleanSurfaceTable();
     G4LogicalBorderSurface::CleanSurfaceTable();
  }

  DefineMaterials();
  return ConstructDetector();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* LXeDetectorConstruction::ConstructDetector()
{
	
// CAD MESH


/*	G4double density = 0.200*g/cm3;
    G4String name;
    G4int ncomponents = 0;


	G4Material* ADCS_mat = new G4Material(name="Aerogel", density, ncomponents=3);
	G4Material* ANT_mat = new G4Material(name="ANT_mat", density, ncomponents=2);
	G4Material* AUX_mat = new G4Material(name="UX_mat", density, ncomponents=1);
	G4Material* COM_mat = new G4Material(name="Aerogel", density, ncomponents=4);
	G4Material* EPS_mat = new G4Material(name="EPS_mat", density, ncomponents=2);
	G4Material* OBC_mat = new G4Material(name="OBC_mat", density, ncomponents=1);
	G4Material* STRU_mat = new G4Material(name="STRU_mat", density, ncomponents=1);
	G4Material* SP_mat = new G4Material(name="SP_mat", density, ncomponents=1);
	G4Material* Payload_mat = new G4Material(name="Payload_mat", density, ncomponents=1); */

	
// CAD MESH END	
	
	
	
	
	
	
	
	
	
	
  //The experimental hall walls are all 1m away from housing walls
  G4double expHall_x = fScint_x+fD_mtl+1*m;
  G4double expHall_y = fScint_y+fD_mtl+1*m;
  G4double expHall_z = fScint_z+fD_mtl+1*m;

  //Create experimental hall
  fExperimentalHall_box
    = new G4Box("expHall_box",expHall_x,expHall_y,expHall_z);
  fExperimentalHall_log = new G4LogicalVolume(fExperimentalHall_box,
                                             fVacuum,"expHall_log",0,0,0);
  fExperimentalHall_phys = new G4PVPlacement(0,G4ThreeVector(),
                              fExperimentalHall_log,"expHall",0,false,0);


  fExperimentalHall_log->SetVisAttributes(G4VisAttributes::Invisible);
//Hole in Pb sheets
  G4double Pb_y = 1.*mm;
  Cylinder1 = NULL;
  Pb1_box_With_Hole = NULL;
  Cylinder1 = new G4Tubs ("Cylinder #1",0,0.5*mm,Pb_y/2,0,twopi);  // r:     0 mm -> 50 mm
                                                          // z:   -50 mm -> 50 mm
                                                          // phi:   0 ->  2 pi
  //Create and place the Al and Pb sheets

  G4double Al_y = 2.*mm;
  G4double Offset_Pb1 = fScint_y/2+fD_mtl+1*mm+Pb_y+9.5*mm+Al_y+Pb_y/2;
  G4double Offset_Pb2 = fScint_y/2+fD_mtl+1*mm+Pb_y/2;
  G4double Offset_Al = fScint_y/2+fD_mtl+1*mm+Pb_y+9.5*mm+Al_y/2;


	//printf("%lf",fScint_y/2+fD_mtl+1*mm+Pb_y+9.5*mm+Al_y/2);
	//exit(-1);

  Pb1_box = new G4Box("Pb1_box",fScint_x/2, fScint_z/2, Pb_y/2);
 // printf("%lf, %lf\n",fScint_x,fScint_z);  
  Pb1_box_With_Hole = new G4SubtractionSolid("Box-Cylinder", Pb1_box, Cylinder1, 0, G4ThreeVector(0,0,0));
  //
 
	G4double OffsetX = 0*mm;
	G4double OffsetY = 0*mm;
  for(int h = 0; h < 3; h++)
	{
	for(int j = 0; j < 3; j++)
		{
		OffsetY = h*27.5*mm - 27.5*mm;
		OffsetX = j*65*mm - 65*mm;
		//printf("%d, %d\n",j,h);
//		if(h != 0 || j != 0) 
//			{
			Pb1_box_With_Hole = new G4SubtractionSolid("Box-Cylinder", Pb1_box_With_Hole, Cylinder1, 0, G4ThreeVector(OffsetX,OffsetY,0));
//			}
		}
	}
 
  G4RotationMatrix* rm_x = new G4RotationMatrix();
  rm_x->rotateX(-90*deg); 
  
  Pb1_log = new G4LogicalVolume(Pb1_box_With_Hole, Mat_Pb, "Pb1_log",0,0,0);
  Pb1_phys = new G4PVPlacement(rm_x,G4ThreeVector(0,Offset_Pb1,0),
                              Pb1_log,"Pb1",fExperimentalHall_log,false,0);

  Pb2_box = new G4Box("Pb2_box",fScint_x/2, Pb_y/2, fScint_z/2);
//  G4SubtractionSolid Pb2_box_With_Hole("Box-Cylinder", &Pb2_box, &Cylinder1);
 
  Pb2_log = new G4LogicalVolume(Pb1_box_With_Hole, Mat_Pb, "Pb1_log",0,0,0);
  Pb2_phys = new G4PVPlacement(rm_x,G4ThreeVector(0,Offset_Pb2,0),
                              Pb2_log,"Pb2",fExperimentalHall_log,false,0);
                                                            
  Al_box = new G4Box("Al_box",fScint_x/2, Al_y/2, fScint_z/2);
  Al_log = new G4LogicalVolume(Al_box, fAl, "Al_log",0,0,0);
  Al_phys = new G4PVPlacement(0,G4ThreeVector(0,Offset_Al,0),
                              Al_log,"Al1",fExperimentalHall_log,false,0);


 
 
  if(fMainVolumeOn){
    fMainVolume
      = new LXeMainVolume(0,G4ThreeVector(),fExperimentalHall_log,false,0,this);
  }
  
  
 // Surface properties for the scint vs ESR
    G4OpticalSurface* scintESR = new G4OpticalSurface("Housing");
 
    new G4LogicalBorderSurface("HousingSurface", fMainVolume->GetPhysScint(),
                               fMainVolume,
                               scintESR);
 
    scintESR->SetType(dielectric_metal);
    scintESR->SetFinish(polished);
    scintESR->SetModel(glisur);

    const G4int num = 2;

    G4double pp[num] = {2.0*eV, 7.5*eV};
    G4double reflectivity[num] = {0.99, 0.99};
    G4double efficiency[num] = {0.0, 0.0};
    
    G4MaterialPropertiesTable* scintESRProperty 
      = new G4MaterialPropertiesTable();

    scintESRProperty->AddProperty("REFLECTIVITY",pp,reflectivity,num);
    scintESRProperty->AddProperty("EFFICIENCY",pp,efficiency,num);
    scintESR->SetMaterialPropertiesTable(scintESRProperty);

//--------- example of User Limits -------------------------------

  // below is an example of how to set tracking constraints in a given
  // logical volume(see also in N02PhysicsList how to setup the processes
  // G4StepLimiter or G4UserSpecialCuts).
    
  // Sets a max Step length in the tracker region, with G4StepLimiter
  //
  
  //G4double maxStep = 0.5*fChamberWidth; 
  //fLogicTracker->SetUserLimits(new G4UserLimits(maxStep));
  
  // Set additional contraints on the track, with G4UserSpecialCuts
  //
  // G4double maxLength = 2*fTrackerLength, maxTime = 0.1*ns, minEkin = 10*MeV;
  // logicTracker->SetUserLimits(new G4UserLimits(maxStep,maxLength,maxTime,
  //                                               minEkin));

 
  return fExperimentalHall_phys;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::ConstructSDandField() {

  if (!fMainVolume) return;

  // PMT SD

  if (!fPmt_SD.Get()) {
    //Created here so it exists as pmts are being placed
    G4cout << "Construction /LXeDet/pmtSD" << G4endl;
    LXePMTSD* pmt_SD = new LXePMTSD("/LXeDet/pmtSD");
    fPmt_SD.Put(pmt_SD);

    pmt_SD->InitPMTs((fNx*fNy+fNx*fNz+fNy*fNz)*2); //let pmtSD know # of pmts
    pmt_SD->SetPmtPositions(fMainVolume->GetPmtPositions());
  }

  //sensitive detector is not actually on the photocathode.
  //processHits gets done manually by the stepping action.
  //It is used to detect when photons hit and get absorbed&detected at the
  //boundary to the photocathode (which doesnt get done by attaching it to a
  //logical volume.
  //It does however need to be attached to something or else it doesnt get
  //reset at the begining of events

  SetSensitiveDetector(fMainVolume->GetLogPMT(), fPmt_SD.Get());

  // Scint SD

  if (!fScint_SD.Get()) {
    G4cout << "Construction /LXeDet/scintSD" << G4endl;
    LXeScintSD* scint_SD = new LXeScintSD("/LXeDet/scintSD");
    fScint_SD.Put(scint_SD);
  }
  SetSensitiveDetector(fMainVolume->GetLogScint(), fScint_SD.Get());
  
    // Actually WORKING Sensitive detectors

  static G4ThreadLocal G4bool initialized = false;
    if ( ! initialized ) {
		
		
		G4String trackerChamberSDname = "LXe/LXeScintillatorSD";
		LXeScintillatorSD* aTrackerSD = new LXeScintillatorSD(trackerChamberSDname,
                                            "ScintillatorHitsCollection");
		G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD);
  // Setting aTrackerSD to all logical volumes with the same name 
  // of "Chamber_LV".
	//	SetSensitiveDetector("cad_logical", aTrackerSD, true);
		initialized = true;
		/*
        // Prepare sensitive detectors
        CheckVolumeSD* fCheckSD = new CheckVolumeSD("checkSD");
        (G4SDManager::GetSDMpointer())->AddNewDetector( fCheckSD );
        fLogicCheck->SetSensitiveDetector(fCheckSD);

        TargetSD* fTargetSD = new TargetSD("targetSD");
        (G4SDManager::GetSDMpointer())->AddNewDetector( fTargetSD );
        fLogicTarget->SetSensitiveDetector(fTargetSD);
        initialized=true;
        
        */
        
        
    }


 
   
  
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::SetDimensions(G4ThreeVector dims) {
  this->fScint_x=dims[0];
  this->fScint_y=dims[1];
  this->fScint_z=dims[2];
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}
 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::SetHousingThickness(G4double d_mtl) {
  this->fD_mtl=d_mtl;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::SetNX(G4int nx) {
  this->fNx=nx;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::SetNY(G4int ny) {
  this->fNy=ny;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::SetNZ(G4int nz) {
  this->fNz=nz;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::SetPMTRadius(G4double outerRadius_pmt) {
  this->fOuterRadius_pmt=outerRadius_pmt;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::SetDefaults() {

  //Resets to default values
 // fD_mtl=0.0635*cm;

  
std::string infileline;
std::string Part_Name;
std::ifstream file("housingthickness.txt");

while (std::getline(file, infileline))
    {
	assert(infileline.size() != 0);
	
	
	double d;
	sscanf(infileline.c_str(), "%lf", &d);
	fD_mtl = d*mm;
	//fD_mtl = std::stoi(infileline);
    }
  

  fScint_x = 15.*cm;
  fScint_y = 0.5*cm;
  fScint_z = 7.5*cm;

  fNx = 1;
  fNy = 1;
  fNz = 2;

  fOuterRadius_pmt = 0.1*cm;

  fRefl=1.0;

  fNfibers=15;
  fWLSslab=false;
  fMainVolumeOn=true;
  fMainVolume=NULL;
  fSlab_z=2.5*mm;

  G4UImanager::GetUIpointer()
    ->ApplyCommand("/LXe/detector/scintYieldFactor 1.");

  if(fLXe_mt)fLXe_mt->AddConstProperty("SCINTILLATIONYIELD",0.001/keV);
  if(fMPTPStyrene)fMPTPStyrene->AddConstProperty("SCINTILLATIONYIELD",10./MeV);

  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::SetHousingReflectivity(G4double r) {
  fRefl=r;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::SetWLSSlabOn(G4bool b) {
  fWLSslab=b;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::SetMainVolumeOn(G4bool b) {
  fMainVolumeOn=b;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::SetNFibers(G4int n) {
  fNfibers=n;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeDetectorConstruction::SetMainScintYield(G4double y) {
  fLXe_mt->AddConstProperty("SCINTILLATIONYIELD",y/keV);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void LXeDetectorConstruction::SetWLSScintYield(G4double y) {
  fMPTPStyrene->AddConstProperty("SCINTILLATIONYIELD",y/MeV);
}
