// ndn-leo.cc

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ndnSIM-module.h"
#include "read-data.h"

// for LinkStatusControl::FailLinks and LinkStatusControl::UpLinks
#include "ns3/ndnSIM/helper/ndn-link-control-helper.hpp"

namespace ns3 {

int
main(int argc, char* argv[])
{
  // Loading data
  // Importing TLEs
  vector<leo::Tle> tles = leo::readTles("data/tles.txt");
  
  // Importing ground stations
  vector<leo::GroundStation> groundStations = 
    leo::readGroundStations("data/ground_stations.txt", tles.size());

  // Importing topology
  vector<leo::Topo> topo = leo::readIsls("data/isls.txt");

  // For debug
  cout << "press any keys to continue";
  cin.get();

  // Setting default parameters for PointToPoint links and channels
  Config::SetDefault("ns3::PointToPointNetDevice::DataRate", StringValue("1Mbps"));
  Config::SetDefault("ns3::PointToPointChannel::Delay", StringValue("10ms"));
  Config::SetDefault("ns3::DropTailQueue<Packet>::MaxSize", StringValue("20p"));

  // Read optional command-line parameters (e.g., enable visualizer with ./waf --run=<> --visualize
  CommandLine cmd;
  cmd.Parse(argc, argv);

  // Creating nodes
  NodeContainer nodes;
  nodes.Create(tles.size() + groundStations.size());

  // Connecting nodes using two links
  PointToPointHelper p2p;
  p2p.Install(nodes.Get(0), nodes.Get(1));
  p2p.Install(nodes.Get(1), nodes.Get(2));


  // Install NDN stack on all nodes
  ndn::StackHelper ndnHelper;
  ndnHelper.Install(nodes);
  
  // Set up FIB 
  std::string prefix = "sat";
  // TODO
  ndn::FibHelper::AddRoute(nodes.Get(0), "/prefix",nodes.Get(1), 5);
  ndn::FibHelper::AddRoute(nodes.Get(1), "/prefix", nodes.Get(2), 5);
  // ndn::FibHelper::RemoveRoute(nodes.Get(1), "/prefix", nodes.Get(2));

  // Installing applications

  // Consumer
  ndn::AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
  // Consumer will request /prefix/0, /prefix/1, ...
  consumerHelper.SetPrefix("/prefix");
  consumerHelper.SetAttribute("Frequency", StringValue("10")); // 10 interests a second
  consumerHelper.Install(nodes.Get(0));                        // first node

  // Producer
  ndn::AppHelper producerHelper("ns3::ndn::Producer");
  // Producer will reply to all requests starting with /prefix
  producerHelper.SetPrefix("/prefix");
  producerHelper.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper.Install(nodes.Get(2)); // last node

  // The failure of the link connecting consumer and router will start from seconds 10.0 to 15.0
  // Simulator::Schedule(Seconds(10.0), ndn::LinkControlHelper::FailLink, nodes.Get(0), nodes.Get(1));
  // Simulator::Schedule(Seconds(15.0), ndn::LinkControlHelper::UpLink, nodes.Get(0), nodes.Get(1));

  Simulator::Stop(Seconds(5.0));

  Simulator::Run();
  Simulator::Destroy();

  return 0;
}

} // namespace ns3

int
main(int argc, char* argv[])
{
  return ns3::main(argc, argv);
}