#pragma once

class Transaction {
private:
	long double balance;
	char date[11];
public:
	Transaction()
	{
		balance = 0;
		time_t now = time(nullptr);
		tm local_time;
		localtime_s(&local_time, &now);
		strftime(date, sizeof(date), "%d-%m-%Y", &local_time);
	}
	long double getBalance()
	{
		return balance;
	}
	const char* getDate()
	{
		return date;
	}
	void updateBalance(int id, long double balance)
	{
		fstream inout, inout2;
		int fid;
		long double fbalance;
		inout.open("balance.txt", ios::in);
		inout2.open("temp.txt", ios::out);
		while (inout >> fid >> fbalance)
		{
			if (fid != id)
			{
				inout2 << fid << " " << fbalance << endl;
			}
			else
			{
				continue;
			}
		}
		inout2 << id << " " << balance << endl;
		inout.close();
		inout2.close();
		remove("balance.txt");
		rename("temp.txt", "balance.txt");
	}
	void readBalance(int id)
	{
		fstream inout;
		int userid;
		inout.open("balance.txt", ios::in);
		while (inout >> userid)
		{
			if (userid == id)
			{
				inout >> balance;
				break;
			}
			else
			{
				continue;
			}
		}
	}
	void markasfraudlent(int id)
	{
		fstream out;
		out.open("fraudlents.txt", ios::out | ios::app);
		out << id << endl;
		out.close();
	}
	void deposit(int id, int pin)
	{
		long double amount;
		int p;
		cout << "Enter amount to deposit : ";
		cin >> amount;
		cout << "Enter 4-digit pin : ";
		cin >> p;
		int i = 1;
		while (p != pin)
		{
			if (i == 3)
			{
				markasfraudlent(id);
				break;
			}
			cout << "Incorrect pin ";
			cout << pin;
			cin >> p;
			i++;
		}
		if (p == pin)
		{
			balance += amount;
			updateBalance(id, balance);
			readBalance(id);
			fstream inout;
			inout.open("Transactions.txt", ios::out | ios::app);
			inout << date << " " << id << " " << amount << " " << "Deposit" << endl;
			cout << "Transaction Successful" << endl;
			inout.close();
		}
	}
	void withdraw(int id, int pin, long long int limit)
	{
		long double amount;
		int p;
		cout << "Enter amount to withdraw : ";
		cin >> amount;
		while (amount > balance || amount > limit)
		{
			cout << "You have insufficient balance or max withdrawal limit is reached" << endl;
			cin >> amount;
		}
		cout << "Enter 4-digit pin : ";
		cin >> p;
		int i = 1;
		while (p != pin)
		{
			if (i == 3)
			{
				markasfraudlent(id);
				break;
			}
			cout << "Incorrect pin ";
			cin >> p;
			i++;
		}
		if (p == pin)
		{
			balance -= amount;
			updateBalance(id, balance);
			readBalance(id);
			fstream inout;
			inout.open("Transactions.txt", ios::out | ios::app);
			inout << date << " " << id << " " << amount << " " << "Withdraw" << endl;
			cout << "Transaction Successful" << endl;
			inout.close();
		}
	}
	void transfer(int id, int pin)
	{
		long double amount;
		int userid, p;
		cout << "Enter amount to transfer : ";
		cin >> amount;
		while (amount > balance)
		{
			cout << "You have insufficient balance " << endl;
			cin >> amount;
		}
	label:
		cout << "Enter user id whom to transfer : ";
		cin >> userid;
		fstream inout;
		int ID;
		long double BALANCE;
		bool flag = false;
		inout.open("balance.txt", ios::in);
		while (inout >> ID >> BALANCE)
		{
			if (ID == userid)
			{
				flag = true;
				break;
			}
			else
			{
				continue;
			}
		}
		inout.close();
		if (!flag)
		{
			cout << "User with ID : " << userid << " not found" << endl;
			goto label;
		}
		cout << "Enter 4-digit pin : ";
		cin >> p;
		int i = 1;
		while (p != pin)
		{
			if (i == 3)
			{
				markasfraudlent(id);
				break;
			}
			cout << "Incorrect pin" << endl;
			cin >> p;
			i++;
		}
		if (p == pin)
		{
			balance -= amount;
			updateBalance(id, balance);
			BALANCE += amount;
			updateBalance(ID, BALANCE);
			readBalance(id);
			inout.open("Transactions.txt", ios::out | ios::app);
			inout << date << " " << id << " " << amount << " " << "Transfer" << " " << userid << endl;
			inout.close();
			cout << "Transaction Successful" << endl;

		}
	}
	void companytransfer(int id, int pin)
	{
		fstream inout;
		int userid, ID, BALANCE; bool flag = false; long double amount;
		string name, address, cnic, loginid, password;
		string accounttocheck;
		cout << "Enter User's Account ID to transfer : ";
		cin >> accounttocheck;
		inout.open("users.txt", ios::in);
		string line;
		while (getline(inout, line))
		{
			size_t pos = 0;
			string value;
			int count = 0;
			while ((pos = line.find(",")) != string::npos)
			{
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
					password = value;
					break;
				}
				line.erase(0, pos + 1);
				count++;
			}
			if (count == 5) {
				password = line;
			}
			if (accounttocheck == loginid)
			{
				flag = true;
				fstream in;
				int user, company;
				bool employee = false;
				in.open("companies_employees.txt", ios::in);
				while (in >> user >> company)
				{
					if (user == userid && company == id)
					{
						employee = true;
						fstream read;
						read.open("balance.txt", ios::in);
						while (read >> ID >> BALANCE)
						{
							if (ID == userid)
							{
								read.close();
								cout << "Enter Amount to transfer : ";
								cin >> amount;
								while (amount > balance)
								{
									cout << "You have insufficient balance " << endl;
									cin >> amount;
								}
								int p;
								cout << "Enter 4-digit pin : ";
								cin >> p;
								int i = 1;
								while (p != pin)
								{
									if (i == 3)
									{
										markasfraudlent(id);
										break;
									}
									cout << "Incorrect pin " << endl;
									cout << "Try again : ";
									cin >> p;
									i++;
								}
								if (p == pin)
								{
									fstream trans;
									balance -= amount;
									updateBalance(id, balance);
									BALANCE = BALANCE + amount;
									updateBalance(ID, BALANCE);
									readBalance(id);
									trans.open("Transactions.txt", ios::out | ios::app);
									cout << "balance = " << balance << " BALANCE = " << BALANCE << endl;
									trans << date << " " << id << " " << amount << " " << "Transfer" << " " << userid << endl;
									trans.close();
									cout << "Transaction Successful" << endl;
								}
								break;
							}
							else
							{
								continue;
							}
						}
						break;
					}
					else
					{
						continue;
					}
				}
				in.close();
				if (!employee)
				{
					cout << loginid << " is not the employee of the company" << endl;
				}
				break;
			}
			else
			{
				continue;
			}
		}
		inout.close();
		if (!flag)
		{
			cout << "User does not exist" << endl;
		}
	}
};