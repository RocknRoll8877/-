#include "Database.h"

ostream& operator << (ostream& stream, const Flight& flight)
{
    stream << setfill('0') << setw(2) << to_string(flight.getHoursFrom());
    stream << ":";
    stream << setfill('0') << setw(2) << to_string(flight.getMinutesFrom());
    stream << "-";
    stream << setfill('0') << setw(2) << to_string(flight.getHoursTo());
    stream << ":";
    stream << setfill('0') << setw(2) << to_string(flight.getMinutesTo());
    stream << "-";
    stream << setfill('0') << setw(3) << flight.getFrom();
    stream << "-";
    stream << setfill('0') << setw(3) << flight.getTo();
    stream << "- ";
    stream << setfill('0') << flight.getAirplane();
    return stream;
}

void Database::AddEvent(const Flight& flight, const string& name)
{
    if (!name.empty())
    {
        records[flight].insert(name);
    }
}

bool Database::DeleteName(const Flight& flight, const string& name)
{
    if (records.count(flight) > 0 && records[flight].count(name) > 0)
    {
        records[flight].erase(name);
        return true;
    }
    return false;
}

int  Database::DeleteFlight(const Flight& flight)
{
    int to_del = 0;
    if (records.count(flight) > 0)
    {
        to_del = records.at(flight).size();
        records.erase(flight);
    }
    return to_del;
}


set<string> Database::Find(const Flight& flight) const
{
    set<string> result;
    if (records.count(flight) > 0)
    {
        result = records.at(flight);
    }
    return result;
}



void Database::Print() const
{
    for (const auto& r : records)
    {
        for (auto s : r.second)
        {
            cout << r.first << ' ' << s << endl;
        }
    }
}