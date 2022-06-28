#pragma once

namespace HeaderFiles
{
	void start()
	{
		int command = 0;
		int index = -1;
		bool isGuest = 0;
		bool isAdmin = 0;
		bool exit = 0;
		bool back = 0;
		Order newOrder;
		Product newProduct;
		ProductItem newProductitem;
		LogIn log;

		Product p1("Samsung s22 Ultra", "Green", "Best Samsung flagman in 2022", 3099.9);
		Product p2("Acer A3", "Black", "Laptop for meduim Budget", 1899.9);
		Product p3("Xiaomi Black Shark 4", "Green&Black", "Best phone for gaming", 2199.9);

		ProductItem pi1(&p1, 100);
		ProductItem pi2(&p2, 30);
		ProductItem pi3(&p2, 50);
		ProductItem temp;


		Customer c1("KillerVasif", "vasif123", "Vasif", "Babazade", Date(10, 2, 2004));
		Customer c2("AliShamil", "ali123", "Ali", "Shamilzade", Date(13, 6, 2005));
		Admin a1("KepaMax", "kepa123", "Kenan", "Muradov", Date(29, 8, 2004));

		Database db;
		db.admins.push_back(a1);
		db.customers.push_back(c1);
		db.customers.push_back(c2);

		db.productsItems.push_back(pi1);
		db.productsItems.push_back(pi2);
		db.productsItems.push_back(pi3);


		cout << "Welcome to Kepa Online shop\n";

		while (!exit)
		{

			back = 0;
			system("cls");
			cout << "1) Log in\n"
				<< "2) Continue as Guest\n"
				<< "0) Exit\n";

			cin >> command;
			cin.ignore();

			switch (command)
			{
			case 1:
				cin >> log;
				try
				{
					if (log.isAdmin)
						db.checkAdmin(log);

					else
						db.checkCustomer(log);
				}
				catch (const std::exception&)
				{
					cout << "\nUsername or password is incorrect!\n";
					continue;
				}
				isAdmin = log.isAdmin;
				break;

			case 2:
				isGuest = true;
				break;

			case 0:

				cout << "Good Bye\n";
				exit = true;
				back = true;
				break;

			default:
				cout << "Unkown command\n";

			}

			while (!back)
			{
				system("cls");


				if (isAdmin)
				{
					cout << "\n What do you want?\n"
						<< "1) Add product\n"
						<< "2) Update Product\n"
						<< "3) Delete Product by id\n"
						<< "0) Go back\n";

					cin >> command;
					cin.ignore();

					switch (command)
					{
					case 1:
						cout << "Enter Product info\n";
						cin >> newProduct;
						cout << "\nEnter quantity\n";
						cin >> command;
						cin.ignore();
						cout << "Old count: " << db.productsItems.size() << endl;
						try
						{
							db.addProduct(ProductItem(&newProduct, command));

						}
						catch (const std::exception&)
						{
							cout << "Products Wasnt made\n";
							system("pause");
							continue;
						}

						cout << "New count: " << db.productsItems.size() << endl;

						system("pause");
						break;

					case 2:
						for (size_t i = 0; i < db.productsItems.size(); i++)
						{
							cout << db.productsItems[i] << endl;
						}

						cout << "Enter Product info\n";
						cin >> newProduct;
						cout << "\nEnter quantity\n";
						cin >> command;
						cin.ignore();

						newProductitem = move(ProductItem(&newProduct, command));
						cout << "\nEnter Old product id\n";
						cin >> command;
						cin.ignore();

						try
						{
							db.UpdateProduct(command, newProductitem);
						}
						catch (const std::exception&)
						{
							cout << "Product not found\n";
							system("pause");
							continue;
						}

						system("pause");
						break;

					case 3:
						for (size_t i = 0; i < db.productsItems.size(); i++)
						{
							cout << db.productsItems[i] << endl;
						}

						cout << "\nEnter Product id\n";
						cin >> command;
						cin.ignore();

						try
						{
							db.deleteProduct(command);
						}
						catch (const std::exception&)
						{
							cout << "Product not found";
							system("pause");
							continue;
						}

						system("pause");
						break;

					case 0:
						back = true;
						break;

					default:

						cout << "Unknown Command\n";
						system("pause");
					}
				}
				else
				{


					cout << "\n What do you want?\n"
						<< "1) See al products\n"
						<< "2) See full info of product by id\n"
						<< "3) Add product to order\n"
						<< "4) Accept order\n"
						<< "0) Go back\n";

					cin >> command;
					cin.ignore();

					switch (command)
					{
					case 1:

						cout << "\n\n======Products======\n";
						for (size_t i = 0; i < db.productsItems.size(); i++)
						{

							cout << db.productsItems[i] << endl;
						}
						cout << "\n======End======\n";

						system("pause");
						break;

					case 2:

						cout << "\nEnter Product id: ";
						cin >> command;
						cin.ignore();

						try
						{
							db.seeProduct(command);
						}
						catch (const std::exception&)
						{
							cout << "Product with this id not found\n";
							system("pause");
							continue;
						}
						system("pause");
						break;

					case 3:


						if (isGuest)
						{
							cout << "You have to sign in to buy in our shop\n";
							system("pause");
							continue;
						}

						cout << "\nEnter Product id: ";
						cin >> command;
						cin.ignore();

						try
						{
							index = db.getProductIndexById(command);
						}
						catch (const std::exception&)
						{
							cout << "Product not found\n";
							system("pause");
							continue;
						}
						cout << "Current Count: " << db.productsItems[index].quantity << endl;

						cout << "Enter count: ";
						cin >> command;

						if (command <= 0 || command > db.productsItems[index].quantity)
						{
							cout << "Entered invalid number";
							system("pause");
							continue;
						}

						db.productsItems[index].quantity -= command;
						cout << "Remaining Count: " << db.productsItems[index].quantity << endl;

						newOrder.addToOrder(db.productsItems[index].product, command);

						system("pause");
						break;

					case 4:

						if (isGuest)
						{
							cout << "You have to sign in to buy in our shop\n";
							system("pause");
							continue;
						}

						if (newOrder.finalPrice() == 0)
						{
							cout << "There are no products in your basket\n";
							system("pause");
							continue;
						}

						cout << newOrder;
						cout << "\nHave a good day";

						db.orders.push_back(newOrder);

						system("pause");
						break;

					case 0:

						back = true;
						break;

					default:
						cout << "Unknown Command\n";
						system("pause");

					}
				}
			}
		}
	}

}



