#include "ground-station.h"
#include "ns3/core-module.h"
#include <stdexcept>

namespace leo
{

GroundStation::GroundStation (
  int id,
  std::string name,
  double latitude, double longitude,
  double elevation, double xCartesian, double yCartesian,
  double zCartesian)
  : m_id(id),
    m_name(name),
    m_latitude(latitude),
    m_longitude(longitude),
    m_elevation(elevation),
    m_xCartesian(xCartesian),
    m_yCartesian(yCartesian),
    m_zCartesian(zCartesian)
{}

GroundStation::GroundStation (std::vector<std::string> gs) : GroundStation(
  std::stoi(gs[0]),
  gs[1],
  std::stod(gs[2]),
  std::stod(gs[3]),
  std::stod(gs[4]),
  std::stod(gs[5]),
  std::stod(gs[6]),
  std::stod(gs[7])
)
{}

// GroundStation (std::vector<std::string> gs)
// {
//   if (gs.size() < 8) {
//     throw new std::invalid_argument("Invalid Input");
//   }
//   GroundStation(
//     std::stoi(gs[0]),
//     gs[1],
//     std::stoi(gs[2]),
//     std::stoi(gs[3]),
//     std::stoi(gs[4]),
//     std::stoi(gs[5]),
//     std::stoi(gs[6]),
//     std::stoi(gs[7])
//   );
// }

}