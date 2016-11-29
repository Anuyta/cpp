//#include <iostream>
//
//class Array
//{
//	int* arr;
//	int size_;
//
//public:
//	Array(int size, int value)
//		: Array(size) //ÄÅËÅÃÈĞÎÂÀÍÈÅ
//	{
//		std::cout << "Array(int size_, int value)\n";
//		//arr = new int[size];
//		//size_ = size;
//		//Array(size_);//ñîçäàåòñÿ áåçûìÿííûé îáúåêò
//		for (int i = 0; i < size; ++i)
//			arr[i] = value;
//	}
//
//	Array(int size) : arr{ new int[size] }, size_{ size }
//	{
//		std::cout << "Array(int size_)\n";
//		/*arr = new int[size];
//		size_ = size;*/
//	}	
//
//	int getSize()
//	{
//		return size_;
//	}
//
//	Array getCopy()
//	{
//		return *this;
//	}
//
//	Array(const Array& obj)
//		:Array{obj.size_}
//	{
//		for (int i = 0; i < size_; ++i)		
//			arr[i] = obj.arr[i];
//	}
//
//	int& Index(int index)
//	{
//		if (index < 0 && index > size_)
//		{
//			std::cout << "Invalid index " << index << ". Return last element " << std::endl;
//			return arr[size_ - 1];
//		}
//		return arr[index];
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
//	/*for (int i = 0; i < arr.getSize(); ++i)
//		std::cout << arr.Index(i) << " ";
//	std::cout << std::endl;
//*/
//	for (int i = 0; i < arr.getSize(); ++i)
//		arr.Index(i) = i;
//
//	Array arr1 = arr.getCopy();
//	for (int i = 0; i < arr1.getSize(); ++i)
//		arr1.Index(i) = i + 1;
//	for (int i = 0; i < arr1.getSize(); ++i)
//		std::cout << arr1.Index(i) << " ";
//	std::cout << std::endl;
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
			arr[i] = obj.Index(i);

		//obj.setElement(1, 10);
	}

	//Array(int* obj) //constructor where first elem is size of array 
	//	: Array(obj[0])
	//{	
	//	std::cout << "Array(int*, int sizze)\n ";
	//	for (int i = 0; i < size; ++i)		
	//		arr[i] = obj[i + 1];			
	//}

	Array(int* obj, int sizze)
		: Array(sizze)
	{
		//std::cout << "Array(int*, int sizze)\n ";
		for (int i = 0; i < sizze; ++i)
			arr[i] = obj[i];
	}

	int& Index(int index) const
	{
		if (index < 0 || index >= size)
		{
			//std::cout << "Invalid index: " << index << ". Return last element." << std::endl;
			return arr[size - 1];
		}
		return arr[index];
	}

	int getSize() const
	{
		return size;
	}

	Array getCopy()
	{
		return *this;
	}

	void setElement(int index, int value)
	{
		if (index >= 0 || index < size)
		{
			arr[index] = value;
		}
		else
			std::cout << "Invalid index: " << index << std::endl;
	}

	int& operator[](int b) const
	{
		return Index(b);
	}

	/*Array operator+(const Array& obj)
	{
		Array result(obj.size + size);
		for (int count = 0; count < size; ++count)
			result[count] = arr[count];

		for (int count = size; count < result.size; ++count)
			result[count] = obj.arr[count - size];

		return result;
	}	*/

	friend Array operator+(const Array&a, const Array&b);

	const Array& operator=(const Array& obj)//copy operator		
	{	
		if (&obj != this)
		{
			delete[] arr;
			arr = new int[obj.size];
			size = obj.size;
			for (int i = 0; i < size; ++i)
				arr[i] = obj.arr[i];			
		}	
		return *this;
	}

	~Array()
	{
		//std::cout << "\n~Array()\n ";
		delete[] arr;
	}
};

Array operator+(const Array&a, const Array&b) //global function
{
	Array c(a.size + b.size);
	for (int i = 0; i < a.size; ++i)
		c.arr[i] = a.arr[i];
	for (int i = a.size; i < c.size; ++i)
		c.arr[i] = b.arr[i - a.size];
	return c;
}

std::ostream& operator<<(std::ostream& os, const Array& arr)
{
	for (int i = 0; i < arr.getSize(); ++i)
		os << arr[i] << " ";
	return os;
}

std::istream& operator>>(std::istream& is, Array& arr)
{
	for (int i = 0; i < arr.getSize(); ++i)
		is >> arr[i];
	return is;
}

int main()
{		
	/*int arr1[] = { 6, 1, 2, 0, 9, 3, 4 };
	int arr2[3] = { 0, 3, 2 };
	int arr3[5];

	Array a1(arr1, 7);	
	Array a2(arr2, 3);
	Array c = a1 + a2;
	for (int i = 0; i < c.getSize(); ++i)
		std::cout << c[i] << " ";
	std::cout << std::endl;*/

	/*int a[5] = { 1, 2 };
	int a1[5];
	Array arr(a, 5);
	std::cout << arr << std::endl;
	
	Array arr1(a1, 5);
	std::cin >> arr1;
	std::cout << arr1 << std::endl;*/

	Array arr1(6, 10);
	std::cout << arr1 << std::endl;
	Array arr2(10, 5);
	std::cout << arr2 << std::endl;
	arr2 = arr1;
	std::cout << arr1 << std::endl;
	arr1 = arr1;
	std::cout << arr1 << std::endl;
	return 0;
}