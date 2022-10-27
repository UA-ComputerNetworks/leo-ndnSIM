#ifndef GROUND_STATION
#define GROUND_STATION

#include <string>
namespace leo {

class GroundStation
{
public:
  GroundStation(int id, std::string name, double latitude, double longitude,
                double elevation, double xCartesian, double yCartesian,
                double zCartesian);
  int m_id;
  std::string m_name;
  double m_latitude;
  double m_longitude;
  double m_elevation;
  double m_xCartesian;
  double m_yCartesian;
  double m_zCartesian;
  
};

} // namespace leo

#endif // GROUND_STATION_H
