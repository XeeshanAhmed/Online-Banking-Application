#pragma once

class CompanyClient {
private:
	int companyid;
	string companyName;
	string companyAddress;
	string companyTax;
	string login_id;
	string password;
	long long int withdrawl_limit;
	Card card;
	Account* account;
	Transaction transaction;
public:
	CompanyClient()
	{
		companyid = 1;
		account = NULL;
	}
	int getcompanyid()
	{
		return companyid;
	}
	string getcompanyName()
	{
		return companyName;
	}
	string getcompanyAddress()
	{
		return companyAddress;
	}
	string getcompanyTax()
	{
		return companyTax;
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
	void createCompanyAccount()
	{
		fstream inout, inout2;
		string line;
		inout.open("users.txt", ios::in);
		inout2.open("companies.txt", ios::in);
		if (inout.is_open())
		{
			while (getline(inout, line))
			{
				companyid++;
			}
		}
		if (inout2.is_open())
		{
			while (getline(inout2, line))
			{
				companyid++;
			}
		}
		inout2.close();
		inout.close();
		cin.ignore();
		cout << "Enter company's name : ";
		getline(cin, companyName);
		cout << "Enter company's address : ";
		getline(cin, companyAddress);
		cout << "Enter company's tax number : ";
		cin >> companyTax;
		cout << "Enter login id : ";
		cin >> login_id;
		cout << "Enter password : ";
		cin >> password;
		cout << "Enter estimated withdrawal limit : ";
		cin >> withdrawl_limit;
		inout.open("companies.txt", ios::out | ios::app);
		inout << companyid << "," << companyName << "," << companyAddress << "," << companyTax << "," << login_id << "," << password << endl;
		inout.close();
	label:
		if (withdrawl_limit <= 100000)
		{
			account = new Bronze();
			inout.open("accounts.txt", ios::out | ios::app);
			inout << companyid << " " << account->getWithdarawlLimit() << " " << account->getAccountType() << endl;
			inout.close();
		}
		else if (withdrawl_limit <= 500000)
		{
			account = new Gold();
			inout.open("accounts.txt", ios::out | ios::app);
			inout << companyid << " " << account->getWithdarawlLimit() << " " << account->getAccountType() << endl;
			inout.close();
		}
		else if (withdrawl_limit <= 20000000)
		{
			account = new Bussiness();
			inout.open("accounts.txt", ios::out | ios::app);
			inout << companyid << " " << account->getWithdarawlLimit() << " " << account->getAccountType() << endl;
			inout.close();
		}
		else
		{
			cout << "Sorry max withdrawal limit can be 20000000 pkr" << endl;
			cin >> withdrawl_limit;
			goto label;
		}
		card.setcard();
		cout << "Companies credit card number is : " << card.getcard() << endl;;
		card.setpin();
		inout.open("cards.txt", ios::out | ios::app);
		inout << companyid << " " << card.getcard() << " " << card.getpin() << endl;
		inout.close();
		inout.open("balance.txt", ios::out | ios::app);
		inout << companyid << " " << transaction.getBalance() << endl;
		inout.close();
		cout << "Acccount Created Successfully" << endl;
	}
	void loginCompanyAccount()
	{
		string loginid, pass;
		bool flag = false;
		cout << "Enter Company's Account id : ";
		cin >> loginid;
		cout << "Enter password : ";
		cin >> pass;
		fstream inout;
		inout.open("companies.txt", ios::in);
		string line;
		while (getline(inout, line)) {
			size_t pos = 0;
			string value;
			int count = 0;
			while ((pos = line.find(",")) != string::npos) {
				value = line.substr(0, pos);
				switch (count) {
				case 0:
					companyid = stoi(value);
					break;
				case 1:
					companyName = value;
					break;
				case 2:
					companyAddress = value;
					break;
				case 3:
					companyTax = value;
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
					cout << "login successful" << endl;
					card.readCard(companyid);
					transaction.readBalance(companyid);
					inout.open("accounts.txt", ios::in);
					int id;
					while (inout >> id)
					{
						if (id == companyid)
						{
							inout >> withdrawl_limit;
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
					else if (withdrawl_limit <= 20000000)
					{
						account = new Bussiness();
					}
					cout << "login successful" << endl;
					break;
				}
				else
				{

					cout << "Incorrect password " << endl;
					cout << "Enter the correct password : ";
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
			cout << "Incorrect Account id " << endl;
			system("pause");
			system("cls");
			loginCompanyAccount();
		}
	}
	void addCompanyEmployee()
	{
		fstream inout, out, in;
		int userid;
		bool flag = false;
		string name, address, cnic, loginid, pass, accountidtocheck;
		cout << "Enter Employee's Account ID : ";
		cin >> accountidtocheck;
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
					loginid = value;
					break;
				case 5:
					pass = value;
					break;
				}

				line.erase(0, pos + 1);
				count++;
			}
			if (count == 5) {
				pass = line;
			}
			if (accountidtocheck == loginid)
			{
				flag = true;
				int user, company;
				in.open("companies_employees.txt", ios::in);
				bool exist = false;
				while (in >> user >> company)
				{
					if (userid == user && companyid == company)
					{
						exist = true;
						cout << "User already exist" << endl;
						break;
					}
					else
					{
						continue;
					}
				}
				if (!exist)
				{
					out.open("companies_employees.txt", ios::out | ios::app);
					out << userid << " " << companyid << endl;
					out.close();
					cout << "Employee Added" << endl;
				}
				break;
			}
			else
			{
				continue;
			}
		}
		in.close();
		inout.close();
		if (!flag)
		{
			cout << "User " << accountidtocheck << " does not have bank account" << endl;
		}
	}
	void deposit()
	{
		transaction.deposit(companyid, card.getpin());
	}
	void withdraw()
	{
		transaction.withdraw(companyid, card.getpin(), account->getWithdarawlLimit());
	}
	void transfer()
	{
		transaction.companytransfer(companyid, card.getpin());
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
			if (companyid == stoi(id))
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
	void applyloan()
	{
		int loan, choice;;
		cout << "Enter amount to take loan : ";
		cin >> loan;
		cout << "Choose time span " << endl;
		cout << "\t\t1- 1 year " << endl;
		cout << "\t\t2- 2 year " << endl;
		cout << "\t\t3- 3 year " << endl;
		cout << "\t\t";
		cin >> choice;
		cout << "Request sent for approval check notifications later :)" << endl;
		fstream inout;
		inout.open("loan_request.txt", ios::out | ios::app);
		inout << companyid << " " << loan << " " << choice << "years" << endl;
		inout.close();
	}
	void Notification()
	{
		fstream in;
		string fid, years;
		long double amount;
		bool any = false;
		in.open("loans.txt", ios::in);
		if (in.is_open())
		{
			while (in >> fid >> amount >> years)
			{
				if (companyid == stoi(fid))
				{
					any = true;
					cout << "Your application for loan " << amount << " for " << years << " has been approved" << endl;
					char choice;
					cout << "Do you want to take loan (y/n) : ";
					cin >> choice;
					if (choice == 'y' || choice == 'Y')
					{
						amount += transaction.getBalance();
						transaction.updateBalance(companyid, amount);
						transaction.readBalance(companyid);
					}
				}
				else
				{
					fstream out;
					out.open("temp.txt", ios::out | ios::app);
					out << fid << " " << amount << " " << years << endl;
					out.close();
				}
			}
			in.close();
			remove("loans.txt");
			rename("temp.txt", "loans.txt");
			if (!any)
			{
				cout << "No Notifications" << endl;
			}
		}
		else
		{
			cout << "No Notifications " << endl;
		}

	}
	~CompanyClient()
	{
		delete account;
		account = nullptr;
	}
};