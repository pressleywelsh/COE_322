#include <vector>
#include <string>
void readFile( std::string fileName, std::vector<int>& nyears, std::vector<int>& dev);
void prevRecord(std::vector<int>& nyears, std::vector<int>& dev, std::vector<int>& previousRecord);
void gaps(int month, std::vector<int>& nyears, std::vector<int>& previousRecord, std::vector<int>& gapyears, std::vector<int>& gapsizes);
