#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <ctime>

using namespace std;

const int LENGHT = 10000000;
const int FIND_VALUE = 9999;

int main()
{
	vector<int> vec;
	unordered_set<int> set;
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	auto start_time_vec_add = chrono::high_resolution_clock::now();
	for (int i = 0; i < LENGHT; i++)
	{
		if (i == LENGHT / 2)
		{
			vec.push_back(FIND_VALUE);
		}
		vec.push_back(rand() % 1000);
	}
	auto end_time_vec_add = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_vec_add = end_time_vec_add - start_time_vec_add;
	cout << "Добавление " << LENGHT << " элементов для std::vector - " << elapsed_vec_add.count() << " c." << endl;

	auto start_time_set_add = chrono::high_resolution_clock::now();
	for (int i = 0; i < LENGHT; i++)
	{
		if (i == LENGHT / 2)
		{
			set.insert(FIND_VALUE);
		}
		set.insert(rand() % 1000);
	}
	auto end_time_set_add = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_set_add = end_time_set_add - start_time_set_add;
	cout << "Добавление " << LENGHT << " элементов для std::unordered_set = " << elapsed_set_add.count() << " с." << endl;
	
	auto start_time_vec_find = chrono::high_resolution_clock::now();
	auto pos_vec = find(vec.begin(), vec.end(), FIND_VALUE);
	auto end_time_vec_find = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_vec_find = end_time_vec_find - start_time_vec_find;
	cout << "Поиск элемента в std::vector = " << elapsed_vec_find.count() << " c." << endl;

	auto start_time_set_find = chrono::high_resolution_clock::now();
	auto pos_set = set.find(FIND_VALUE);
	auto end_time_set_find = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_set_find = end_time_set_find - start_time_set_find;
	cout << "Поиск элемента в std::unorederd_set = " << elapsed_set_find.count() << " c." << endl;

	auto start_time_vec_delete = chrono::high_resolution_clock::now();
	vec.erase(vec.begin());
	auto end_time_vec_delete = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_vec_delete = end_time_vec_delete - start_time_vec_delete;
	cout << "Удаление элемента из начала std::vector = " << elapsed_vec_delete.count() << " c." << endl;

	auto start_time_set_delete = chrono::high_resolution_clock::now();
	set.erase(FIND_VALUE);
	auto end_time_set_delete = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_set_delete = end_time_set_delete - start_time_set_delete;
	cout << "Удаление элемента из std::unoredered_set = " << elapsed_set_delete.count() << " c." << endl;
}