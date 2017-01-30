#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Person
{
public:
	std::string name;
	std::string surname;
	friend std::ostream& operator<< (std::ostream& os, const Person& pers);	

	bool operator > (const Person& per) const
	{
		return (name > per.name);
	}

	bool operator < (const Person& per) const
	{
		return (name < per.surname);
	}
};

std::ostream& operator<< (std::ostream& os, const Person& pers)
{
	os << pers.name << " ";
	os << pers.surname << std::endl;
	return os;
}

int main()
{
	std::vector<Person> pers;
	std::ifstream f1("file_1.txt");	

	if (!f1.is_open())
	{
		std::cout << "Error, file not found!\n";
		exit(1);
	}		

	Person per;
	while (!f1.eof())
	{
		f1 >> per.name >> per.surname;
		pers.push_back(per);		
	}		

	std::ofstream f2("file_2.txt");		
	std::sort(pers.begin(), pers.end(), [](const Person& a, const Person& b) 
	{
		return b < a;
	});
	for (auto it : pers) 		
		f2 << it;
	
	std::ofstream f3("file_3.txt");	
	std::sort(pers.begin(), pers.end(), [](const Person& a, const Person& b)
	{
		return b > a;
	});
	for (auto it : pers)
		f3 << it;
	return 0;
}
