#include "Flight.h"


Flight::Flight(int newHoursFrom, int newMinutesFrom, int newHoursTo, int newMinutesTo, string newFrom, string newTo, string newAirplane)
{

    if (newHoursFrom < 1 || newHoursFrom > 24)
    {
        throw out_of_range("New hours from value is invalid: " + to_string(newHoursFrom));
    }
    else if (newMinutesFrom < 1 || newMinutesFrom > 60)
    {
        throw out_of_range("New minutes from value is invalid: " + to_string(newMinutesFrom));
    }
    else if (newHoursTo < 1 || newHoursTo> 24)
    {
        throw out_of_range("New hours to is invalid: " + to_string(newHoursTo));
    }
    else if (newMinutesTo < 1 || newMinutesTo > 60)
    {
        throw out_of_range("New minutes to is invalid: " + to_string(newMinutesTo));
    }
    else if (newMinutesTo == newMinutesFrom && newHoursFrom == newHoursTo)
    {
        throw out_of_range("Invalid time format");
    }
    hoursFrom = newHoursFrom;
    minutesFrom = newMinutesFrom;
    hoursTo = newHoursTo;
    minutesTo = newMinutesTo;
    from = newFrom;
    to = newTo;
    airplane = newAirplane;
}


bool Flight::operator<(const Flight& rhs) const {
    if (hoursFrom < rhs.hoursFrom)
        return true;
    if (rhs.hoursFrom < hoursFrom)
        return false;
    if (minutesFrom < rhs.minutesFrom)
        return true;
    if (rhs.minutesFrom < minutesFrom)
        return false;
    if (hoursTo < rhs.hoursTo)
        return true;
    if (rhs.hoursTo < hoursTo)
        return false;
    if (minutesTo < rhs.minutesTo)
        return true;
    if (rhs.minutesTo < minutesTo)
        return false;
    if (from < rhs.from)
        return true;
    if (rhs.from < from)
        return false;
    if (to < rhs.to)
        return true;
    if (rhs.to < to)
        return false;
    return airplane < rhs.airplane;
}

bool Flight::operator>(const Flight& rhs) const {
    return rhs < *this;
}

bool Flight::operator<=(const Flight& rhs) const {
    return !(rhs < *this);
}

bool Flight::operator>=(const Flight& rhs) const {
    return !(*this < rhs);
}

int Flight::getHoursFrom() const
{
    return hoursFrom;
};

int Flight::getMinutesFrom() const
{
    return minutesFrom;
};

int Flight::getHoursTo() const
{
    return hoursTo;
};

int Flight::getMinutesTo() const
{
    return minutesTo;
};

string Flight::getFrom() const
{
    return from;
};

string Flight::getTo() const
{
    return to;
};

string Flight::getAirplane() const {

    return airplane;
}

