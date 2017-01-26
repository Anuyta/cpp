#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

class Student
{
	std::string name;
	int group;

public:
	Student() = default;

	Student(std::string name_, int group_)
		: name{ name_ }, group{group_}
	{
	}

	Student(const Student& stud)
		: name{ stud.name }, group{ stud.group }
	{
	}

	friend std::ostream& operator<< (std::ostream& os, const Student& stud);
};

std::ostream& operator<< (std::ostream& os, const Student& stud)
{
	os << stud.name << " ";
	os << stud.group << std::endl;
	return os;
}

//void initStud(std::vector<Student>& stud)
//{
//	stud.emplace_back("Ivanov", 210);
//	stud.emplace_back("Petrov", 215);
//}

void fillVector(std::vector<Student>& vStudents)
{
	for (unsigned i = 0; i < 100; ++i)
	{
		vStudents.emplace_back(std::string("Ivan") + std::to_string(rand() % 100), rand() % 5 + 18);
	}
}

void ptintStud(std::vector<Student>& stud)
{
	for (auto it = stud.begin(), end = stud.end(); it != end; ++it)
	{
		std::cout << *it;
	}
}

//void fillMap(std::map<std::vector<Student>::size_type, Student> stud)
//{
//	for (auto size = stud.size(), i = 0; i < i < size; ++i)
//	{
//		stud[i] = 
//	}
//}

void ptintMap(std::map<std::vector<Student>::size_type, Student> stud)
{
	for (auto it = stud.begin(), end = stud.end(); it != end; ++it)
	{
		std::cout << it->first << " " << it->second<< std::endl;
	}
}

int main()
{
	std::vector<Student> stud;
	stud.reserve(100);
	fillVector(stud);
	//initStud(stud);
	ptintStud(stud);

	std::map<std::vector<Student>::size_type, Student> stud1;
	auto size = stud.size();
	for (decltype(size) i = 0; i < size; ++i)	
		stud1[i] = stud[i];
	ptintMap(stud1);
	return 0;
}
