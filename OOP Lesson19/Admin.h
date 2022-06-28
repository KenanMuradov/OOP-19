#pragma once

namespace HeaderFiles::People
{

	using namespace HeaderFiles::Helpers;

	class Admin : public Person
	{

	public:
		Admin::Person p;

		string username = "";
		string password = "";

		Admin() = default;

		Admin(string username, string password,
			string name, string surname, Date dateOfBirth);

		friend istream& operator>>(istream& in, Admin& a);
	};

	Admin::Admin(string username, string password,
		string name, string surname, Date dateOfBirth)
		: Person(name, surname, dateOfBirth)
	{
		this->username = username;
		this->password = password;
	}


	istream& operator>>(istream& in, Admin& a)
	{
		cout << "Enter Name: ";
		getline(in, a.name);

		cout << "Enter Surname: ";
		getline(in, a.surname);

		cout << "Enter Birth date: ";
		in >> a.dateOfBirth;

		in.ignore();

		cout << "Enter username: ";
		getline(in, a.username);

		cout << "Enter password: ";
		getline(in, a.password);

		return in;
	}
}

	


