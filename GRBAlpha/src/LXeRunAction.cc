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
// $Id: LXeRunAction.cc 68752 2013-04-05 10:23:47Z gcosmo $
//
/// \file optical/LXe/src/LXeRunAction.cc
/// \brief Implementation of the LXeRunAction class
//
//
#include "LXeTrackingAction.hh"
#include "G4Threading.hh"
#include "LXeRunAction.hh"
#include "LXeRecorderBase.hh"
#include "G4RunManager.hh"
#include "FileReader.hh"
#include "LXeRun.hh"
#include "Spectrum.hh"

#include "G4Run.hh"
#include "G4AutoLock.hh"
#include <string>
#include <map>

namespace { G4Mutex myHEPPrimGenMutex = G4MUTEX_INITIALIZER; }
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void PrintNParticles(std::map<const G4ParticleDefinition*, int>& container);
void WriteOutParticles(std::map<const G4ParticleDefinition*, int>& container, std::string& name, G4int TID);


LXeRunAction::LXeRunAction(LXeRecorderBase* r) : fRecorder(r) {
	Checked_Already = 0;
	
	  // Reading in data for event generation
  
  	  G4AutoLock lock(&myHEPPrimGenMutex);
// reading in type of particle
// check if file exists and particle names are OK
    std::ifstream f2("particleforgun.txt");
	if(!f2.good()){
		G4cout << "*******************************" << G4endl;
		G4cout << "Abort!!!" << G4endl;
		G4cout << "File: " << "particleforgun.txt" << " does not exist!" << G4endl;
		G4cout << "*******************************" << G4endl;

		exit(-1);
		}

    std::ifstream f99("energy.txt");

	if(!f99.good()){
		G4cout << "*******************************" << G4endl;
		G4cout << "Abort!!!" << G4endl;
		G4cout << "File: " << "energy.txt" << " does not exist!" << G4endl;
		G4cout << "*******************************" << G4endl;

		exit(-1);
		}

	std::ifstream file("particleforgun.txt");
	while (std::getline(file, infileline))
    {
	Part_Name = infileline;	
	}
	
	std::ifstream file66("energy.txt");
	while (std::getline(file66, infileline))
    {
	Energy = std::atoi(infileline.c_str());	
	}
	//G4cout << Part_Name.size() <<G4endl;
	//G4cout << "ok" <<G4endl;
    


// reading in energy spectras for particles:
	std::string infileline;
	std::string infilename;
std::ifstream file2("thefileforgun.txt");

while (std::getline(file2, infileline))
    {
	infilename = infileline;	
    }

    std::ifstream f(infilename.c_str());
	if(!f.good()){
		G4cout << "*******************************" << G4endl;
		G4cout << "Abort!!!" << G4endl;
		G4cout << "File: " << infilename << " does not exist!" << G4endl;
		G4cout << "*******************************" << G4endl;

		exit(-1);
		}

// std::fstream in("/home/galgoczi/cubesat/cosmic_spectras/500km_electrons_max.txt");
	/*
	std::ifstream in(infilename.c_str());
    std::string line;
    int p = 0;

    while (std::getline(in, line))
    {
        float value;
        std::stringstream ss(line);
        Particle_Energy_In_RunAction.push_back(std::vector<float>());
        while (ss >> value)
        {
		//	cout << value << " ";
            Particle_Energy_In_RunAction[p].push_back(value);
        }
      //  cout << "\n";
      //  cout << i << "\n";
        ++p;
    }
	*/

	// Read in energy spectra for particle gun
	  MTFileReader* ReadIn = new MTFileReader(infilename.c_str());
	  Particle_Energy_In_RunAction = ReadIn->LoadSpectra();
		
		EnSpectrum = new Spectrum();
		EnSpectrum->SaveSpectrum(Particle_Energy_In_RunAction);

	  lock.unlock();



	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeRunAction::~LXeRunAction() {	delete EnSpectrum;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Run* LXeRunAction::GenerateRun()
{ 
  fRun = new LXeRun(); 
  return fRun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeRunAction::BeginOfRunAction(const G4Run* aRun){
  if(fRecorder)fRecorder->RecordBeginOfRun(aRun);
 } 


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeRunAction::EndOfRunAction(const G4Run* aRun){
	/*
	for(std::vector<G4int>::iterator it = PMTHitNo2.begin(); it != PMTHitNo2.end() ; it++){
		G4cout << *it << G4endl;
		}*/
	

	fpTrackingAction = (LXeTrackingAction*) G4RunManager::GetRunManager()->GetUserTrackingAction();

	std::map<const G4ParticleDefinition*, int>&
    particlesCreatedInWorld = fpTrackingAction->GetNParticlesCreatedInWorld();
  
	// if it is thread number 0 print out the particles to file
	// G4int G4Threading::G4GetThreadId()
	G4int ThreadID = G4Threading::G4GetThreadId();
  
	//G4cout << ThreadID << "\n";
	
	
	
	if(G4Threading::IsWorkerThread()){
		G4cout << "ThreadId: " << ThreadID << G4endl;
		G4cout << "Number and type of particles created:" << G4endl;
		PrintNParticles(particlesCreatedInWorld);
		G4cout << "_______________________" << G4endl;
		std::string FName = "Particles.txt";
		
		
		G4AutoLock lockPart(&myHEPPrimGenMutex);
		WriteOutParticles(particlesCreatedInWorld, FName, ThreadID);
		lockPart.unlock();
		}
		
	if (isMaster){	
	fRun->Calculations();
	
	}
	
  if(fRecorder)fRecorder->RecordEndOfRun(aRun);
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
void PrintNParticles(std::map<const G4ParticleDefinition*, int>& container)
{
    std::map<const G4ParticleDefinition*, int>::iterator it;
    for(it = container.begin() ;
        it != container.end(); it ++)
    {
        G4cout << "N " << it->first->GetParticleName() << " : " << it->second << G4endl;
    }
}
 
// ................................................................................................

void WriteOutParticles(std::map<const G4ParticleDefinition*, int>& container, std::string& name, G4int TID)
{
	std::ofstream outfile;
	outfile.open(name.c_str(),  std::ios_base::app);

    std::map<const G4ParticleDefinition*, int>::iterator it;
    
    outfile  << G4endl;
    outfile << "ThreadID: " << TID << G4endl;
    for(it = container.begin() ;
        it != container.end(); it ++)
    {
        outfile << it->first->GetParticleName() << " : " << it->second << G4endl;
    }
	outfile << "_______________________" << G4endl;

}
