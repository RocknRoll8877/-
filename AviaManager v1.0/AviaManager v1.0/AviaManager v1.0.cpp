#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include "Flight.h"
#include "Database.h"

using namespace std;



Flight ParseFlight(const string& data)
{

    map<int, string> destinationDB = { {1, "MSC"}, {2, "BAK"}, {3, "MNS"}, {4, "BFS"}, {5, "NYC"}, {6, "LAC"}, {7, "DET"}, {8, "SPT"}, {9, "WAS"}, {10, "PRS"} };

    map<int, string> airplaneDB = { {1, "Tu-134"}, {2, "Tu-154"}, {3, "Tu-204"}, {4, "Sukhoi SuperJet-100"}, {5, "Il-62"}, {6, "Il-86"},
                                    {7, "Airbus-A310"}, {8, "Airbus-A320"}, {9, "Boeing-737"}, {10, "Boeing-747"}, {11, "Boeing - 777"} };

    istringstream date_stream(data);
    bool flag = true;

    int hoursFrom;
    flag = flag && (date_stream >> hoursFrom);
    flag = flag && (date_stream.peek() == ':');
    date_stream.ignore(1);

    int minutesFrom;
    flag = flag && (date_stream >> minutesFrom);
    flag = flag && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int hoursTo;
    flag = flag && (date_stream >> hoursTo);
    flag = flag && (date_stream.peek() == ':');
    date_stream.ignore(1);

    int minutesTo;
    flag = flag && (date_stream >> minutesTo);
    flag = flag && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int fromCode;
    flag = flag && (date_stream >> fromCode);
    flag = flag && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int toCode;
    flag = flag && (date_stream >> toCode);
    flag = flag && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int airplaneCode;
    flag = flag && (date_stream >> airplaneCode);
    flag = flag && date_stream.eof();

    if (destinationDB[fromCode] == destinationDB[toCode] || destinationDB[toCode] == "" || destinationDB[fromCode] == "" || airplaneDB[airplaneCode] == "" || flag == false) {
        throw logic_error("Wrong data format: " + data);
    }

    string from = destinationDB[fromCode];
    string to = destinationDB[toCode];
    string airplane = airplaneDB[airplaneCode];


    return Flight(hoursFrom, minutesFrom, hoursTo, minutesTo, from, to, airplane);
}



int main()
{
    cout << "Welcome to AviaManager v1.0!\n";
    cout << "Print <Add> to add new flight according to the next format:\n";
    cout << "Time to start - time to finish - number of start city - number of finish city - number model of airplane. Then print the name of flight. For example:\n";
    cout << "Add 12:28-14:47-2-3-4 E404\n";
    cout << "Print <Find> to find flight's number according to the format. For example:\n";
    cout << "Find 12:28-14:47-2-3-4 E404\n";
    cout << "Print <Del> to delete data from programm according to the format. For example:\n";
    cout << "Del 12:28-14:47-2-3-4\n";
    cout << "To print information to the terminal enter <Print>\n";

    try
    {
        Database db;
        string command;

        while (getline(cin, command))
        {
            if (command == "") continue;

            stringstream input(command);

            string operation;
            input >> operation;

            map<string, char> operations_codes = { {"Add", 'A'}, {"Del",'D'}, {"Find", 'F'}, {"Print",'P'} };

            char operation_code = operations_codes[operation];

            switch (operation_code)
            {
            case 'A':
            {
                string flight_info, name;
                input >> flight_info >> name;
                const Flight flight = ParseFlight(flight_info);
                if (name != "" || name != " ") {
                    db.AddEvent(flight, name);
                }
                break;
            }
            case 'D':
            {
                string flight_info, name;
                input >> flight_info;
                if (!input.eof()) {
                    input >> name;
                }

                const Flight flight = ParseFlight(flight_info);

                if (name.empty()) {
                    const int num_of_events_to_del = db.DeleteFlight(flight);
                    cout << "Deleted " << num_of_events_to_del << " flight's number" << endl;
                }
                else {
                    if (db.DeleteName(flight, name)) {
                        cout << "Deleted successfully" << endl;
                    }
                    else {
                        cout << "Flight's number not found" << endl;
                    }
                }
                break;
            }
            case 'F':
            {
                string flight_info, name;
                input >> flight_info >> name;
                const Flight flight = ParseFlight(flight_info);
                set<string> names = db.Find(flight);

                for (string e : names) {
                    cout << e << endl;
                }
                break;
            }
            case 'P':
            {
                db.Print();
                break;
            }
            default:
                cerr << "Unknown command: " << operation << endl;
                return 0;
            }
        }
    }

    catch (exception& e)
    {
        cerr << e.what() << endl;
        return 0;
    }
    return 0;
}

