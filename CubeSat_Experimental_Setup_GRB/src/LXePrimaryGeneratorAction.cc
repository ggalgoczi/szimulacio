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



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXePrimaryGeneratorAction::LXePrimaryGeneratorAction(){
  G4int n_particle = 1;
  fParticleGun = new G4ParticleGun(n_particle);
 
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
 
  G4String particleName;
  fParticleGun->SetParticleDefinition(particleTable->
                                     FindParticle(particleName="gamma"));
  //Default energy,position,momentum
  fParticleGun->SetParticleEnergy(59.54*keV);
  fParticleGun->SetParticlePosition(G4ThreeVector(-300,0.0001,0));
  
 // fParticleGun->SetParticleMomentumDirection(G4ThreeVector(10,10,0.));  
	

// reading in energy spectras for particles:

 std::fstream in("/home/galgoczi/cubesat/cosmic_spectras/500km_electrons_max.txt");
    std::string line;
    int i = 0;

    while (std::getline(in, line))
    {
        float value;
        std::stringstream ss(line);

        ElectronEnergyMax.push_back(std::vector<float>());

        while (ss >> value)
        {
//			cout << ss;
            ElectronEnergyMax[i].push_back(value);
 
        }
        ++i;
    }
    in.close();   
	in.open ("/home/galgoczi/cubesat/cosmic_spectras/band_correct.txt", std::fstream::in);

	i = 0;
    while (std::getline(in, line))
    {	
        float value;
        std::stringstream ss2(line);
        ElectronEnergyMin.push_back(std::vector<float>());

        while (ss2 >> value)
        {
            ElectronEnergyMin[i].push_back(value);
        } 
        ++i;
    }
    in.close();
	in.open("/home/galgoczi/cubesat/cosmic_spectras/500km_protons_max.txt", std::fstream::in);

	i = 0;	
    while (std::getline(in, line))
    {
        float value;
        std::stringstream ss(line);

        ProtonEnergyMax.push_back(std::vector<float>());

        while (ss >> value)
        {
//			cout << ss;
            ProtonEnergyMax[i].push_back(value);
 
        }
        ++i;
    }    
    in.close();
	in.open ("/home/galgoczi/cubesat/cosmic_spectras/500km_protons_min.txt", std::fstream::in);

	i = 0;
    while (std::getline(in, line))
    {
        float value;
        std::stringstream ss(line);

        ProtonEnergyMin.push_back(std::vector<float>());

        while (ss >> value)
        {
//			cout << ss;
            ProtonEnergyMin[i].push_back(value);
 
        }
        ++i;
    }
    in.close();
    
    // Norming the propabilities
    // Proton Min
    double sum = 0;
    double count = 0;
	for (int i = 0; i < ProtonEnergyMin.size(); i++)
		{
		sum += ProtonEnergyMin[i][2];
		}    
	cout << "ProtonEnergyMin sum was" << " " << sum << "\n";		
		
	for (int i = 0; i < ProtonEnergyMin.size(); i++)
		{
		//	cout << ProtonEnergyMin[i][2] << " " << sum << "\n";
		count += double(ProtonEnergyMin[i][2])/sum;		
		ProtonEnergyMin[i].push_back(count);
		}
    // Proton Max
    sum = 0;
    count = 0;
	for (int i = 0; i < ProtonEnergyMax.size(); i++)
		{
		sum += ProtonEnergyMax[i][2];
		}    
	cout << "ProtonEnergyMax sum was" << " " << sum << "\n";		
		
	for (int i = 0; i < ProtonEnergyMax.size(); i++)
		{
		//	cout << ProtonEnergyMin[i][2] << " " << sum << "\n";
		count += double(ProtonEnergyMax[i][2])/sum;		
		ProtonEnergyMax[i].push_back(count);
		}    
    // Electron Min
    sum = 0;
    count = 0;
	for (int i = 0; i < ElectronEnergyMin.size(); i++)
		{
		sum += ElectronEnergyMin[i][2];
		}    
	cout << "ElectronEnergyMin sum was" << " " << sum << "\n";		
		
	for (int i = 0; i < ElectronEnergyMin.size(); i++)
		{
		//	cout << ProtonEnergyMin[i][2] << " " << sum << "\n";
		count += double(ElectronEnergyMin[i][2])/sum;		
		ElectronEnergyMin[i].push_back(count);
		}    
    // Electron Max
    sum = 0;
    count = 0;
	for (int i = 0; i < ElectronEnergyMax.size(); i++)
		{
		sum += ElectronEnergyMax[i][2];
		}    

	cout << "ElectronEnergyMax sum was" << " " << sum << "\n";		
	for (int i = 0; i < ElectronEnergyMax.size(); i++)
		{
		//	cout << ProtonEnergyMin[i][2] << " " << sum << "\n";
			count += double(ElectronEnergyMax[i][2])/sum;
			ElectronEnergyMax[i].push_back(count);
		}    
        
            
    // Printing out data from file
    
for (int i = 0; i < ElectronEnergyMin.size(); i++)
	{
    for (int j = 0; j < ElectronEnergyMin[i].size(); j++)
		{
        cout << ElectronEnergyMin[i][j] << " ";
		}
	cout << "\n";
	} 
	
    
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXePrimaryGeneratorAction::~LXePrimaryGeneratorAction(){
    delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){
cout << "whaat\n" ;
  cout << anEvent->GetEventID()  << "\n";
  //exit(-1);
   if(anEvent->GetEventID() == 0) position2 = fParticleGun->GetParticlePosition();
   cout << "gun was" << position2[0] << " " << position2[1] << " " << position2[2] << "\n";

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
  else{printf("Gun position set is invalid!!\n");exit(-1);}


  G4double RandXY = -1 + 2*G4UniformRand();
  G4double RandZ = -1+2*G4UniformRand();
  fParticleGun->SetParticlePosition(G4ThreeVector(position2[0] + 300 * std::sin(alpha) * RandXY, position2[1] - 300 * std::cos(alpha) * RandXY, 300*RandZ)); 
  //cout << "gun was" << position2[0] << " " << position2[1] << " " << position2[2] << "\n";



 double number = G4UniformRand();
 /* if (number < 0.53) {fParticleGun->SetParticleEnergy(59.54*keV); }// 35.9%
  else if(0.53 < number && number < 0.8) {fParticleGun->SetParticleEnergy(18*keV); }// 2,4%
  else {fParticleGun->SetParticleEnergy(14*keV);}// 2,4% */
  

	// All particle fluxes are in cm-2s-1 and MeV
//  const double gammas_energy[4] = {'0.01', '0.03', '0.05', '0.08', '0.1', '0.3','0.5', '0.8', '1', '3', '5','10'};
// const double gammas_propability[4] = {'1', '3', '7', '9'};
double energy = 0;
	for (int i = 0; i < ElectronEnergyMin.size(); i++)
		{
       // cout << "itt" << ElectronEnergyMin[i][3] << " " << number << "\n";
	if(i == 0){
		if(double(ElectronEnergyMin[0][3]) > number)
			{
			energy = ElectronEnergyMin[i][0];
     //   cout << "ooo" << ElectronEnergyMin[i][3] << " " << number << "\n";
			}			
		}
	else{
	if(double(ElectronEnergyMin[i][3]) > number && double(ElectronEnergyMin[i-1][3]) < number)
			{
			energy = ElectronEnergyMin[i][0];
        //cout << "ooo" << ElectronEnergyMin[i][3] << " " << ElectronEnergyMin[i][0] << " " << number << "\n";
			}		
		}

	
		}
	//	cout << "now" << " " << energy << " " << number << "\n";
//	cout << energy << "\n";

  fParticleGun->SetParticleEnergy(energy*MeV);
  fParticleGun->GeneratePrimaryVertex(anEvent);
}
