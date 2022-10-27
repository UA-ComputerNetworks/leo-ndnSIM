#include "ground-station.h"
#include "ns3/core-module.h"

namespace leo
{

GroundStation::GroundStation (
  int id, std::string name, double latitude, double longitude,
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

}