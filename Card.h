#pragma once
using namespace std;

class Card {
private:
	long long int card_no;
	int pin_id;
public:

	void setcard()
	{
		srand(time(0));
		for (int i = 0; i < 15; i++)
		{
			card_no = card_no * 10 + rand() % 10;
		}
	}
	long long int getcard()
	{
		return card_no;
	}
	void setpin()
	{
		cout << "Enter 4 digit pin : ";
		cin >> pin_id;
	}
	int getpin()
	{
		return pin_id;
	}
	void readCard(int id)
	{
		fstream inout;
		inout.open("cards.txt", ios::in);
		int ID;
		while (inout >> ID >> card_no >> pin_id)
		{
			if (id == ID)
			{
				break;
			}
			else
			{
				continue;
			}
		}
		inout.close();
	}
};