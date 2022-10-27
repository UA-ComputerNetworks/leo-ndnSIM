#ifndef READ_DATA
#define READ_DATA
#include "model/ground-station.h"
#include <vector>

namespace leo
{
std::vector<GroundStation> groundStation;
std::vector<GroundStation> readGroundStation(string fname);
}

#endif // READ_DATA_H