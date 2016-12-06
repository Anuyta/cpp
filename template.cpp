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

	Array(int* obj) //constructor where first elem is size of array 
		: Array(obj[0])
	{	
		std::cout << "Array(int*, int sizze)\n ";
		for (int i = 0; i < size; ++i)		
			arr[i] = obj[i + 1];			
	}

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

	/*Array operator+=(const Array& obj)
	{
		
	}*/	

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

template <typename T> //внешнее сложение
T sum(T a, T b)
{
	return a + b;
}

template <typename T>
int binarySearch(T* a, int left, int right, T key)
{	
	int middle = left + (right - left) / 2;
	if (left == right && key!= a[left])
		return -1;	
	if (a[middle] == key)
		return middle;
	else if (key < a[middle])
		return binarySearch(a, left, middle, key);
	else
		return binarySearch(a, middle + 1, right, key);		
	return -1;
}

int main()
{	
	/*Array arr1(6, 10);
	std::cout << arr1 << std::endl;
	Array arr2(10, 5);
	std::cout << arr2 << std::endl;*/
	/*arr2 = arr1;
	std::cout << arr1 << std::endl;
	arr1 = arr1;
	std::cout << arr1 << std::endl; */

	int arr1[] = { -3, 1, 5, 5, 5, 9, 13, 14 };		
	std::cout << binarySearch(arr1, 0, 6, 14) << std::endl;
	int arr2[] = { -3};
	std::cout << binarySearch(arr2, 0, 0, -3) << std::endl;
	return 0;
}