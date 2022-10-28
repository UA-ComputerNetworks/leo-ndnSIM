// read-data.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include "model/ground-station.h"
#include "model/tle.h"
#include "model/topo.h"

using namespace std;


namespace leo {
vector<leo::GroundStation> readGroundStations(string fname, int offset)
{
    vector<leo::GroundStation> groundStations; 
    ifstream input( fname );
    string line;
    while(getline(input, line))
    {
        vector<string> result;
        boost::split(result, line, boost::is_any_of(","));
        groundStations.emplace_back(leo::GroundStation(result, offset));
        // for (size_t i = 0; i < result.size(); i++)
        //     cout << result[i] << " ";
        // cout << "\n";
    }
    cout << "Imported " << groundStations.size() << " ground stations from " << fname << endl; 
  if (!groundStations.empty()) cout << "ID(s): " << groundStations[0].m_uid << " <--> "<< groundStations [groundStations.size() - 1].m_uid << endl;
    return groundStations;
}

vector<leo::GroundStation> readGroundStations(string fname)
{
    return readGroundStations(fname, 0);
}

vector<leo::Tle> readTles(string fname)
{
    vector<leo::Tle> Tles; 
    ifstream input( fname );

    int orbit_count;
    int sat_count_per_orbit;
    input >> orbit_count >> sat_count_per_orbit;

    string title;
    string line1;
    string line2;
    for (int orbit = 0; orbit < orbit_count; orbit++) {
        for (int sat = 0; sat < sat_count_per_orbit; sat++) {
            getline(input, title);
            getline(input, line1);
            getline(input, line2);
            Tles.emplace_back(leo::Tle(orbit, orbit * sat_count_per_orbit + sat,
                              title, line1, line2));
        }
    }
    cout << "Imported " << Tles.size() << " TLEs from " << fname << endl;
    if (!Tles.empty()) cout << "ID(s): " << Tles[0].m_uid << " <--> "<< Tles [Tles.size() - 1].m_uid << endl;
    return Tles;
}

vector<leo::Topo> readIsls(string fname)
{
    vector<leo::Topo> topo; 
    ifstream input( fname );
    string line;
    while(getline(input, line))
    {
        int uid_1;
        int uid_2;
        input >> uid_1 >> uid_2;
        topo.emplace_back(leo::Topo(uid_1, uid_2));
    }
    cout << "Imported " << topo.size() << " topology entries from " << fname << endl;
    return topo;
}

}
