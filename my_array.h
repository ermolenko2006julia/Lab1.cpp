#pragma once
#include "product.h"

class my_array
{
private:
	product* products;
	int capacity;
	int count;

public:
	my_array();

	void add(product p);
	int get_count() const;
	void remove(int index);
	product get_product(int index) const;
	void set_product(product p, int index);

	my_array find_products_by_category(string category);
	my_array find_products_by_cost(int start_cost, int finish_cost);

	friend ostream& operator<<(ostream& out, const my_array& arr);
};

