
#ifndef Histogram_h
#define Histogram_h 1

#include <vector>
#include <fstream>
#include <assert.h> 


class Histogram {
  public:
	Histogram (double, double);
	std::vector<double> histo;
	std::vector<double> binmiddlevalue;
	double BinSize ;
	double BinSize2 ;
    void add_values (double);
    void add_values (std::vector<double>&);
    void CreateMiddleValues(double,double);
    void PrintOutHisto(std::string FNAME);
    void Calculate_Hits_Energy(int, int);
    void Calculate_Hits_With_One_Clust();
    void Calculate_Hits_With_One_Clust(int, int);
    std::vector<double> retrive_histo () {return histo;}
};


//GoodNessHist.PrintOutHisto("histoforchisquare");
#endif
