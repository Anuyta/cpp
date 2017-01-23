#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::string s;
	std::ifstream f("Text.txt");
	std::string::size_type n;
	int count = 0;
	while (!f.eof())
	{
		std::getline(f, s);
		std::string::size_type len = s.size();	
		n = s.find('o');
		while (n < len)
		{
			n = s.find('o', n + 1);			
			++count;
		}			
	}
	std::cout << count;
	return 0;
}