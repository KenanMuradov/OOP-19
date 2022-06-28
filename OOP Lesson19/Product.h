#pragma once
namespace HeaderFiles::Products
{
	using namespace HeaderFiles::Helpers;

	class Product
	{
	private:

		static int _staticId;

	public:

		int id = 0;
		string name = "";
		string description = "";
		string color = "";
		double price = 0;



		Product() {
			id = ++_staticId;
		}

		Product(string name, string color, string description, double price);


	};

	int Product::_staticId = 0;

	Product::Product(string name, string color, string description, double price)
		: id(++_staticId), name(name), color(color), description(description), price(price) {}

	ostream& operator<<(ostream& out, const Product& p)
	{
		out << "Id: " << p.id << endl
			<< "Name: " << p.name << endl
			<< "Color: " << p.color << endl
			<< "Description: " << p.description << endl
			<< "Price: " << p.price << endl;

		return out;
	}


	istream& operator>>(istream& in, Product& p)
	{
		cout << "Enter product name: ";
		getline(in, p.name);

		cout << "Enter product color: ";
		getline(in, p.color);

		cout << "Enter product description: ";
		getline(in, p.description);

		cout << "Enter product price: ";
		in >> p.price;
		in.ignore();

		return in;
	}

}

	