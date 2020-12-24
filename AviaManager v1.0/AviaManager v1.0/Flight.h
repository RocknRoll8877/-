#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

using namespace std;


class Flight
{
public:
    Flight(int newHoursFrom, int newMinutesFrom, int newHoursTo, int newMinutesTo, string newFrom, string newTo, string newAirplane);

    int getHoursFrom() const;

    int getMinutesFrom() const;

    int getHoursTo() const;

    int getMinutesTo() const;

    string getFrom() const;

    string getTo() const;

    string getAirplane() const;

    bool operator<(const Flight& rhs) const;

    bool operator>(const Flight& rhs) const;

    bool operator<=(const Flight& rhs) const;

    bool operator>=(const Flight& rhs) const;

private:
    int hoursFrom;
    int minutesFrom;
    int hoursTo;
    int minutesTo;
    string from;
    string to;
    string airplane;
};
