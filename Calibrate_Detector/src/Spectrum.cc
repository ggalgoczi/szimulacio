#include <iostream>
#include <fstream>
#include <string>
#include "Spectrum.hh"
#include "globals.hh"
#include <assert.h>
#include "Randomize.hh"

void filePutContents3(const std::string& name, const std::vector<int>& content, bool append = false) {
    std::ofstream outfile;
    if (append)
		outfile.open(name.c_str(), std::ios_base::app);
    else
        outfile.open(name.c_str());
    
    for(int p = 0; p < content.size() ;p++)
    outfile << content[p] << G4endl;
}

void filePutContents3(const std::string& name, const std::vector<double>& content, bool append = false) {
    std::ofstream outfile;
    if (append)
		outfile.open(name.c_str(), std::ios_base::app);
    else
        outfile.open(name.c_str());
    
    for(int p = 0; p < content.size() ;p++)
    outfile << content[p] << G4endl;
}

Spectrum::Spectrum()
{ //inputFile.open(filename.data()); 
	


}

Spectrum::~Spectrum() {filePutContents3("SpectraCheck.txt",PrintForCheck);}

void Spectrum::SaveSpectrum(std::vector<std::vector<double> > SpectrumIn)
{
	// "/home/galgoczi/muontomo/MuonTelescope/MuonTelescope/spectrum/spectrum.txt"
	assert(SpectrumIn.size() != 0);
	assert(SpectrumIn[0].size() != 0);
	
	EnergySpectrum = SpectrumIn;
	IntegralFlux = EnergySpectrum[0][2];
	CreatePropTable();
	
	//Save holder for spectrum
for(int k =0 ; k < SpectrumIn.size(); k++){PrintForCheckHolder.push_back(SpectrumIn[k][0]);}	
filePutContents3("SpectraCheckHolder.txt",PrintForCheckHolder);
for(int k =0 ; k < SpectrumIn.size(); k++){
PrintForCheck.push_back(0);}

}

void Spectrum::CreatePropTable(){
	
	for (int i = 0; i < EnergySpectrum.size(); i++){
		Propability.push_back(EnergySpectrum[i][2]/IntegralFlux);
		}
	}


double Spectrum::DrawEnergy()
	{
	G4double Rand = G4UniformRand();
	for (int i = 0; i < Propability.size(); i++){
	if( (i+1) == Propability.size()) {
		PrintForCheck[i]++;
		//G4cout << "endl " << EnergySpectrum[i][0] << G4endl;
		return EnergySpectrum[i][0];
		}	
		
	if(Propability[i+1] < Rand){
		//G4cout << EnergySpectrum[i][0] << G4endl;
		PrintForCheck[i]++;
		return EnergySpectrum[i][0];
		}
	}
}
