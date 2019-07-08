#ifndef Spectrum_h
#define Spectrum_h 1

#include <vector>
#include <string>

class Spectrum
{
 public:
   Spectrum();
   ~Spectrum();
   void SaveSpectrum(std::vector<std::vector<double> >);
   double DrawEnergy();
   void CreatePropTable();
 private:
	std::vector<std::vector<double> > EnergySpectrum;
	std::vector<double> Propability;
	std::vector<double> PrintForCheckHolder;
	std::vector<int> PrintForCheck;
	double IntegralFlux;

};

#endif
