#include "18.h"

using namespace std;


/*конструктор, деструктор*/
LFU::LFU(size_t size1)
{
	 size = size1;	 
	 count = 0;
}

LFU::~LFU()
{	
	My_map.clear();
}


/*поиск по значению, поиск минимума*/
map <string, int>::iterator LFU::find_value(const int value)
{
	map<string, int>::iterator it;
	it = My_map.begin();

    while (it!=My_map.end()) 
    {
        if ((*it).second==value) 
			return it;
        ++it;
    }
    return My_map.end();
}

int LFU::find_minimum()
{
	map<string, int>::iterator it;
	it = My_map.begin();
	int min = (*it).second;
    while (it!=My_map.end()) 
    {
		if (min > (*it).second)
			min = (*it).second;
       ++it;
    }
    return min;

}

int LFU::get_min()
{
	return min;
}


/*нахождение адреса, добавление адреса в map*/
bool LFU::find_and_add(const string &address)
{
	auto result = My_map.find(address);
	if (result == My_map.end())
	{
		if (count < size)
		{
			My_map.insert (pair<string,int>(address, 1));
			min = 1;
			count++;
		}
		else 
		{
			auto res = find_value(min);
			My_map.erase(res);

			My_map.insert (pair<string,int>(address, 1));			
		}
		return false;
	}
	else
	{
		My_map[address] += 1;
		int value = My_map[address];
		min = find_minimum();
	}
	return true;	
}

bool LFU::find(const string &address)
{
	auto result = My_map.find(address);
	
	if (result != My_map.end())
	{
		My_map[address] += 1;
		int value = My_map[address];
		min = find_minimum();
		return true;
	}
	else 
		return false;
}


/*вывод*/
void LFU::print() 
{
	for (auto it = My_map.begin(); it != My_map.end(); ++it)
		cout <<  it->first << " : " << it->second << endl;
}

void LFU::print_address(const string &address) 
{
	auto it = My_map.find(address);
		cout <<  it->first << " : " << it->second << endl;
}










/*LFU::LFU(size_t size1)
{
	mp.insert(pair<string,int>("0000",0));

	size = size1;
	
	for (size_t i = 0; i < size; i++)
		ItemList.push_back(mp);
}

LFU::~LFU()
{
	ItemList.clear();
}

bool LFU::find_and_add(const string &address)
{
	for(auto it = ItemList.begin(); it != ItemList.end(); ++it)
	{
		auto result = mp.find[address];
		if(result != mp.end())
		{
			mp[result] +=1;
			return true;
		}
	}
}*/

/*храню значение минимума в отдельном поле класс
*/

//int size_Queue = My_Queue.size();

			/*auto dubbing = My_Queue;
			for(int i = size_Queue; i > 1; i--)
				dubbing.pop();
			int min = dubbing.top();*/

//My_Queue.push(1);


		//My_Queue.push(value);