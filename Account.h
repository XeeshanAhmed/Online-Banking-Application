#pragma once

class Account {
public:
	virtual long long int getWithdarawlLimit()const
	{
		return 0;
	}
	virtual string getAccountType()
	{
		return "";
	}

};

class Bronze :public Account {
private:
	const long long int withdarwal_limit = 100000;
public:
	virtual long long int getWithdarawlLimit()const
	{
		return withdarwal_limit;
	}
	virtual string getAccountType()
	{
		return "Bronze";
	}
};

class Gold :public Account {
private:
	const long long int withdarwal_limit = 500000;
public:
	virtual long long int getWithdarawlLimit()const
	{
		return withdarwal_limit;
	}
	virtual string getAccountType()
	{
		return "Gold";
	}
};

class Bussiness :public Account {
private:
	const long long int withdarwal_limit = 20000000;
public:
	virtual long long int getWithdarawlLimit()const
	{
		return withdarwal_limit;
	}
	virtual string getAccountType()
	{
		return "Bussiness";
	}
};