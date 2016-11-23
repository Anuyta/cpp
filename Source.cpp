//#include <iostream>
//
//class Array
//{
//private:
//	int* arr;
//	int size;
//
//public:
//	Array(int size_, int value)
//		: Array(size_)
//	{
//		std::cout << " Array(int size_, int value)\n ";
//		for (int i = 0; i < size; ++i)
//			arr[i] = value;
//	}
//
//	Array(int size_)
//		: arr{ new int[size_] }, size{ size_ }
//	{
//		std::cout << "Array(int size_)\n ";
//	}
//
//	int& Index(int index)
//	{
//		if (index < 0 || index >= size)
//		{
//			std::cout << "Invalid index: " << index << ". Return last element." << std::endl;
//			return arr[size - 1];
//		}
//		return arr[index];
//	}
//
//	int getSize()
//	{
//		return size;
//	}
//
//	~Array()
//	{
//		delete[] arr;
//	}
//};
//
//int main()
//{
//	Array arr(16, 10);
//	for (int i = 0; i < arr.getSize(); ++i)
//		std::cout << arr.Index(i) << " ";
//	std::cout << std::endl;
//
//	for (int i = 0; i < arr.getSize(); ++i)
//		arr.Index(i) = i;
//
//
//	return 0;
//}


#include <iostream>

class Array
{
private:
	int* arr;
	int size;

public:
	Array(int size_, int value)
		: Array(size_)
	{
		//std::cout << " Array(int size_, int value)\n ";
		for (int i = 0; i < size; ++i)
			arr[i] = value;
	}

	Array(int size_)
		: arr{ new int[size_] }, size{ size_ }
	{
		//std::cout << "Array(int size_)\n ";
	}

	Array(const Array& obj)
		: Array(obj.size)
	{
		for (int i = 0; i < size; ++i)
			arr[i] = obj.arr[i];
	}

	int& Index(int index)
	{
		if (index < 0 || index >= size)
		{
			std::cout << "Invalid index: " << index << ". Return last element." << std::endl;
			return arr[size - 1];
		}
		return arr[index];
	}

	int getSize()
	{
		return size;
	}

	Array getCopy()
	{
		return *this;
	}

	~Array()
	{
		std::cout << "~Array()\n ";
		delete[] arr;
	}
};

int main()
{
	Array arr(16, 10);

	for (int i = 0; i < arr.getSize(); ++i)
		arr.Index(i) = i;

	std::cout << "// print arr\n";
	for (int i = 0; i < arr.getSize(); ++i)
		std::cout << arr.Index(i) << " ";
	std::cout << std::endl;

	Array arr1 = arr.getCopy();
	for (int i = 0; i < arr1.getSize(); ++i)
		arr1.Index(i) = i + 1;

	std::cout << "// print arr1\n";
	for (int i = 0; i < arr1.getSize(); ++i)
		std::cout << arr1.Index(i) << " ";
	std::cout << std::endl;

	std::cout << "// print arr\n";
	for (int i = 0; i < arr.getSize(); ++i)
		std::cout << arr.Index(i) << " ";
	std::cout << std::endl;

	return 0;
}



//#include <iostream>
//
//class A
//{
//	int a1;
//public:
//	A(const A& obj)
//	{
//		std::cout << "A(const A& obj)\n";
//	}
//
//	A()
//	{		
//		std::cout << "AAA\n";
//
//	}//конструктор по умолчанию
//	~A()
//	{
//		std::cout << "~AAA\n";
//	}
//	//~A() = default;  //деструктор по умолчанию
//};
//
//class B
//{
//	int b;
//	A a;
//
//public:		
//	B(const B& b) 
//		: a{b.a}
//	{
//		std::cout << "B(const B& obj)\n";		
//	}
//	B()
//	{
//		std::cout << "BBB\n";
//	}/* = default;*/
//	//~B() = default;
//	~B()
//	{
//		std::cout << "~BBB\n";
//	}
//};
//
//int main()
//{
//	B b;
//	B b1 = b;
//}