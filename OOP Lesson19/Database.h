#pragma once

namespace HeaderFiles
{
	using namespace HeaderFiles::Helpers;
	using namespace HeaderFiles::People;
	using namespace HeaderFiles::Products;

	class Database
	{
	public:

		vector<ProductItem> productsItems;
		vector<Admin> admins;
		vector<Customer> customers;
		vector<Order> orders;

		void checkCustomer(const LogIn& customer);
		void checkAdmin(const LogIn& admin);
		void addProduct(const ProductItem product);
		void UpdateProduct(int id, const ProductItem& product);
		void deleteProduct(int id);
		void seeProduct(int id);
		size_t getProductIndexById(int id);
	};

#pragma region METHODS

	void Database::checkCustomer(const LogIn& customer)
	{
		cout << customer.username << endl;
		cout << customer.password << endl;

		for (size_t i = 0; i < customers.size(); i++)
		{
			if (customers[i].username == customer.username)
			{
				cout << customers[i].username << endl;
				cout << customers[i].password << endl;

				if (customers[i].password == customer.password)
					return;

				throw Exception("Password is not correct", ctime(callLocalTime()));
			}
		}
		throw Exception("Username is not found", ctime(callLocalTime()));
	}

	void Database::checkAdmin(const LogIn& admin)
	{
		for (size_t i = 0; i < customers.size(); i++)
		{
			if (admins[i].username == admin.username)
			{
				if (admins[i].password == admin.password)
					return;

				throw Exception("Password is not correct", ctime(callLocalTime()));
			}
			throw Exception("Username is not found", ctime(callLocalTime()));
		}
	}

	void Database::addProduct(const ProductItem productItem)
	{

		for (size_t i = 0; i < productsItems.size(); i++)
		{
			if (productsItems[i].product->name == productItem.product->name)
			{
				productsItems[i].quantity += productItem.quantity;
				return;
			}
		}


		if (productItem.product)
		{
			productsItems.push_back(productItem);
			return;
		}

		throw Exception("Product doesnt even exists", ctime(callLocalTime()));
	}

	void Database::UpdateProduct(int id, const ProductItem& newProduct)
	{
		for (size_t i = 0; i < productsItems.size(); i++)
		{
			if (productsItems[i].id == id)
				productsItems[i] = newProduct;
		}

		throw Exception("Product not found", ctime(callLocalTime()));
	}

	void Database::deleteProduct(int id)
	{
		size_t i = 0;
		for (; i < productsItems.size(); i++)
		{
			if (productsItems[i].id == id)
			{
				productsItems.erase(productsItems.begin() + i);
				return;
			}
		}

		throw Exception("Product not found", ctime(callLocalTime()));
	}

	void Database::seeProduct(int id)
	{
		for (size_t i = 0; i < productsItems.size(); i++)
		{
			if (productsItems[i].id == id)
			{
				cout << *productsItems[i].product;
				return;
			}
		}

		throw Exception("Product not found", ctime(callLocalTime()));
	}

	size_t Database::getProductIndexById(int id)
	{
		size_t i = 0;
		for (; i < productsItems.size(); i++)
		{
			if (productsItems[i].id == id)
			{
				return i;
			}
		}

		throw Exception("Product not found", ctime(callLocalTime()));
	}

#pragma endregion



}

