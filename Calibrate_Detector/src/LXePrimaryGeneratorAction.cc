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
// $Id: LXePrimaryGeneratorAction.cc 68752 2013-04-05 10:23:47Z gcosmo $
//
/// \file optical/LXe/src/LXePrimaryGeneratorAction.cc
/// \brief Implementation of the LXePrimaryGeneratorAction class
//
//
#include "LXePrimaryGeneratorAction.hh"
#include "Randomize.hh"
#include "G4EventManager.hh"
#include "LXeRunAction.hh"


#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "globals.hh"
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
const int Gun_On_Sphere = 1;
const int Parallel_Beam = 0;


void filePutContents2(const std::string& name, const std::string& content, bool append = false) {
    std::ofstream outfile;
    if (append)
		outfile.open(name.c_str(), std::ios_base::app);
    else
        outfile.open(name.c_str());
    outfile << content;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXePrimaryGeneratorAction::LXePrimaryGeneratorAction(LXeRunAction*  RunAction) 
: fRunAction(RunAction)
{

  G4int n_particle = 1;
  fParticleGun = new G4ParticleGun(n_particle);
 
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
 
  G4String particleName;
  fParticleGun->SetParticleDefinition(particleTable->
                                     FindParticle(particleName="gamma"));
  
  fParticleGun->SetParticlePosition(G4ThreeVector(0.0 , 17.135000*mm, 0.0));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,-1.,0.));
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXePrimaryGeneratorAction::~LXePrimaryGeneratorAction(){
    delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){
//cout << "whaat\n" ;
  // cout << anEvent->GetEventID()  << "\n"; verbosehoz
  //exit(-1);
   // G4String Particle_Name = fRunAction->Part_Name;

  
 //opening angle
  //
  G4double alphaMin =  0;
  G4double alphaMax = 55.6463391*deg;
  G4double fCosAlphaMin = std::cos(alphaMin);
  G4double fCosAlphaMax = std::cos(alphaMax);  
  
  
  G4double cosTheta = 2*G4UniformRand() - 1;  //cosTheta uniform in [0, pi]
  G4double sinTheta = std::sqrt(1. - cosTheta*cosTheta);
  G4double phi      = 6.28318530718*G4UniformRand();  //phi uniform in [0, 2*pi]
  G4ThreeVector ur(sinTheta*std::cos(phi),sinTheta*std::sin(phi),cosTheta);
  //1. in world frame
  //cosAlpha uniform in [cos(alphaMin), cos(alphaMax)]
  G4double cosAlpha = fCosAlphaMin - G4UniformRand()*(fCosAlphaMin - fCosAlphaMax); 
  G4double sinAlpha = std::sqrt(1. - cosAlpha*cosAlpha);
  G4double psi      = 6.28318530718*G4UniformRand();  //psi uniform in (0,2*pi)  
  G4ThreeVector dir(sinAlpha*std::cos(psi),-cosAlpha,sinAlpha*std::sin(psi));
  
  //2. rotate dir   (rotateUz transforms uz to ur)
  //dir.rotateUz(ur);           
  
  //Default energy,position,momentum
  //printf("%G4double\n",G4UniformRand());
  double number = G4UniformRand();
 /* if (number < 0.53) {fParticleGun->SetParticleEnergy(59.54*keV); }// 35.9%
  else if(0.53 < number && number < 0.8) {fParticleGun->SetParticleEnergy(18*keV); }// 2,4%
  else {fParticleGun->SetParticleEnergy(14*keV);}// 2,4% */
  fParticleGun->SetParticleEnergy(150*keV);
  
  fParticleGun->SetParticleMomentumDirection(dir);
  fParticleGun->GeneratePrimaryVertex(anEvent);
  
  }
