#include <iostream>
#include <fstream>
#include <string>
#include "FileReader.hh"
#include "globals.hh"


FileReader::FileReader(std::string FileName)
{ //inputFile.open(filename.data()); 
	fileName = FileName;
}

FileReader::~FileReader()
{}

std::vector<std::vector<double> > FileReader::LoadSpectra()
{
	std::vector<std::vector<double> > MuonEnergyTable;
	// "/home/galgoczi/muontomo/MuonTelescope/MuonTelescope/spectrum/spectrum.txt"
	
	std::ifstream f2(fileName.c_str());
	if(!f2.good()){
		G4cout << "*******************************" << G4endl;
		G4cout << "Abort!!!" << G4endl;
		G4cout << "File: " << fileName << " does not exist!" << G4endl;
		G4cout << "*******************************" << G4endl;
		exit(-1);
		}

	std::fstream in(fileName.c_str());
    std::string line;
    int j = 0;

    while (std::getline(in, line))
    {
        float value;
        std::stringstream ss(line);
        MuonEnergyTable.push_back(std::vector<double>());
        while (ss >> value)
        {
        MuonEnergyTable[j].push_back(value); 
        }
        ++j;
    }
    in.close(); 
     
  return MuonEnergyTable;
}
