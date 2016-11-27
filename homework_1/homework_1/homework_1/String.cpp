#include <iostream>

class String
{
private:
	char* str_;
	int size_;

public:
	String(const char* str)
		: str_{ new char[strlen(str) + 1] }, size_{ strlen(str) + 1 }
	{
		strcpy_s(str_, size_, str);
	}

	char* returnString();
	int getSize();
	void changeString(const char* str);
	void addToString(const char* str);
	char insertSymbol(int index, const char symbol);
	void printAnsiiCods();
	void upperString();
	void lowString();

	~String()
	{
		delete[] str_;
	}
};

char* String::returnString()
{
	return str_;
}

inline int String::getSize()
{
	return strlen(str_);
}

void String::changeString(const char* str)
	
{
	delete[] str_;
	size_ = strlen(str) + 1;
	str_ = new char[size_];
	strcpy_s(str_, size_, str);
}

void String::addToString(const char* str)
{
	size_ += strlen(str);
	char* strT = new char[size_];
	strcpy_s(strT, size_, str_);
	strcat_s(strT, size_, str);
	delete[] str_;
	str_ = strT;
}

char String::insertSymbol(int index, const char symbol)
{
	if (index < 0 || index >= size_ - 1)
	{
		std::cout << "Invalid index: " << index << ". Last available index = " << size_ - 2 << std::endl;
		return 0;
	}
	++size_;
	char* strT = new char[size_];	
	strncpy_s(strT, size_, str_, index + 1);
	strT[index] = symbol;
	strcat_s(strT, size_, &str_[index]);
	delete[] str_;
	str_ = strT;
}

void String::printAnsiiCods()
{
	for (int i = 0; str_[i] != '\0'; ++i)
		std::cout << (int)str_[i] << " ";
}

void String::upperString()
{
	for (int i = 0; i < size_; ++i)	
		str_[i] = toupper(str_[i]);
}

void String::lowString()
{
	for (int i = 0; i < size_; ++i)	
		str_[i] = tolower(str_[i]);
}

int main()
{
	String str("abcddq");
	std::cout << str.returnString() << std::endl;
	str.changeString("ajknwEgf");
	std::cout << str.returnString() << std::endl;
	str.addToString("zzzy");
	std::cout << str.returnString() << std::endl;
	str.insertSymbol(12, 'X');
	std::cout << str.returnString() << std::endl;
	str.printAnsiiCods();
	str.upperString();
	std::cout << std::endl;
	std::cout << str.returnString() << std::endl;
	str.lowString();
	std::cout << str.returnString() << std::endl;
	return 0;
}