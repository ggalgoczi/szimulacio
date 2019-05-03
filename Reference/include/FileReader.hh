#ifndef FileReader_h
#define FileReader_h 1

#include <vector>
#include <string>
class FileReader
{
 public:
   FileReader(std::string fileName);
   ~FileReader();
   std::vector<std::vector<double> > LoadSpectra();
 private:
 std::string fileName;

};

#endif
