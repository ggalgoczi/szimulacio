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
#include "LXeRunAction.hh"
#include "LXeRecorderBase.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeRunAction::LXeRunAction(LXeRecorderBase* r) : fRecorder(r) {
	
	
	  // Reading in data for event generation
  
  
// reading in type of particle
// check if file exists and particle names are OK

G4cout << "okk" <<G4endl;

	std::ifstream file("particleforgun.txt");
	while (std::getline(file, infileline))
    {
	Part_Name = infileline;	
	//G4cout << Part_Name.size() <<G4endl;
	//G4cout << "ok" <<G4endl;
    }


// reading in energy spectras for particles:
	std::string infileline;
	std::string infilename;
std::ifstream file2("thefileforgun.txt");
while (std::getline(file2, infileline))
    {
	infilename = infileline;	
    }

// std::fstream in("/home/galgoczi/cubesat/cosmic_spectras/500km_electrons_max.txt");
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





	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeRunAction::~LXeRunAction() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeRunAction::BeginOfRunAction(const G4Run* aRun){
  if(fRecorder)fRecorder->RecordBeginOfRun(aRun);
    
 } 


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeRunAction::EndOfRunAction(const G4Run* aRun){
  if(fRecorder)fRecorder->RecordEndOfRun(aRun);
}
