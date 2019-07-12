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
// $Id: LXeEMPhysics.cc 68752 2013-04-05 10:23:47Z gcosmo $
//
/// \file optical/LXe/src/LXeEMPhysics.cc
/// \brief Implementation of the LXeEMPhysics class
//
//
#include "LXeEMPhysics.hh"

#include "globals.hh"
#include "G4ios.hh"
#include <iomanip>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeEMPhysics::LXeEMPhysics(const G4String& name)
               :  G4VPhysicsConstructor(name)
{
  fPhotoEffect = NULL;
  fComptonEffect = NULL;
  fPairProduction = NULL;
  fElectronMultipleScattering = NULL;
  fElectronIonisation = NULL; 
  fElectronBremsStrahlung = NULL;
  fPositronMultipleScattering = NULL;
  fPositronIonisation = NULL; 
  fPositronBremsStrahlung = NULL;
  fAnnihilation = NULL;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeEMPhysics::~LXeEMPhysics() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......#include "G4EmProcessOptions.hh"
#include "G4EmProcessOptions.hh"
#include "G4SystemOfUnits.hh"
#include "G4HadronElasticProcess.hh"

#include "G4HadronElastic.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"

#include "G4Gamma.hh"

#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4Proton.hh"
//#include "G4Neutron.hh"

#include "G4NeutrinoE.hh"
#include "G4AntiNeutrinoE.hh"

#include "G4LossTableManager.hh"
#include "G4UAtomicDeexcitation.hh"

//OTHERS:
#include "G4hIonisation.hh" 
#include "G4hMultipleScattering.hh"
#include "G4hBremsstrahlung.hh"
#include "G4hPairProduction.hh"
#include "G4ionIonisation.hh"
#include "G4IonParametrisedLossModel.hh"

void LXeEMPhysics::ConstructParticle()
{
  // gamma
  G4Gamma::GammaDefinition();
 
 
  G4Proton::ProtonDefinition();
  // electron
  G4Electron::ElectronDefinition();
  G4Positron::PositronDefinition();
  G4NeutrinoE::NeutrinoEDefinition();
  G4AntiNeutrinoE::AntiNeutrinoEDefinition();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "G4ProcessManager.hh"

void LXeEMPhysics::ConstructProcess()
{
  fPhotoEffect = new G4PhotoElectricEffect();
  fComptonEffect = new G4ComptonScattering();
  fPairProduction = new G4GammaConversion();
 
    // Electron physics
  fElectronMultipleScattering = new G4eMultipleScattering();
  fElectronIonisation = new G4eIonisation();
  fElectronBremsStrahlung = new G4eBremsstrahlung();
 
    //Positron physics
  fPositronMultipleScattering = new G4eMultipleScattering();
  fPositronIonisation = new G4eIonisation();
  fPositronBremsStrahlung = new G4eBremsstrahlung();
  fAnnihilation = new G4eplusAnnihilation();

  // Gamma Physics
  G4ProcessManager* pManager = 0;

  pManager = G4Gamma::Gamma()->GetProcessManager();
  pManager->AddDiscreteProcess(fPhotoEffect);
  pManager->AddDiscreteProcess(fComptonEffect);
  pManager->AddDiscreteProcess(fPairProduction);

  // Electron Physics
  pManager = G4Electron::Electron()->GetProcessManager();

  pManager->AddProcess(fElectronMultipleScattering, -1, 1, 1);
  pManager->AddProcess(fElectronIonisation,         -1, 2, 2);
  pManager->AddProcess(fElectronBremsStrahlung,     -1, 3, 3);  

  //Positron Physics
  pManager = G4Positron::Positron()->GetProcessManager();
 
  pManager->AddProcess(fPositronMultipleScattering, -1, 1, 1);
  pManager->AddProcess(fPositronIonisation,         -1, 2, 2);
  pManager->AddProcess(fPositronBremsStrahlung,     -1, 3, 3);  
  pManager->AddProcess(fAnnihilation,                0,-1, 4);  


// elastic scatt

 G4HadronElasticProcess* theElasticProcess = new G4HadronElasticProcess;
 G4HadronElastic* theElasticModel = new G4HadronElastic;
 theElasticProcess->RegisterMe(theElasticModel);
  



// proton physics
pManager = 0;

  G4hIonisation* hIonisation = new G4hIonisation();
  hIonisation->SetStepFunction(0.2, 50*um);
  pManager = G4Proton::Proton()->GetProcessManager();
  pManager->AddProcess(hIonisation,               -1, 2, 2);  
  pManager->AddProcess(new G4hMultipleScattering, -1, 1, 1);
  pManager->AddProcess(new G4hBremsstrahlung,     -1,-3, 3);
  pManager->AddProcess(new G4hPairProduction,     -1,-3, 3);
  pManager->AddDiscreteProcess(theElasticProcess);
// ions physics

  pManager = G4GenericIon::GenericIon()->GetProcessManager();
  pManager->AddProcess(new G4hMultipleScattering, -1, 2, 2);
  pManager->AddProcess(new G4ionIonisation,       -1, 1, 1);
//pManager->AddDiscreteProcess(theElasticProcess);

// Elastic scattering
/*
G4HadronElasticProcess* protelProc
= new G4HadronElasticProcess();
G4LElastic* protelMod = new G4LElastic();
protelProc->RegisterMe(protelMod);
pManager->AddDiscreteProcess(protelProc); */


  
 

/*
G4ProtonInelasticProcess* protinelProc = new G4ProtonInelasticProcess();
G4LEProtonInelastic* proLEMod = new G4LEProtonInelastic();
protLEMod->SetMaxEnergy(20.0*GeV);
protinelProc->RegisterMe(protLEMod);
pManager->AddDiscreteProcess(protinelProc); */

/*
G4HEProtonInelastic* protHEMod = new G4HEProtonInelastic();
protHEMod->SetMinEnergy(20.0*GeV);
protinelProc->RegisterMe(protHEMod);
pManager->AddDiscreteProcess(protinelProc);
*/

 // Em options
  //
  // Main options and setting parameters are shown here.
  // Several of them have default values.
  //
  
  G4EmProcessOptions emOptions;
  
  //physics tables
  //
  emOptions.SetMinEnergy(10*eV);        //default 100 eV   
  emOptions.SetMaxEnergy(10*TeV);        //default 100 TeV 
  emOptions.SetDEDXBinning(500);        //default=12*7
  emOptions.SetLambdaBinning(500);        //default=12*7
   emOptions.SetBuildCSDARange(true);
  emOptions.SetDEDXBinningForCSDARange(10*10);
  //multiple coulomb scattering
  //
  emOptions.SetMscStepLimitation(fUseSafety);  //default
    
  // Deexcitation
  //
  G4VAtomDeexcitation* de = new G4UAtomicDeexcitation();
  de->SetFluo(true);
  de->SetAuger(true);   
  de->SetPIXE(true);  
  G4LossTableManager::Instance()->SetAtomDeexcitation(de);

}
