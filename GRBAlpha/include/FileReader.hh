
#include <vector>
#include <string>
class MTFileReader
{
 public:
   MTFileReader(std::string fileName);
   ~MTFileReader();
   std::vector<std::vector<double> > LoadSpectra();
 private:
 std::string fileName;

};

