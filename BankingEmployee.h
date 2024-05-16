#pragma once

class BankingEmployee {
private:
	string loginid;
	string password;
	UserClient* user;
	CompanyClient* company;
public:

	bool login()
	{
		bool exist = false;
		string fid, fpass;;
		cout << "Enter login id : ";
		cin >> loginid;
		cout << "Enter password : ";
		cin >> password;
		fstream inout;
		inout.open("banking_employee.txt", ios::in);
		while (inout >> fid >> fpass)
		{
			if (fid == loginid)
			{
				if (fpass == password)
				{
					exist = true;
					cout << "login successful" << endl;
					return true;
				}
				else
				{
					cout << "Incorrext password" << endl;
					while (password != fpass)
					{
						cout << "Try Again : ";
						cin >> password;
					}
					if (fpass == password)
					{
						exist = true;
						cout << "login Successful" << endl;
						return true;
					}
				}
			}
			else
			{
				continue;
			}
		}
		inout.close();
		if (!exist)
		{
			cout << "Inorrect Id" << endl;
			return false;
		}
	}
	void loan_requests()
	{
		fstream in, out;
		int approval;
		in.open("loan_request.txt", ios::in);
		string line;
		if (in.is_open())
		{
			while (getline(in, line))
			{
				cout << line << endl;
				cout << "1-Accept " << endl;
				cout << "2-Reject" << endl;
				cout << " \t :";
				cin >> approval;
				while (approval != 1 && approval != 2)
				{
					cout << "Invalid choice" << endl;
					cout << " \t : ";
					cin >> approval;
				}
				if (approval == 1)
				{
					out.open("loans.txt", ios::out | ios::app);
					out << line << endl;
					out.close();
					cout << "Thank you" << endl;
				}
				else
				{
					cout << "Okies" << endl;
				}
			}
			in.close();
			remove("loan_request.txt");
		}
		else
		{
			cout << "No Loan requests" << endl;
		}
	}
	void fraudlents()
	{
		fstream fraud_in, user_in, company_in, out;
		int fid;
		char id[2];
		string line;
		fraud_in.open("fraudlents.txt", ios::in);
		if (fraud_in.is_open())
		{
			while (fraud_in >> fid)
			{
				user_in.open("users.txt", ios::in);
				while (getline(user_in, line))
				{
					id[0] = line[0];
					id[1] = '\0';
					if (fid == stoi(id))
					{
						cout << "following account has been identified as as fraudlent" << endl;
						cout << line;
						cout << "Freeze the account ? (y/n)";
						char choice;
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							cout << "Account blocked" << endl;
						}
					}
					else
					{
						out.open("temp.txt", ios::out | ios::app);
						out << line << endl;
						out.close();
					}
				}
				user_in.close();
				remove("users.txt");
				rename("temp.txt", "users.txt");
			}
			fraud_in.close();
		}
		else
		{
			cout << "No account has been identified as fraudlent" << endl;
			cout << "No fraudlent accounts" << endl;
			system("pause");
		}
	}
	void veiwtransaction()
	{
		int ID;
		cout << "Enter Id no to view history : ";
		cin >> ID;
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
			if (ID == stoi(id))
			{
				cout << line << endl;
			}
		}
		inout.close();
	}
};