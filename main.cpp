#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<exception>
#include<fstream>
#include<cstdlib>
#include<ctime>
//including al the created header files
#include"Card.h"
#include"Account.h"
#include"Transaction.h"
#include"UserClient.h"
#include"CompanyClient.h"
#include"BankingEmployee.h"
using namespace std;

int main()
{
	int option;
	bool mainMenu = true;
	UserClient user;
	CompanyClient client;
	BankingEmployee employee;
	while (mainMenu)
	{
		cout << "\t\t\t\t\t\t\t\t----------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\tSecure your financial future with us..." << endl;
		cout << "\t\t\t\t\t\t\t\t\t    Join us Now!" << endl;
		cout << "\t\t\t\t\t\t\t\t----------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t 1-USER" << endl;
		cout << "\t\t\t\t\t\t\t\t 2-COMPANY" << endl;
		cout << "\t\t\t\t\t\t\t\t 3-EMPLOYEE" << endl;
		cout << "\t\t\t\t\t\t\t\t 4-EXIT" << endl;
		cout << "\t\t\t\t\t\t\t\t Please select option:";
		while (true)
		{
			if (cin >> option)
			{
				break;
			}
			else
			{
				cin.clear();
				// Discard the invalid input
				cin.ignore();
				cout << "Invalid input. Please enter an integer.\n";
			}


		}
		switch (option)
		{
		case 1:
			while (true)
			{
				system("cls");
				cout << "\t\t\t\t\t\t\t\t 1-LOGIN" << endl;
				cout << "\t\t\t\t\t\t\t\t 2-SIGNUP" << endl;
				cout << "\t\t\t\t\t\t\t\t 3-Back" << endl;
				cout << "\t\t\t\t\t\t\t\t Please select option:";
				cin >> option;
				bool loginSignup = false;//through this variable i am keeping track wether user has login or sigup because i have to show same functionality to user in both the cases
				if (option == 1)
				{
					user.login_user();
					loginSignup = true;
				}
				else if (option == 2)
				{
					user.register_user();
					loginSignup = true;
				}
				else if (option == 3)
				{
					break;
				}
				else
				{
					cout << "Invalid input" << endl;
				}
				while (loginSignup)
				{
					system("cls");
					cout << "\t\t\t\t\t\t\t\t 1-Depsoit Money" << endl;
					cout << "\t\t\t\t\t\t\t\t 2-Withdraw Money" << endl;
					cout << "\t\t\t\t\t\t\t\t 3-Transfer Money" << endl;
					cout << "\t\t\t\t\t\t\t\t 4-Check Balance" << endl;
					cout << "\t\t\t\t\t\t\t\t 5-View Transaction History" << endl;
					cout << "\t\t\t\t\t\t\t\t 6-Sign out" << endl;
					cout << "\t\t\t\t\t\t\t\t Please select option : ";
					cin >> option;
					if (option == 1)
					{
						user.deposit();
						system("pause");
					}
					else if (option == 2)
					{
						user.withdraw();
						system("pause");
					}
					else if (option == 3)
					{
						user.transfer();
						system("pause");
					}
					else if (option == 4)
					{
						user.checkBalance();
						system("pause");
					}
					else if (option == 5)
					{
						user.viewTransactionHistory();
						system("pause");
					}
					else if (option == 6)
					{
						loginSignup = false;

					}
					else
					{
						cout << "Invalid input" << endl;
					}
				}
			}
			break;
		case 2:
			while (true)
			{
				system("cls");
				cout << "\t\t\t\t\t\t\t\t 1-LOGIN" << endl;
				cout << "\t\t\t\t\t\t\t\t 2-CREATE ACCOUNT" << endl;
				cout << "\t\t\t\t\t\t\t\t 3-Back" << endl;
				cout << "\t\t\t\t\t\t\t\t Please select option : ";
				cin >> option;
				bool loginSignup = false;
				if (option == 1)
				{
					client.loginCompanyAccount();
					loginSignup = true;
				}
				else if (option == 2)
				{
					client.createCompanyAccount();
					loginSignup = true;
				}
				else if (option == 3)
				{
					break;
				}
				else
				{
					cout << "Invalid Input";
				}
				while (loginSignup)
				{
					system("cls");
					cout << "\t\t\t\t\t\t\t\t 1-Depsoit Money" << endl;
					cout << "\t\t\t\t\t\t\t\t 2-Withdraw Money" << endl;
					cout << "\t\t\t\t\t\t\t\t 3-Transfer Money" << endl;
					cout << "\t\t\t\t\t\t\t\t 4-Check Balance" << endl;
					cout << "\t\t\t\t\t\t\t\t 5-View Transaction History" << endl;
					cout << "\t\t\t\t\t\t\t\t 6-Add Employee" << endl;
					cout << "\t\t\t\t\t\t\t\t 7-Apply for Loan" << endl;
					cout << "\t\t\t\t\t\t\t\t 8-Notifications" << endl;
					cout << "\t\t\t\t\t\t\t\t 9-Sign out" << endl;
					cout << "\t\t\t\t\t\t\t\t Please select option : ";
					cin >> option;
					if (option == 1)
					{
						client.deposit();
						system("pause");
					}
					else if (option == 2)
					{
						client.withdraw();
						system("pause");
					}
					else if (option == 3)
					{
						client.transfer();
						system("pause");
					}
					else if (option == 4)
					{
						client.checkBalance();
						system("pause");
					}
					else if (option == 5)
					{
						client.viewTransactionHistory();
						system("pause");
					}
					else if (option == 6)
					{
						client.addCompanyEmployee();
						system("pause");
					}
					else if (option == 7)
					{
						client.applyloan();
						system("pause");
					}
					else if (option == 8)
					{
						client.Notification();
						system("pause");
					}
					else if (option == 9)
					{
						loginSignup = false;
					}
					else
					{
						cout << "Invalid input" << endl;
					}
				}
			}
			break;
		case 3:
			cout << " Please Login Below " << endl;
			if (employee.login())
			{
				while (true)
				{
					system("cls");
					cout << "\t\t\t\t\t\t\t\t 1-Veiw Users List" << endl;
					cout << "\t\t\t\t\t\t\t\t 2-Loan Applications" << endl;
					cout << "\t\t\t\t\t\t\t\t 3-Fraudlent Accounts" << endl;
					cout << "\t\t\t\t\t\t\t\t 4-View Transaction History" << endl;
					cout << "\t\t\t\t\t\t\t\t 5-Freeze an account" << endl;
					cout << "\t\t\t\t\t\t\t\t 6-Sign out" << endl;
					cout << "\t\t\t\t\t\t\t\t Please select option : ";
					cin >> option;
					if (option == 1)
					{
						fstream inout;
						string line;
						inout.open("users.txt", ios::in);
						while (getline(inout, line))
						{
							cout << line << endl;
						}
						inout.close();
						system("pause");
					}
					else if (option == 2)
					{
						employee.loan_requests();
						system("pause");
					}
					else if (option == 3)
					{
						employee.fraudlents();
						system("pause");
					}
					else if (option == 4)
					{
						employee.veiwtransaction();
						system("pause");
					}
					else if (option == 5)
					{
						int acc;
						cout << "Enter Id no to close the account : ";
						cin >> acc;
						fstream inout;
						string line;
						char id[2];
						inout.open("users.txt", ios::in);
						while (getline(inout, line))
						{
							id[0] = line[0];
							id[1] = '\0';
							if (acc == stoi(id))
							{
								continue;
							}
							else
							{
								fstream out;
								out.open("temp.txt", ios::out | ios::app);
								out << line << endl;
								out.close();
							}
						}
						inout.close();
						remove("users.txt");
						rename("temp.txt", "users.txt");
						cout << "Account blocked" << endl;
					}
					else if (option == 6)
					{
						break;
					}
					else
					{
						cout << "Invalid input" << endl;
					}
				}

			}
			else
			{
				cout << "Unable to signin you" << endl;
			}
			break;
		case 4:
			mainMenu = false;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	}

}