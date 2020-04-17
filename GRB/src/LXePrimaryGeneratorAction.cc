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
const int Gun_On_Sphere = 0;
const int Parallel_Beam = 1;


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
 
  G4String Particle_Name = fRunAction->Part_Name;
  //G4cout << Particle_Name << G4endl;
  //G4cout << "Fura" << G4endl;
  //exit(-1);
  
//  G4ParticleTable::GetParticleTable()->DumpTable();


  
  G4String particleName;
  fParticleGun->SetParticleDefinition(particleTable->
                                     FindParticle(particleName=Particle_Name));
  //Default energy,position,momentum
 // fParticleGun->SetParticleEnergy(fRunAction->Energy*keV);
  //G4cout << "Energy " << fRunAction->Energy << G4endl;
  fParticleGun->SetParticlePosition(G4ThreeVector(300,0.0001,0));
  
 // fParticleGun->SetParticleMomentumDirection(G4ThreeVector(10,10,0.));  
    	     
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

  
	if(Parallel_Beam == 1) {  
			assert(Gun_On_Sphere == 0);	

   //if(anEvent->GetEventID() == 0) position2 = fParticleGun->GetParticlePosition();
	if(fRunAction->Checked_Already==0){
		
		position2 = fParticleGun->GetParticlePosition();
		fRunAction->Checked_Already=1;
		}

   //position2 = fParticleGun->GetParticlePosition();
  // cout << "gun was at: " << position2[0] << " " << position2[1] << " " << position2[2] << "\n"; 

  G4double alpha = std::atan(position2[1]/position2[0]);
  
  
  if( (position2[1] > 0 && position2[0] < 0) || (position2[1] < 0 && position2[0] < 0))
	{
	G4ThreeVector dir(std::cos(alpha),std::sin(alpha),0);
	fParticleGun->SetParticleMomentumDirection(dir);  
	}
  else if((position2[1] < 0 && position2[0] > 0) || (position2[1] > 0 && position2[0] > 0))
	{
	G4ThreeVector dir(-std::cos(alpha),-std::sin(alpha),0);	
	fParticleGun->SetParticleMomentumDirection(dir);  
	}
  else{
	  G4cout << "Gun position set is invalid!!" << G4endl;
	  G4cout << position2[0] << G4endl;
	  G4cout << position2[1] << G4endl;
	  exit(-1);}


  G4double RandXY = -1 + 2*G4UniformRand();
  G4double RandZ = -1+2*G4UniformRand();
  //G4cout << "hoo " << position2[0] + 300 * std::sin(alpha) * RandXY << G4endl;
  fParticleGun->SetParticlePosition(G4ThreeVector(position2[0] + 300 * std::sin(alpha) * RandXY, position2[1] - 300 * std::cos(alpha) * RandXY, 300*RandZ)); 
  //cout << "gun was" << position2[0] << " " << position2[1] << " " << position2[2] << "\n";
	}

	if(Gun_On_Sphere == 1){
		
	assert(Parallel_Beam == 0);	
		
 //opening angle
  //
  G4double alphaMin =  0;
  G4double alphaMax = 180*deg;
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
  
  
  // Place gun on a sphere
  
  
  cosTheta = 2*G4UniformRand() - 1;
  sinTheta = std::sqrt(1. - cosTheta*cosTheta);
  phi      = 6.28318530718*G4UniformRand();
  ur = G4ThreeVector(sinTheta*std::cos(phi),sinTheta*std::sin(phi),cosTheta);
  cosAlpha = fCosAlphaMin - G4UniformRand()*(fCosAlphaMin - fCosAlphaMax); 
  sinAlpha = std::sqrt(1. - cosAlpha*cosAlpha);
  psi      = 6.28318530718*G4UniformRand();
  
  fParticleGun->SetParticlePosition(G4ThreeVector(sinAlpha*std::cos(psi)*330*cm,-cosAlpha*330*cm,sinAlpha*std::sin(psi)*330*cm));
  fParticleGun->SetParticleMomentumDirection(dir);
  
  }



 double number = G4UniformRand();
 /* if (number < 0.53) {fParticleGun->SetParticleEnergy(59.54*keV); }// 35.9%
  else if(0.53 < number && number < 0.8) {fParticleGun->SetParticleEnergy(18*keV); }// 2,4%
  else {fParticleGun->SetParticleEnergy(14*keV);}// 2,4% */
  

	// All particle fluxes are in cm-2s-1 and MeV
//  const double gammas_energy[4] = {'0.01', '0.03', '0.05', '0.08', '0.1', '0.3','0.5', '0.8', '1', '3', '5','10'};
// const double gammas_propability[4] = {'1', '3', '7', '9'};

//cout << "start\n";
//for(int p = 0; p<30;p++){
//	for(int r = 0; r < 3; r++){
//		cout << Particle_Energy[p][r] << " ";
//		}cout << "\n";}

//exit(-1);

  double Ener = fRunAction->EnSpectrum->DrawEnergy();
  //G4cout << "Energy was: " << Ener << "\n"; // verbosehoz

  fParticleGun->SetParticleEnergy(Ener*MeV);
	//G4cout << Ener << " was" << G4endl;
  //fParticleGun->SetParticleEnergy(energy*MeV);
  //cout << "Energy was: " << energy << "\n"; // verbosehoz
  fParticleGun->GeneratePrimaryVertex(anEvent);
}
