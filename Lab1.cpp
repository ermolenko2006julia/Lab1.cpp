#include <iostream>
#include <string>
#include <fstream>
#include "my_array.h"

namespace database {
	product create_product() {
		string name, category;
		int count, cost;

		cout << "Введите название продукта: ";
		getline(cin, name);

		cout << "Введите категорию продукта: ";
		getline(cin, category);

		cout << "Введите стоимость продукта: ";
		cin >> cost;

		cout << "Введите кол-во продукта: ";
		cin >> count;

		product p(name, cost, count, category);
		return p;
	}

	void edit_product(product& p) {
		int choice;
		do
		{
			cout << "Что редактировать? 1.Название 2.Стоимость 3.Количество 4.Категория 0.Завершить редактирование" << endl;
			cin >> choice;

			if (choice == 1) {
				string new_name;
				cout << "Введите новое название: ";
				cin >> new_name;

				p.set_name(new_name);
			}
			else if (choice == 2) {
				int new_cost;
				cout << "Введите новую стоимость: ";
				cin >> new_cost;

				p.set_cost(new_cost);
			}
			else if (choice == 3) {
				int new_count;
				cout << "Введите новое кол-во: ";
				cin >> new_count;

				p.set_count(new_count);
			}
			else if (choice == 4) {
				string new_category;
				cout << "Введите новую категорию: ";
				cin >> new_category;

				p.set_category(new_category);
			}
		} while (choice != 0);
	}

	void save_file(const my_array& arr) {
		ofstream file("products.txt"); //открытие файла на запись

		for (int i = 0; i < arr.get_count(); i++)
		{
			product p = arr.get_product(i);
			file << p.get_name() << ";" << p.get_category() << ";" << p.get_cost() << ";" << p.get_count();
			if (i < arr.get_count() - 1) {
				file << endl;
			}
		}
		file.close();
	}

	void load_file(my_array& arr) {
		ifstream file("products.txt"); //открываем файл на чтение
		if (!file.is_open()) {
			return;
		}
		while (!file.eof()) //пока файл не закончился
		{
			string name, category, cost, count;

			getline(file, name, ';'); //чтение до точки запятой (разделитель - точка с запятой)
			getline(file, category, ';');
			getline(file, cost, ';');
			getline(file, count);

			product p(name, stoi(cost), stoi(count), category); //stoi - функция преобразования строки в число
			arr.add(p);
		}
		file.close();
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	my_array arr;
	database::load_file(arr);
	int choice;

	do
	{
		cout << "1.Добавить продукт" << endl;
		cout << "2.Вывести продукты" << endl;
		cout << "3.Удалить продукт" << endl;
		cout << "4.Редактировать продукт" << endl;
		cout << "5.Поиск по категории" << endl;
		cout << "6.Поиск по цене" << endl;
		cout << "0.Выход" << endl;

		cin >> choice;
		cin.ignore();

		if (choice == 1) {
			product p = database::create_product();
			arr.add(p);
			database::save_file(arr); //вызываем функцию сохранение в файл
		}
		else if (choice == 2) {
			cout << arr << endl;
		}
		else if (choice == 3) {
			cout << arr << endl;

			cout << "Введите номер продукта: ";
			int number;
			cin >> number;

			if (number >= 1 && number <= arr.get_count()) {
				arr.remove(number - 1);
				database::save_file(arr);
			}
			else {
				cout << "Неверный номер" << endl;
			}
		}
		else if (choice == 4) {
			cout << arr << endl;

			cout << "Введите номер продукта: ";
			int number;
			cin >> number;

			if (number >= 1 && number <= arr.get_count()) {
				product p = arr.get_product(number - 1);
				database::edit_product(p);
				arr.set_product(p, number - 1);
				database::save_file(arr);
			}
			else {
				cout << "Неверный номер" << endl;
			}
		}
		else if (choice == 5) {
			string category;
			cout << "Введите категорию: ";
			cin >> category;

			my_array res = arr.find_products_by_category(category);
			cout << res << endl;
		}
		else if (choice == 6) {
			int start_cost, finish_cost;
			cout << "Начальная стоимость: ";
			cin >> start_cost;

			cout << "Конечная стоимость: ";
			cin >> finish_cost;

			my_array res = arr.find_products_by_cost(start_cost, finish_cost);
			cout << res << endl;
		}
	} 
	while (choice != 0);
}