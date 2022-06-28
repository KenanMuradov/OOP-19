#pragma once

namespace HeaderFiles::Helpers
{
	struct LogIn
	{
		string username = "";
		string password = "";
		bool isAdmin = 0;

		LogIn() = default;

		LogIn(string username, string password, bool isAdmin);

	};
	LogIn::LogIn(string username, string password, bool isAdmin)
		: username(username), password(password), isAdmin(isAdmin) {}

	istream& operator>>(istream& input, LogIn& log)
	{
		cout << "Enter username: ";
		getline(input, log.username);
		string tempPass;
		cout << "Enter password: ";
		getline(input, log.password);
		cout << tempPass << endl;
		log.password = tempPass;

		cout << "\nAre you an Admin?(0 -> no, 1 -> yes): ";
		input >> log.isAdmin;

		return input;
	}

	struct Date
	{
		int day = 0;
		int month = 0;
		int year = 0;

		Date() = default;
		Date(int day, int month, int year);
	};
	Date::Date(int day, int month, int year)
		: day(day), month(month), year(year) {}

	ostream& operator<<(ostream& out, const Date& d)
	{
		out << d.day << '/' << d.month << '/' << d.month;

		return out;
	}

	istream& operator>>(istream& in, Date& d)
	{
		cout << "Enter day: ";
		in >> d.day;

		cout << "Enter month: ";
		in >> d.month;

		cout << "Enter year: ";
		in >> d.year;

		return in;
	}

}


