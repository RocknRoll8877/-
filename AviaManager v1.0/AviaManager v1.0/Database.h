#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include "Flight.h"

using namespace std;


class Database
{
public:
    void AddEvent(const Flight& flight, const string& name);

    bool DeleteName(const Flight& flight, const string& name);

    int  DeleteFlight(const Flight& flight);

    set<string> Find(const Flight& flight) const;

    void Print() const;

private:
    map<Flight, set<string>> records;
};

