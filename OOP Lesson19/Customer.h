#pragma once


namespace HeaderFiles::People
{
	using namespace HeaderFiles::Helpers;

	class Customer : public Person
	{
	public:
		string username = "";
		string password = "";

		Customer() = default;

		Customer(string username, string password, string name, string surname, Date dateOfBirth);

	};

	Customer::Customer(string username, string password, string name, string surname, Date dateOfBirth)
		: Person(name, surname, dateOfBirth)
	{
		this->username = username;
		this->password = password;
	}

	istream& operator>>(istream& in, Customer& c)
	{
		cout << "Enter Name: ";
		getline(in, c.name);

		cout << "Enter Surname: ";
		getline(in, c.surname);

		cout << "Enter Birth date\n";
		in >> c.dateOfBirth;

		in.ignore();

		cout << "Enter username: ";
		getline(in, c.username);

		cout << "Enter password: ";
		getline(in, c.password);

		return in;
	}
}

	
