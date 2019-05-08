#include "Histogram.hh"
#include <iostream>


void PrintHistoToFile(std::vector<double>& Holder, std::vector<double>& Values, std::string Filename, bool AddTwoLinesAtEnd = false){		
		
	std::ofstream output_file0(Filename.c_str());
	assert(Holder.size() == Values.size());
	std::vector<double>::iterator ValsIT = Values.begin();

	for(std::vector<double>::iterator iter = Holder.begin(); iter != Holder.end();iter++){
		output_file0 << *iter << " " << *ValsIT << "\n";
		ValsIT++;
}}

Histogram::Histogram(double min, double max):histo(5000), binmiddlevalue(5000){
	CreateMiddleValues(min, max);
	}

void Histogram::add_values (double Value) {
	int BinToAdd = int(Value/BinSize);
	//std::cout << Value << "\n";
	//std::cout << BinSize << "\n";
	//std::cout << BinToAdd << "\n";
	assert(BinToAdd >= 0 && BinToAdd < 5000);
	histo[BinToAdd]++;
}

void Histogram::add_values (std::vector<double>& Value) {
	for(std::vector<double>::iterator it = Value.begin(); it != Value.end();it++){
	//int BinToAdd = int(*it/BinSize+0.5);
	int BinToAdd = int(*it/BinSize);
	assert(BinToAdd >= 0 && BinToAdd < 5000);
	histo[BinToAdd]++;
}}

void Histogram::CreateMiddleValues (double min, double max) {
	BinSize = (max-min) / 5000.;
	BinSize2 = (max-min) / 5001.;
	for(int k = 0; k < 5001; k++) 
		{binmiddlevalue[k]=BinSize*k+BinSize/2;}
}

void Histogram::PrintOutHisto (std::string FName) {
	std::cout << "Printing file\n";
	PrintHistoToFile(binmiddlevalue,histo,FName);
}
