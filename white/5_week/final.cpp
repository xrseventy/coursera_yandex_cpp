//
// Created by alfa on 08.06.2020.
//

#include <iostream>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

class Date
{
public:
	Date(int new_year, int new_month, int new_day)
	{
		if (new_month < 1 || new_month > 12)
		{
			string error = "Month value is invalid: " + to_string(new_month);
			throw out_of_range(error);
		}
		else
		if (new_day < 1 || new_day > 31)
		{
			string error = "Day value is invalid: " + to_string(new_day);
			throw out_of_range(error);
		}
		year = new_year;
		month = new_month;
		day = new_day;
	}
	int GetYear() const
	{
		return year;
	}
	int GetMonth() const
	{
		return month;
	}
	int GetDay() const
	{
		return day;
	}
private:
	int year;
	int month;
	int day;
};

ostream& operator<<(ostream& stream, const Date& date)
{
	return stream << setfill('0') << setw(4) <<
				  to_string(date.GetYear()) << '-' <<
				  setfill('0') << setw(2) <<
				  to_string(date.GetMonth()) << '-' <<
				  setfill('0') << setw(2) <<
				  to_string(date.GetDay());;
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() != rhs.GetYear())
	{
		return lhs.GetYear() < rhs.GetYear();
	}
	else
	{
		if (lhs.GetMonth() != rhs.GetMonth())
		{
			return lhs.GetMonth() < rhs.GetMonth();
		}
		else
		{
			if (lhs.GetDay() != rhs.GetDay())
			{
				return lhs.GetDay() < rhs.GetDay();
			}
		}
	}
}

Date ParsingDate(const string& date)
{
	istringstream date_stream(date);
	bool status = true;
	int year;
	status = status && (date_stream >> year);
	status = status && (date_stream.peek() == '-');
	date_stream.ignore(1);
	int month;
	status = status && (date_stream >> month);
	status = status && (date_stream.peek() == '-');
	date_stream.ignore(1);
	int day;
	status = status && (date_stream >> day);
	status = status && (date_stream.eof());
	if (!status)
	{
		string error = "Wrong date format: " + date;
		throw logic_error(error);
	}
	return Date(year, month, day);
}

class Database
{
public:
	void AddEvent(const Date& date, const string& event)
	{
		if (!event.empty())
		{
			database[date].insert(event);
		}
	}
	bool DeleteEvent(const Date& date, const string& event)
	{
		if (database.count(date) > 0 && database[date].count(event) > 0)
		{
			database[date].erase(event);
			return true;
		}
		return false;
	}
	int DeleteDate(const Date& date)
	{
		int del = 0;
		if (database.count(date) > 0)
		{
			del = database.at(date).size();
			database.erase(date);
		}
		return del;
	}
	set<string> Find(const Date& date) const
	{
		set<string> output;
		if (database.count(date) > 0)
		{
			output = database.at(date);
		}
		return output;
	}
	void Print() const
	{
		for (const auto& r : database)
		{
			for (auto s : r.second)
			{
				std::cout << r.first << ' ' << s << '\n';
			}
		}
	}
private:
	std::map<Date, std::set<std::string>> database;
};

int main()
{
	try
	{
		Database db;
		string command;
		while (getline(cin, command))
		{
			if (command == "")
			{
				continue;
			}
			stringstream input(command);
			string action;
			input >> action;
			if (action == "Add")
			{
				string date_str, event;
				input >> date_str >> event;
				const Date date = ParsingDate(date_str);
				if (event != "" || event != " ")
				{
					db.AddEvent(date, event);
				}
			}
			else
			if (action == "Del")
			{
				string date_str,event;
				input >> date_str;
				if (!input.eof())
				{
					input >> event;
				}
				const Date date = ParsingDate(date_str);
				if (event.empty())
				{
					const int events_to_del = db.DeleteDate(date);
					cout << "Deleted " << events_to_del << " events" << '\n';
				}
				else
				{
					if (db.DeleteEvent(date, event))
					{
						cout << "Deleted successfully" << '\n';
					}
					else
					{
						cout << "Event not found" << '\n';
					}
				}
			}
			else
			if (action == "Find")
			{
				string date_string, event;
				input >> date_string >> event;
				const Date date = ParsingDate(date_string);
				set<string> events = db.Find(date);
				for (auto& e : events)
				{
					cout << e << '\n';
				}
			}
			else
			if (action == "Print")
			{
				db.Print();
			}
			else
			{
				cout << "Unknown command: " << action << '\n';
				return 0;
			}
		}
	}
	catch(exception& ex)
	{
		cout << ex.what() << '\n';
		return 0;
	}
	return 0;
}