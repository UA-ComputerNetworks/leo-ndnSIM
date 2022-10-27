// read-data.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include "model/ground-station.h"

using namespace std;


namespace leo {
vector<leo::GroundStation> readGroundStations(string fname)
{
    vector<leo::GroundStation> groundStations; 
    cout << "Reading ground_station.txt\n"; 
    ifstream input( fname );
    string line;
    while(std::getline(input, line))
    {
        vector<string> result;
        boost::split(result, line, boost::is_any_of(","));
        groundStations.emplace_back(leo::GroundStation(result));
        // for (size_t i = 0; i < result.size(); i++)
        //     cout << result[i] << " ";
        // cout << "\n";
    }
    return groundStations;
}

}
