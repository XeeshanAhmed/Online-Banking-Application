#pragma once


class UserClient {
private:
	int userid;
	string address;
	string name;
	string cnic;
	string login_id;
	string password;
	long long int withdrawl_limit;
	Card card;
	Account* account;
	Transaction transaction;
public:
	UserClient()
	{
		userid = 1;
		account = NULL;
	}
	int getUserId()
	{
		return userid;
	}
	string getaddress()
	{
		return address;
	}
	string getname()
	{
		return name;
	}
	string getcnic()
	{
		return cnic;
	}
	string getid()
	{
		return login_id;
	}
	string getpassword()
	{
		return password;
	}
	long long int getlimit()
	{
		return withdrawl_limit;
	}
	void register_user()
	{
		fstream inout, inout2;
		string line;
		inout.open("users.txt", ios::in);
		inout2.open("companies.txt", ios::in);
		if (inout.is_open())
		{
			while (getline(inout, line))
			{
				userid++;
			}
		}
		if (inout2.is_open())
		{
			while (getline(inout2, line))
			{
				userid++;
			}
		}
		inout2.close();
		inout.close();
		cin.ignore();
		cout << "Enter address : ";
		getline(cin, address);
		cout << "Enter name : ";
		getline(cin, name);
		cout << "Enter cnic : ";
		cin >> cnic;
		cout << "Enter login id : ";
		cin >> login_id;
		cout << "Enter password : ";
		cin >> password;
		cout << "Enter estimated withdrawal limit : ";
		cin >> withdrawl_limit;
		inout.open("users.txt", ios::out | ios::app);
		inout << userid << "," << name << "," << address << "," << cnic << "," << login_id << "," << password << endl;
		inout.close();
	label:
		if (withdrawl_limit <= 100000)
		{
			account = new Bronze();
			inout.open("accounts.txt", ios::out | ios::app);
			inout << userid << " " << account->getWithdarawlLimit() << " " << account->getAccountType() << endl;
			inout.close();
		}
		else if (withdrawl_limit <= 500000)
		{
			account = new Gold();
			inout.open("accounts.txt", ios::out | ios::app);
			inout << userid << " " << account->getWithdarawlLimit() << " " << account->getAccountType() << endl;
			inout.close();
		}
		else
		{
			cout << "Sorry withdrawal limit for user account cannot exceed 500000 pkr" << endl;
			cin >> withdrawl_limit;
			goto label;
		}
		card.setcard();
		cout << "Your card number is : " << card.getcard() << endl;;
		card.setpin();
		inout.open("cards.txt", ios::out | ios::app);
		inout << userid << " " << card.getcard() << " " << card.getpin() << endl;
		inout.close();
		inout.open("balance.txt", ios::out | ios::app);
		inout << userid << " " << transaction.getBalance() << endl;
		inout.close();
		cout << "Registration Successful" << endl;
	}
	void login_user()
	{
		fstream inout;
		string loginid, pass;
		bool flag = false;
		cout << "Enter login id : ";
		cin >> loginid;
		cout << "Enter password : ";
		cin >> pass;
		inout.open("users.txt", ios::in);
		string line;
		while (getline(inout, line)) {
			size_t pos = 0;
			string value;
			int count = 0;
			while ((pos = line.find(",")) != string::npos) {
				value = line.substr(0, pos);

				switch (count) {
				case 0:
					userid = stoi(value);
					break;
				case 1:
					name = value;
					break;
				case 2:
					address = value;
					break;
				case 3:
					cnic = value;
					break;
				case 4:
					login_id = value;
					break;
				case 5:
					password = value;
					break;
				}

				line.erase(0, pos + 1);
				count++;
			}
			if (count == 5) {
				password = line;
			}
			if (loginid == login_id)
			{
			label:
				if (password == pass)
				{
					flag = true;
					cout << "login successful " << endl;
					cout << userid << endl;
					card.readCard(userid);
					cout << "card readed" << endl;
					transaction.readBalance(userid);
					cout << "balance readed" << endl;
					inout.open("accounts.txt", ios::in);
					int id;
					while (inout >> id)
					{
						if (id == userid)
						{
							inout >> withdrawl_limit;
							cout << "yahan tk aye ho ?" << endl;
						}
						else
						{
							continue;
						}
					}
					inout.close();
					cout << "Account assigned" << endl;
					if (withdrawl_limit <= 100000)
					{
						account = new Bronze();
					}
					else if (withdrawl_limit <= 500000)
					{
						account = new Gold();
					}
					cout << "login successful" << endl;
				}
				else
				{
					cout << "Incorrect password " << endl;
					cout << "Enter correct password: ";
					cin >> pass;
					goto label;
					return;
				}
			}
			else
			{
				continue;
			}
		}
		inout.close();
		if (!flag)
		{
			cout << "Incorrect login id " << endl;
			getchar();
			system("cls");
			login_user();
		}

	}
	void deposit()
	{
		transaction.deposit(userid, card.getpin());
	}
	void withdraw()
	{
		transaction.withdraw(userid, card.getpin(), account->getWithdarawlLimit());
	}
	void transfer()
	{
		transaction.transfer(userid, card.getpin());
	}
	void viewTransactionHistory()
	{
		string line;
		fstream inout;
		char id[2];
		inout.open("Transactions.txt", ios::in);
		while (getline(inout, line))
		{
			int j = 0;
			for (int i = 11; line[i] != ' '; i++)
			{
				id[j] = line[i];
				j++;
			}
			id[j] = '\0';
			if (userid == stoi(id))
			{
				cout << line << endl;
			}
		}
		inout.close();

	}
	void checkBalance()
	{
		cout << "Pkr : ";
		cout << transaction.getBalance() << endl;
	}
	~UserClient()
	{
		delete account;
		account = nullptr;
	}

};