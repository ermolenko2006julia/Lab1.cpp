#include "my_array.h"

my_array::my_array()
{
	capacity = 10;
	count = 0;
	products = new product[capacity];
}

void my_array::add(product p)
{
	if (capacity == count) {
		product* temp = new product[capacity * 2];
		for (int i = 0; i < capacity; i++)
		{
			temp[i] = products[i];
		}
		delete[] products;

		products = temp;
	}

	products[count] = p;
	count++;
}

int my_array::get_count() const
{
	return count;
}

void my_array::remove(int index)
{
	for (int i = index; i < count - 1; i++)
	{
		products[i] = products[i + 1];
	}
	count--;
}

product my_array::get_product(int index) const
{
	return products[index];
}

void my_array::set_product(product p, int index)
{
	products[index] = p;
}

my_array my_array::find_products_by_category(string category)
{
	my_array res;
	for (int i = 0; i < count; i++)
	{
		if (products[i].get_category() == category) {
			res.add(products[i]);
		}
	}
	return res;
}

my_array my_array::find_products_by_cost(int start_cost, int finish_cost)
{
	my_array res;
	for (int i = 0; i < count; i++) {
		if (products[i].get_cost() >= start_cost && products[i].get_cost() < finish_cost) {
			res.add(products[i]);
		}
	}
	return res;
}

ostream& operator<<(ostream& out, const my_array& arr)
{
	for (int i = 0; i < arr.count; i++)
	{
		out << "Номер " << (i+1) << ". " << arr.products[i];
	}
	return out;
}
