#include <iostream>
#include <conio.h>
using namespace std;


int numGames = 0;
int numConsoles = 0;
int numMonitors = 0;
int numHeadsets = 0;
int numShoppingCart = 0;
int ValueCustomer = 0;
int ValueGamingShop = 0;
int numCartConsoles = 0;
int numCartMonitors = 0;
int numCartHeadsets = 0;
int numCartGames = 0;
int z;
string NameSearch;


struct Products
{
	string name;
	int type;
	int price;
	int inventory;
};

Products* games = nullptr;
Products* Consoles = nullptr;
Products* Monitors = nullptr;
Products* Headsets = nullptr;
Products* Shopping_Cart_Item = nullptr;


 // comment
void Payment(const string& name, int& ValueGamingShop, int& ValueCustomer)
{
	string RemoveCart;
	int valuepay = 0;
	int ShowBuy;
	cout << "Please select your option‌ ( 1: Pay  /  2: Show cart items   /  3: Remove the product from the basket )" << endl << "YourWallet balance : " << ValueCustomer << endl;
	cin >> ShowBuy;
	switch (ShowBuy)
	{
	case 1:
		if (numCartGames == 0 && numCartConsoles == 0 && numCartMonitors == 0 && numCartHeadsets == 0)
		{
			cout << "There are no item in Cart.\n";
		}
		else
		{
			for (int i = 0; i < numShoppingCart; i++)
			{
				valuepay += (Shopping_Cart_Item + i)->price * (Shopping_Cart_Item + i)->inventory;
			}
			ValueGamingShop += valuepay;
			ValueCustomer -= valuepay;
			numShoppingCart = 0;
			numCartGames = 0;
			numCartConsoles = 0;
			numCartMonitors = 0;
			numCartHeadsets = 0;
			delete[] Shopping_Cart_Item;
			Shopping_Cart_Item = NULL;
			cout << "Successful transaction.\n";
		}
		return;
		break;
	case 2:
		if (numCartGames == 0 && numCartConsoles == 0 && numCartMonitors == 0 && numCartHeadsets == 0)
		{
			cout << "There are no item in Cart.\n";
		}
		else
		{
			for (int i = 0; i < numShoppingCart; i++)
			{
				cout << "Product " << i + 1 << ":" << endl;
				cout << "  Type: " << (Shopping_Cart_Item[i].type == 1 ? "Console" : Shopping_Cart_Item[i].type == 2 ? "Monitor" : Shopping_Cart_Item[i].type == 3 ? "Headset" : "Game") << endl;
				cout << "  Name: " << Shopping_Cart_Item[i].name << endl;
				cout << "  Price: " << Shopping_Cart_Item[i].price << endl;
				cout << "  inventory: " << Shopping_Cart_Item[i].inventory << endl;
			}
			return;
		}
		break;
	case 3:
		if (numShoppingCart == 0)
		{
			cout << "There are no products to remove from the cart! \n\n";
			return;
		}
		else
		{
			for (int i = 0; i < numShoppingCart; i++)
			{
				cout << "Product " << i + 1 << ":" << endl;
				cout << "  Type: " << (Shopping_Cart_Item[i].type == 1 ? "Console" : Shopping_Cart_Item[i].type == 2 ? "Monitor" : Shopping_Cart_Item[i].type == 3 ? "Headset" : "Game") << endl;
				cout << "  Name: " << Shopping_Cart_Item[i].name << endl;
				cout << "  Price: " << Shopping_Cart_Item[i].price << endl;
				cout << "  inventory: " << Shopping_Cart_Item[i].inventory << endl;
			}

			int choice;
			cout << "Please enter the INDEX of the item you want to remove from the cart(start from 1): " << endl;
			cin >> choice;

			if (choice > numShoppingCart)
			{
				cout << "Invalid index!" << endl;
				return;
			}

			Products selectedItem = Shopping_Cart_Item[choice - 1];
			// Its Console
			if (selectedItem.type == 1)
			{
				for (int j = 0; j < numConsoles; j++)
				{
					if (Consoles[j].name == selectedItem.name)
					{
						Consoles[j].inventory++;
					}
				}
			}
			//Its Monitor
			else if (selectedItem.type == 2)
			{
				for (int j = 0; j < numMonitors; j++)
				{
					if (Monitors[j].name == selectedItem.name)
					{
						Monitors[j].inventory++;
					}
				}
			}
			//Its Headset
			else if (selectedItem.type == 3)
			{
				for (int j = 0; j < numHeadsets; j++)
				{
					if (Headsets[j].name == selectedItem.name)
					{
						Headsets[j].inventory++;
					}
				}
			}
			//Its Game
			else if (selectedItem.type == 4)
			{
				for (int j = 0; j < numGames; j++)
				{
					if (games[j].name == selectedItem.name)
					{
						games[j].inventory++;
					}
				}
			}

			Shopping_Cart_Item[choice-1].inventory--;
			if (Shopping_Cart_Item[choice - 1].inventory == 0)
			{			
				// We must remove item from basket
				for (int k = choice - 1; k < numShoppingCart - 1; k++)
				{
					Shopping_Cart_Item[k] = Shopping_Cart_Item[k + 1];
				}
				numShoppingCart--;
			}
			cout << "The desired item was removed from the basket !\n\n";
		}
		return;
		break;
	}
}
void Shopping_Cart(const string& search, const string& name, int* ValueGamingShop, int* ValueCustomer);
void AddProduct()
{
	int x;
	cout << "Please choose type of product (choice number) :" << endl;
	cout << "1: Console" << endl;
	cout << "2: Monitor" << endl;
	cout << "3: Headset" << endl;
	cout << "4: Game" << endl;
	cin >> x;
	switch (x)
	{
	case 1:
	{
		string pName;
		cout << "Enter console name: ";
		cin >> pName;
		for (int i = 0; i < numConsoles; ++i)
		{
			if (Consoles[i].name == pName)
			{
				cout << "Already Exist" << endl;
				return;
			}
		}

		Products* newConsoles = new Products[numConsoles + 1];
		// کپی کردن کنسول های قبلی به داخل آرایه جدید
		for (int i = 0; i < numConsoles; ++i)
		{
			newConsoles[i] = Consoles[i];
		}
		//حذف آرایه قدیمی
		delete[] Consoles;
		//افزودن کنسول جدید به آرایه جدید
		newConsoles[numConsoles].type = x;
		newConsoles[numConsoles].name = pName;
		cout << "Enter console price: ";
		cin >> newConsoles[numConsoles].price;
		cout << "Enter console inventory: ";
		cin >> newConsoles[numConsoles].inventory;
		cout << endl;
		// ایجاد آرایه جدید
		Consoles = newConsoles;
		// افزودن سایز آرایه داینامیک برای دفعات بعدی اضافه کردن
		numConsoles++;
		cout << "The product has been successfully added.\n";
		break;
	}
	case 2:
	{
		string pName;
		cout << "Enter Monitor name: ";
		cin >> pName;
		for (int i = 0; i < numMonitors; ++i)
		{
			if (Monitors[i].name == pName)
			{
				cout << "Already Exist" << endl;
				return;
			}
		}
		Products* newMonitors = new Products[numMonitors + 1];
		// کپی کردن مانیتور های قبلی به داخل آرایه جدید
		for (int i = 0; i < numMonitors; ++i)
		{
			newMonitors[i] = Monitors[i];
		}
		//حذف آرایه قدیمی
		delete[] Monitors;
		//افزودن مانیتور جدید به آرایه جدید
		newMonitors[numMonitors].type = x;
		newMonitors[numMonitors].name = pName;
		cout << "Enter monitor price: ";
		cin >> newMonitors[numMonitors].price;
		cout << "Enter monitor inventory: ";
		cin >> newMonitors[numMonitors].inventory;
		cout << endl;
		// ایجاد آرایه جدید
		Monitors = newMonitors;
		// افزودن سایز آرایه داینامیک برای دفعات بعدی اضافه کردن
		numMonitors++;
		cout << "The product has been successfully added.\n";
		break;
	}
	case 3:
	{
		string pName;
		cout << "Enter headset name: ";
		cin >> pName;
		for (int i = 0; i < numHeadsets; ++i)
		{
			if (Headsets[i].name == pName)
			{
				cout << "Already Exist" << endl;
				return;
			}
		}
		Products* newHeadsets = new Products[numHeadsets + 1];
		// کپی کردن هدست های قبلی به داخل آرایه جدید
		for (int i = 0; i < numHeadsets; ++i)
		{
			newHeadsets[i] = Headsets[i];
		}
		//حذف آرایه قدیمی
		delete[] Headsets;
		//افزودن هدست جدید به آرایه جدید
		newHeadsets[numHeadsets].type = x;
		newHeadsets[numHeadsets].name = pName;
		cout << "Enter headset price: ";
		cin >> newHeadsets[numHeadsets].price;
		cout << "Enter headset inventory: ";
		cin >> newHeadsets[numHeadsets].inventory;
		cout << endl;
		// ایجاد آرایه جدید
		Headsets = newHeadsets;
		// افزودن سایز آرایه داینامیک برای دفعات بعدی اضافه کردن
		numHeadsets++;
		cout << "The product has been successfully added.\n";
		break;
	}
	case 4:
		string pName;
		cout << "Enter game name: ";
		cin >> pName;
		for (int i = 0; i < numGames; ++i)
		{
			if (games[i].name == pName)
			{
				cout << "Already Exist" << endl;
				return;
			}
		}
		Products* newGames = new Products[numGames + 1];
		// کپی کردن بازی های قبلی به داخل آرایه جدید
		for (int i = 0; i < numGames; ++i)
		{
			newGames[i] = games[i];
		}
		//حذف آرایه قدیمی
		delete[] games;
		//افزودن بازی جدید به آرایه جدید
		newGames[numGames].type = x;
		newGames[numGames].name = pName;
		cout << "Enter game price: ";
		cin >> newGames[numGames].price;
		cout << "Enter game inventory: ";
		cin >> newGames[numGames].inventory;
		cout << endl;
		// ایجاد آرایه جدید
		games = newGames;
		// افزودن سایز آرایه داینامیک برای دفعات بعدی اضافه کردن
		numGames++;
		cout << "The game has been successfully added.\n";
		break;
	}
}

void RemoveGame_And_Product(const string& name, int x)
{
	switch (x)
	{
	case 1:
		for (int i = 0; i < numConsoles; i++)
		{
			if (Consoles[i].name == name)
			{
				for (int j = i; j < numConsoles - 1; j++)
				{
					Consoles[j] = Consoles[j + 1];
				}
				numConsoles--;
				cout << "The product was successfully deleted.\n";
				return;
			}
		}
		cout << "Product not found.\n";
		break;
	case 2:
		for (int i = 0; i < numMonitors; i++)
		{
			if (Monitors[i].name == name)
			{
				for (int j = i; j < numMonitors - 1; j++)
				{
					Monitors[j] = Monitors[j + 1];
				}
				numMonitors--;
				cout << "The product was successfully deleted.\n";
				return;
			}
		}
		cout << "Product not found.\n";
		break;
	case 3:
		for (int i = 0; i < numHeadsets; i++)
		{
			if (Headsets[i].name == name)
			{
				for (int j = i; j < numHeadsets - 1; j++)
				{
					Headsets[j] = Headsets[j + 1];
				}
				numHeadsets--;
				cout << "The product was successfully deleted.\n";
				return;
			}
		}
		cout << "Product not found.\n";
		break;
	case 4:
		for (int i = 0; i < numGames; i++)
		{
			if (games[i].name == name)
			{
				for (int j = i; j < numGames - 1; j++)
				{
					games[j] = games[j + 1];
				}
				numGames--;
				cout << "The game was successfully deleted.\n";
				return;
			}
		}
		cout << "Game not found.\n";
		break;
	}
}
void SearchGame(const string& name)
{
	string NameSearch;
	cout << "Please choose type of product or game (choice number) :" << endl;
	cout << "1: Console" << endl;
	cout << "2: Monitor" << endl;
	cout << "3: Headset" << endl;
	cout << "4: Game" << endl;
	cin >> z;
	switch (z)
	{
	case 1:
		if (numConsoles > 0)
		{
			cout << "Please enter name :" << endl;
			cin >> NameSearch;
			for (int i = 0; i < numConsoles; i++)
			{
				if (Consoles[i].name == NameSearch)
				{
					cout << "Console Name: " << Consoles[i].name << endl;
					cout << "Price: " << Consoles[i].price << endl;
					cout << "inventory: " << Consoles[i].inventory << endl;
					cout << "1: Add to Shopping cart   /   2: Back" << endl;
					int b;
					cin >> b;
					if (b == 1)
					{
						Shopping_Cart(NameSearch, name, &ValueGamingShop, &ValueCustomer);
						return;
					}
					else if (b == 2)
					{
						return;
					}
				}
			}
		}
		else
		{
			cout << "Console not found.\n";
		}
		break;
	case 2:
		if (numMonitors > 0)
		{
			cout << "Please enter name :" << endl;
			cin >> NameSearch;
			for (int i = 0; i < numMonitors; i++)
			{
				if (Monitors[i].name == NameSearch)
				{
					cout << "Monitor Name: " << Monitors[i].name << endl;
					cout << "Price: " << Monitors[i].price << endl;
					cout << "inventory: " << Monitors[i].inventory << endl;
					cout << "1: Add to Shopping cart   /   2: Back" << endl;
					int b;
					cin >> b;
					if (b == 1)
					{
						Shopping_Cart(NameSearch, name, &ValueGamingShop, &ValueCustomer);
						return;
					}
					else if (b == 2)
					{
						return;
					}
				}
			}
		}
		else
		{
			cout << "Monitor not found.\n";
		}
		break;
	case 3:
		if (numHeadsets > 0)
		{
			cout << "Please enter name :" << endl;
			cin >> NameSearch;
			for (int i = 0; i < numHeadsets; i++)
			{
				if (Headsets[i].name == NameSearch)
				{
					cout << "Headset Name: " << Headsets[i].name << endl;
					cout << "Price: " << Headsets[i].price << endl;
					cout << "inventory: " << Headsets[i].inventory << endl;
					cout << "1: Add to Shopping cart   /   2: Back" << endl;
					int b;
					cin >> b;
					if (b == 1)
					{
						Shopping_Cart(NameSearch, name, &ValueGamingShop, &ValueCustomer);
						return;
					}
					else if (b == 2)
					{
						return;
					}
				}
			}
		}
		else
		{
			cout << "Headset not found.\n";
		}
		break;
	case 4:
		if (numGames > 0)
		{
			cout << "Please enter name :" << endl;
			cin >> NameSearch;
			for (int i = 0; i < numGames; i++)
			{
				if (games[i].name == NameSearch)
				{
					cout << "Game Name: " << games[i].name << endl;
					cout << "Price: " << games[i].price << endl;
					cout << "inventory: " << games[i].inventory << endl;
					cout << "1: Add to Shopping cart   /   2: Back" << endl;
					int b;
					cin >> b;
					if (b == 1)
					{
						Shopping_Cart(NameSearch, name, &ValueGamingShop, &ValueCustomer);
						return;
					}
					else if (b == 2)
					{
						return;
					}
				}
			}
		}
		else
		{
			cout << "Game not found.\n";
		}
		break;
	}
}

void ShowInformations()
{
	if (numGames == 0 && numConsoles == 0 && numMonitors == 0 && numHeadsets == 0)
	{
		cout << "There are no item in stock.\n";
	}
	else
	{
		for (int i = 0; i < numGames; i++)
		{
			cout << "Game " << i + 1 << ":" << endl;
			cout << "  Name: " << games[i].name << endl;
			cout << "  Price: " << games[i].price << endl;
			cout << "  inventory: " << games[i].inventory << endl << endl;
		}
		cout << "\n";

		for (int i = 0; i < numConsoles; i++)
		{
			cout << "Console " << i + 1 << ":" << endl;
			cout << "  Name: " << Consoles[i].name << endl;
			cout << "  Price: " << Consoles[i].price << endl;
			cout << "  inventory: " << Consoles[i].inventory << endl << endl;
		}
		cout << "\n";

		for (int i = 0; i < numMonitors; i++)
		{
			cout << "Monitor " << i + 1 << ":" << endl;
			cout << "  Name: " << Monitors[i].name << endl;
			cout << "  Price: " << Monitors[i].price << endl;
			cout << "  inventory: " << Monitors[i].inventory << endl << endl;
		}
		cout << "\n";

		for (int i = 0; i < numHeadsets; i++)
		{
			cout << "Headset " << i + 1 << ":" << endl;
			cout << "  Name: " << Headsets[i].name << endl;
			cout << "  Price: " << Headsets[i].price << endl;
			cout << "  inventory: " << Headsets[i].inventory << endl << endl;
		}
		cout << "\n";

	}
}
int CalculateTotalValue()
{
	int totalValue = 0;
	for (int i = 0; i < numGames; i++)
	{
		totalValue += games[i].price * games[i].inventory;
	}
	for (int i = 0; i < numConsoles; i++)
	{
		totalValue += Consoles[i].price * Consoles[i].inventory;
	}
	for (int i = 0; i < numMonitors; i++)
	{
		totalValue += Monitors[i].price * Monitors[i].inventory;
	}
	for (int i = 0; i < numHeadsets; i++)
	{
		totalValue += Headsets[i].price * Headsets[i].inventory;
	}
	cout << "Total value Gaming Shop is : " << totalValue << "\n\n";
	return totalValue;
}
void Customers_Money_Management(int* ValueCustomer)
{
	int y, Money;
customer_value:
	cout << "Please select the desired activity. " << endl << endl << "1: Show Wallet balance" << endl << "2: Increase wallet balance" << endl << "3: Back" << endl;
	cin >> y;
	switch (y)
	{
	case 1:
		cout << *ValueCustomer << endl;
		goto customer_value;
		break;
	case 2:
		cout << "Enter the desired amount to increase cash:" << endl;
		cin >> Money;
		*ValueCustomer += Money;
		cout << "Inventory successfully increased !  Your account balance: " << *ValueCustomer << endl;
		goto customer_value;
		break;
	case 3:
		return;
		break;
	}
}

void GamingShop_Money_Management(int* ValueGamingShop)
{
	int  y, Money;
customer_value:
	cout << "Please select the desired activity. " << endl << endl << "1: Show Gaming Shop Wallet balance" << endl << "2: Increase Gaming Shop wallet balance" << endl << "3: Back" << endl;
	cin >> y;
	switch (y)
	{
	case 1:
		cout << *ValueGamingShop << endl;
		goto customer_value;
		break;
	case 2:
		cout << "Enter the amount of store cash increase:" << endl;
		cin >> Money;
		*ValueGamingShop += Money;
		cout << "Inventory successfully increased !  Gaming shop account balance: " << *ValueGamingShop << endl;
		goto customer_value;
		break;
	case 3:
		return;
		break;
	}
}

void Shopping_Cart(const string& NameSearch, const string& name, int* ValueGamingShop, int* ValueCustomer)
{
	switch (z)
	{
	case 1:
	{
		for (int j = 0; j < numShoppingCart; j++)
		{
			if (Shopping_Cart_Item[j].name == NameSearch && Shopping_Cart_Item[j].type == z)
			{
				for (int i = 0; i < numConsoles; i++)
				{
					if (Consoles[i].name == NameSearch)
					{
						if (Consoles[i].inventory > 0)
						{
							Consoles[i].inventory--;
						}
						else
						{
							cout << "Shop haven't this item" << endl;
							return;
						}
					}
				}
				Shopping_Cart_Item[j].inventory++;
				cout << "The product was successfully added.\n";
				return;
			}
		}

		for (int i = 0; i < numConsoles; i++)
		{
			if (Consoles[i].name == NameSearch)
			{
				if (Consoles[i].inventory > 0)
				{
					Products* newShoppingCartItem = new Products[numShoppingCart + 1];

					for (int j = 0; j < numShoppingCart; j++)
					{
						newShoppingCartItem[j] = Shopping_Cart_Item[j];
					}
					newShoppingCartItem[numShoppingCart] = Consoles[i];
					newShoppingCartItem[numShoppingCart].inventory = 1;
					numShoppingCart++;

					//حذف آرایه قدیمی
					delete[] Shopping_Cart_Item;
					numCartConsoles++;
					Shopping_Cart_Item = newShoppingCartItem;
					cout << "The product was successfully added.\n";
					Consoles[i].inventory--;

					return;
				}
				else
				{
					cout << "Shop haven't this item" << endl;
					return;
				}
			}
		}
	}
	break;
	case 2:
		for (int j = 0; j < numShoppingCart; j++)
		{
			if (Shopping_Cart_Item[j].name == NameSearch && Shopping_Cart_Item[j].type == z)
			{
				for (int i = 0; i < numMonitors; i++)
				{
					if (Monitors[i].name == NameSearch)
					{
						if (Monitors[i].inventory > 0)
						{
							Monitors[i].inventory--;
						}
						else
						{
							cout << "Shop haven't this item" << endl;
							return;
						}
					}
				}
				Shopping_Cart_Item[j].inventory++;
				cout << "The product was successfully added.\n";
				return;
			}
		}

		for (int i = 0; i < numMonitors; i++)
		{
			if (Monitors[i].name == NameSearch)
			{
				if (Monitors[i].inventory > 0)
				{
					Products* newShoppingCartItem = new Products[numShoppingCart + 1];

					for (int j = 0; j < numShoppingCart; j++)
					{
						newShoppingCartItem[j] = Shopping_Cart_Item[j];
					}
					newShoppingCartItem[numShoppingCart] = Monitors[i];
					newShoppingCartItem[numShoppingCart].inventory = 1;
					numShoppingCart++;

					//حذف آرایه قدیمی
					delete[] Shopping_Cart_Item;
					numCartMonitors++;
					Shopping_Cart_Item = newShoppingCartItem;
					cout << "The product was successfully added.\n";
					Monitors[i].inventory--;

					return;
				}
				else
				{
					cout << "Shop haven't this item" << endl;
					return;
				}
			}
		}
		break;
	case 3:
		for (int j = 0; j < numShoppingCart; j++)
		{
			if (Shopping_Cart_Item[j].name == NameSearch && Shopping_Cart_Item[j].type == z)
			{
				for (int i = 0; i < numHeadsets; i++)
				{
					if (Headsets[i].name == NameSearch)
					{
						if (Headsets[i].inventory > 0)
						{
							Headsets[i].inventory--;
						}
						else
						{
							cout << "Shop haven't this item" << endl;
							return;
						}
					}
				}
				Shopping_Cart_Item[j].inventory++;
				cout << "The product was successfully added.\n";
				return;
			}
		}

		for (int i = 0; i < numHeadsets; i++)
		{
			if (Headsets[i].name == NameSearch)
			{
				if (Headsets[i].inventory > 0)
				{
					Products* newShoppingCartItem = new Products[numShoppingCart + 1];

					for (int j = 0; j < numShoppingCart; j++)
					{
						newShoppingCartItem[j] = Shopping_Cart_Item[j];
					}
					newShoppingCartItem[numShoppingCart] = Headsets[i];
					newShoppingCartItem[numShoppingCart].inventory = 1;
					numShoppingCart++;

					//حذف آرایه قدیمی
					delete[] Shopping_Cart_Item;
					numCartHeadsets++;
					Shopping_Cart_Item = newShoppingCartItem;
					cout << "The product was successfully added.\n";
					Headsets[i].inventory--;

					return;
				}
				else
				{
					cout << "Shop haven't this item" << endl;
					return;
				}
			}
		}
		break;
	case 4:
		for (int j = 0; j < numShoppingCart; j++)
		{
			if (Shopping_Cart_Item[j].name == NameSearch && Shopping_Cart_Item[j].type == z)
			{
				for (int i = 0; i < numGames; i++)
				{
					if (games[i].name == NameSearch)
					{
						if (games[i].inventory > 0)
						{
							games[i].inventory--;
						}
						else
						{
							cout << "Shop haven't this item" << endl;
							return;
						}
					}
				}
				Shopping_Cart_Item[j].inventory++;
				cout << "The product was successfully added.\n";
				return;
			}
		}

		for (int i = 0; i < numGames; i++)
		{
			if (games[i].name == NameSearch)
			{
				if (games[i].inventory > 0)
				{
					Products* newShoppingCartItem = new Products[numShoppingCart + 1];

					for (int j = 0; j < numShoppingCart; j++)
					{
						newShoppingCartItem[j] = Shopping_Cart_Item[j];
					}
					newShoppingCartItem[numShoppingCart] = games[i];
					newShoppingCartItem[numShoppingCart].inventory = 1;
					numShoppingCart++;

					//حذف آرایه قدیمی
					delete[] Shopping_Cart_Item;
					numCartGames++;
					Shopping_Cart_Item = newShoppingCartItem;
					cout << "The product was successfully added.\n";
					games[i].inventory--;

					return;
				}
				else
				{
					cout << "Shop haven't this item" << endl;
					return;
				}
			}
		}
		break;
	}
}

int main(const string& name)
{
	string Password;
	int number;
	string Name;
	int choice;
	do {
	Roleـswitching:
		cout << "Please choose your identity with number ( 1: Administration /  2: Customers  /  3: Exit ) : ";
		cin >> number;
		if (number == 1)
		{
		TryAgain:
			Password = "";
			char ch;
			const char ENTER = 13;
			cout << "Please enter the password: ";
			while ((ch = _getch()) != ENTER)
			{
				if (ch != 8)
				{
					Password += ch;
					cout << '*';
				}
				else if (ch == 8 && Password.length() > 0)
				{
					Password.pop_back();
					cout << "\b \b";
				}
			}
			cout << "\n";
			if (Password == "admin1admin")
			{
			menu:
				cout << "1) AddProduct" << endl;
				cout << "2) RemoveGame_And_Product" << endl;
				cout << "3) ShowInformations" << endl;
				cout << "4) CalculateTotalValue" << endl;
				cout << "5) GamingShop_Money_Management" << endl;
				cout << "6) LogOut" << endl;
				cin >> choice;
				cout << endl;
				// نمایش منو و گرفتن انتخاب مدیر
				// ...
				switch (choice)
				{
				case 1:
					AddProduct();
					goto menu;
					// افزودن بازی
					break;
				case 2:
					int x;
					cout << "Please choose type of product or game (choice number) :" << endl;
					cout << "1: Console" << endl;
					cout << "2: Monitor" << endl;
					cout << "3: Headset" << endl;
					cout << "4: Game" << endl;
					cin >> x;
					cout << "Please write the name : ";
					cin >> Name;
					RemoveGame_And_Product(Name, x);
					goto menu;
					// حذف بازی
					break;
				case 3:
					ShowInformations();
					goto menu;
					break;
				case 4:
					CalculateTotalValue();
					goto menu;
					break;
				case 5:
					GamingShop_Money_Management(&ValueGamingShop);
					goto menu;
					break;
				case 6:
					goto Roleـswitching;
					break;
				}
			}
			else
			{
				cout << "your password is incorrect ! " << endl;
				cout << "(choose with number) \n 1: Back \n 2: Try Again ";
				int Back_continue;
				cin >> Back_continue;
				if (Back_continue == 2)
				{
					goto TryAgain;
				}
				else if (Back_continue == 1)
				{
					goto Roleـswitching;
				}
			}
		}
		else if (number == 2)
		{
		Customer:
			cout << "1) SearchGame ( buy game )" << endl;
			cout << "2) ShowInformations" << endl;
			cout << "3) Customers_Money_Management" << endl;
			cout << "4) Payment" << endl;
			cout << "5) LogOut" << endl;
			cin >> choice;
			cout << endl;
			// نمایش منو و گرفتن انتخاب کاربر
			// ...
			switch (choice)
			{
			case 1:
				SearchGame(name);
				goto Customer;
				break;
			case 2:
				ShowInformations();
				goto Customer;
				break;
			case 3:
				Customers_Money_Management(&ValueCustomer);
				goto Customer;
				break;
			case 4:
				Payment(name, ValueGamingShop, ValueCustomer);
				goto Customer;
				break;
			case 5:
				goto Roleـswitching;
				break;
			}
		}
		else if (number == 3)
		{ 
		return 0;
        }
	} while (choice != 0);
	return 0;
}