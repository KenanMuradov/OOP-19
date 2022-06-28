#pragma once


namespace HeaderFiles::People
{
	using namespace HeaderFiles::Helpers;


	class Person
	{
	private:

		static int _staticId;

	public:
		int id = 0;
		string name = "";
		string surname = "";
		Date dateOfBirth;

		Person() : id(++_staticId) {}

		Person(string name, string surname, Date dateOfBirth);
	};
	int Person::_staticId = 0;

	Person::Person(string name, string surname, Date dateOfBirth)
		: id(++_staticId), name(name), surname(surname), dateOfBirth(dateOfBirth) {}


	istream& operator>>(istream& in, Person& p)
	{
		cout << "Enter Name: ";
		getline(in, p.name);

		cout << "Enter Surname: ";
		getline(in, p.surname);

		cout << "Enter Birth date\n";
		in >> p.dateOfBirth;

		in.ignore();

		return in;
	}


}

