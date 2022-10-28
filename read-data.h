#ifndef READ_DATA
#define READ_DATA
#include "model/ground-station.h"
#include "model/tle.h"
#include "model/topo.h"
#include "ns3/network-module.h"

#include <vector>

namespace leo
{

// Explicitly pick an overloaded function for Schedule
void RemoveRouteAB (ns3::Ptr<ns3::Node> node, string prefix, ns3::Ptr<ns3::Node> otherNode);
void AddRouteAB (ns3::Ptr<ns3::Node> node, string prefix, ns3::Ptr<ns3::Node> otherNode, int metric);

std::vector<leo::GroundStation> readGroundStations(string fname);
std::vector<leo::GroundStation> readGroundStations(string fname, int offset);
std::vector<leo::Tle> readTles(string fname);
std::vector<leo::Topo> readIsls(string fname);
void importDynamicState(ns3::NodeContainer nodes, string dname);

}

#endif // READ_DATA_H