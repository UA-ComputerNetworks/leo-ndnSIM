// read-data.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include "model/ground-station.h"

using namespace std;


namespace leo {
vector<GroundStation> groundStation;
vector<GroundStation> readGroundStation(string fname)
{
    cout << "Reading ground_station.txt\n"; 
    ifstream input( fname );
    string line;
    while(std::getline(input, line, ','))
    {
        cout << line;
        vector<string> result;
        boost::split(result, line, boost::is_any_of(","));
        for (size_t i = 0; i < result.size(); i++)
            cout << result[i] << endl;
    }
}

}
