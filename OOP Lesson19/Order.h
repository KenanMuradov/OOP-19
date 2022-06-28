#pragma once


namespace HeaderFiles
{
	using namespace HeaderFiles::Helpers;
	using namespace HeaderFiles::People;
	using namespace HeaderFiles::Products;
	class Order
	{
	public:
		vector<ProductItem> productItem;
		int customerId = 0;
		Date dateTime;

		Order()
		{
			dateTime = Date(currentDate->tm_mday, currentDate->tm_mon + 1, currentDate->tm_year + 1900);
		}

		Order(int id) : customerId(id)
		{
			dateTime = Date(currentDate->tm_mday, currentDate->tm_mon + 1, currentDate->tm_year + 1900);
		}


		double finalPrice() const;
		void addToOrder(Product* p, int quantity);

	};


	ostream& operator<<(ostream& out, const Order& o)
	{
		out << "Customer Id: " << o.customerId << endl
			<< "Ordered Products\n";
		for (size_t i = 0; i < o.productItem.size(); i++)
		{
			out << '\t' << o.productItem[i] << endl;
		}
		out << "End\n";

		out << "Final Price: " << o.finalPrice() << endl;
		return out;
	}


	double Order::finalPrice() const
	{
		double sum = 0;

		for (size_t i = 0; i < productItem.size(); i++)
		{
			sum += productItem[i].product->price * productItem[i].quantity;
		}

		return sum;
	}

	void Order::addToOrder(Product* p, int quantity)
	{
		for (size_t i = 0; i < productItem.size(); i++)
		{
			if (productItem[i].product->id == p->id)
			{
				productItem[i].quantity += quantity;
				return;
			}
		}
		ProductItem newProductItem(p, quantity);

		productItem.push_back(newProductItem);
	}

}

