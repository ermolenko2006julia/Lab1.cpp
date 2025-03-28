#include "product.h"

product::product()
{
	name = "";
	cost = 0;
	count = 0;
	category = "";
}

product::product(string name, int cost, int count, string category)
{
	this->name = name;
	this->cost = cost;
	this->category = category;
	this->count = count;
}

string product::get_name() const
{
	return name;
}

int product::get_count() const
{
	return count;
}

int product::get_cost() const
{
	return cost;
}

string product::get_category() const
{
	return category;
}

void product::set_name(string name)
{
	this->name = name;
}

void product::set_count(int count)
{
	this->count = count;
}

void product::set_cost(int cost)
{
	this->cost = cost;
}

void product::set_category(string category)
{
	this->category = category;
}

ostream& operator<<(ostream& out, const product& p)
{
	out << "Название: " << p.name << ", Категория: " << p.category << ", Кол-во: " << p.count << ", Стоимость: " << p.cost << endl;
	return out;
}

istream& operator>>(istream& in, product& p)
{
	in >> p.name >> p.category >> p.count >> p.cost;
	return in;
}
