#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

class LFU
{
private:
	size_t size;
	size_t count;
	size_t min;
	map <string, int> My_map;

public:
	/*конструктор, деструктор*/
	LFU(size_t size1);
	~LFU();

	/*поиск по значению, поиск минимума*/
	map<string, int>::iterator find_value(const int value);
	int find_minimum();
	int get_min();
	
	/*нахождение адреса, добавление адреса в map*/
	bool find_and_add(const string &address);
	bool find(const string &address);

	/*вывод*/
	void print();
	void print_address(const string &address);
};












//friend ostream& operator << (ostream& os, const map<string, int> & My_map);