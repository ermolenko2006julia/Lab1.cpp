#pragma once
#include <iostream>
using namespace std;

class product
{
private:
	string name;
	int cost;
	int count;
	string category;

public:
	product();
	product(string name, int cost, int count, string category);

	string get_name() const;
	int get_count() const;
	int get_cost() const;
	string get_category() const;

	void set_name(string name);
	void set_count(int count);
	void set_cost(int cost);
	void set_category(string category);

	friend ostream& operator<<(ostream& out, const product& p);
	friend istream& operator>>(istream& in, product& p);
};

