#pragma once


namespace HeaderFiles::Products
{
	using namespace HeaderFiles::Helpers;

	class ProductItem
	{
	private:
		static int _staticId;
	public:

		int id = 0;
		Product* product = nullptr;
		int quantity = 0;

		ProductItem() : id(++_staticId) {}
		ProductItem(Product* p, int quantity);
		ProductItem(ProductItem&& ohter) noexcept;
		ProductItem(const ProductItem& ohter);

		ProductItem& operator=(ProductItem&& other) noexcept;
		ProductItem& operator=(const ProductItem& other);

		double totalPrice();


	};

	int ProductItem::_staticId = 0;

#pragma region CONSTRUCTORS

	ProductItem::ProductItem(Product* p, int quantity)
		: id(++_staticId), product(p), quantity(quantity) {}

	ProductItem::ProductItem(const ProductItem& other)
	{
		id = other.id;
		product = new Product(*other.product);
		quantity = other.quantity;
	}

	ProductItem::ProductItem(ProductItem&& other) noexcept
	{
		id = other.id;
		product = other.product;
		other.product = nullptr;
		quantity = other.quantity;
	}

#pragma endregion




#pragma region OPERATORS

	ProductItem& ProductItem::operator=(const ProductItem& other)
	{
		id = other.id;
		product = new Product(*other.product);
		quantity = other.quantity;

		return *this;
	}

	ProductItem& ProductItem::operator=(ProductItem&& other) noexcept
	{
		id = other.id;
		product = other.product;
		other.product = nullptr;
		quantity = other.quantity;

		return *this;
	}

	ostream& operator<<(ostream& out, const ProductItem& p)
	{
		out << "Id: " << p.id << endl
			<< "Name: " << p.product->name << endl
			<< "Quantity: " << p.quantity << endl;

		return out;
	}

#pragma endregion

	double ProductItem::totalPrice()

	{
		if (product)
			return product->price * quantity;

		throw Exception("Product Doesnt exists", ctime(callLocalTime()));
	}

}




