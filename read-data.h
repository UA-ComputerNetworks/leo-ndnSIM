#ifndef READ_DATA
#define READ_DATA
#include "model/ground-station.h"
#include "model/tle.h"
#include "model/topo.h"
#include <vector>

namespace leo
{
  std::vector<leo::GroundStation> readGroundStations(string fname);
  std::vector<leo::GroundStation> readGroundStations(string fname, int offset);
  std::vector<leo::Tle> readTles(string fname);
  std::vector<leo::Topo> readIsls(string fname);
}

#endif // READ_DATA_H