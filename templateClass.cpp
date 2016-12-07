//#include <iostream>
//
//template <class T>
//class Array
//{
//private:
//	T* arr;
//	int size;
//
//public:
//	Array(int size_, T value)
//		: Array(size_)
//	{
//		//std::cout << " Array(int size_, int value)\n ";
//		for (int i = 0; i < size; ++i)
//			arr[i] = value;
//	}
//
//	Array(int size_)
//		: arr{ new T[size_] }, size{ size_ }
//	{
//		//std::cout << "Array(int size_)\n ";
//	}
//
//	Array(const Array& obj)
//		: Array(obj.size)
//	{
//		for (int i = 0; i < size; ++i)
//			arr[i] = obj.Index(i);
//		//obj.setElement(1, 10);
//	}
//
//	Array(T* obj) //constructor where first elem is size of array 
//		: Array(obj[0])
//	{
//		std::cout << "Array(int*, int sizze)\n ";
//		for (int i = 0; i < size; ++i)
//			arr[i] = obj[i + 1];
//	}
//
//	Array(T* obj, int sizze) //copy constructor
//		: Array(sizze)
//	{
//		//std::cout << "Array(int*, int sizze)\n ";
//		for (int i = 0; i < sizze; ++i)
//			arr[i] = obj[i];
//	}
//
//	T& Index(int index) const
//	{
//		if (index < 0 || index >= size)
//		{
//			//std::cout << "Invalid index: " << index << ". Return last element." << std::endl;
//			return arr[size - 1];
//		}
//		return arr[index];
//	}
//
//	T getSize() const
//	{
//		return size;
//	}
//
//	T* getArr() const
//	{
//		return arr;
//	}
//
//	Array getCopy()
//	{
//		return *this;
//	}
//
//	void setElement(int index, int value)
//	{
//		if (index >= 0 || index < size)
//		{
//			arr[index] = value;
//		}
//		else
//			std::cout << "Invalid index: " << index << std::endl;
//	}
//
//	T& operator[](int b) const
//	{
//		return Index(b);
//	}
//
//	/*Array operator+(const Array& obj)
//	{
//		Array result(obj.size + size);
//		for (T count = 0; count < size; ++count)
//			result[count] = arr[count];
//
//		for (T count = size; count < result.size; ++count)
//			result[count] = obj.arr[count - size];
//
//		return result;
//	}	*/
//		
//	friend Array operator+(const Array& a, const Array& b);	
//	
//	friend Array
//		operator-(const Array& a, const Array& b);
//
//	Array operator=(const Array& obj)
//	{
//		if (&obj != this)//checking that the object does not point to itself
//		{
//			delete[] arr;
//			arr = new T[obj.size];
//			size = obj.size;
//			for (int i = 0; i < size; ++i)
//				arr[i] = obj.arr[i];
//		}
//		return *this;
//	}
//
//	template <typename T>
//	void quickSort(T*a, int last);
//
//	~Array()
//	{
//		//std::cout << "\n~Array()\n ";
//		delete[] arr;
//	}
//};
//
//template <class T>
//Array<T> operator+(const Array<T>& a, const Array<T>& b) //global function
//{
//	Array c(a.size + b.size);
//	for (int i = 0; i < a.size; ++i)
//		c.arr[i] = a.arr[i];
//	for (int i = a.size; i < c.size; ++i)
//		c.arr[i] = b.arr[i - a.size];
//	return c;
//}
//
//template <class T>
//Array<T> operator-(const Array<T>& a, const Array<T>& b) //global function
//{
//	Array c(a.size + b.size);
//	for (int i = 0; i < a.size; ++i)
//		c.arr[i] = a.arr[i];
//	for (int i = a.size; i < c.size; ++i)
//		c.arr[i] = b.arr[i - a.size];
//	return c;
//}
//
//template <class T>
//std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
//{
//	for (int i = 0; i < arr.getSize(); ++i)
//		os << arr[i] << " ";
//	return os;
//}
//
//template <class T>
//std::istream& operator>>(std::istream& is, Array<T>& arr)
//{
//	for (int i = 0; i < arr.getSize(); ++i)
//		is >> arr[i];
//	return is;
//}
//
//template <typename T> //внешнее сложение
//T sum(T a, T b)
//{
//	return a + b;
//}
//
//template <typename T>
//int binarySearch(T* a, int left, int right, T key)
//{
//	T middle = left + (right - left) / 2;
//	if (left == right && key != a[left])
//		return -1;
//	if (a[middle] == key)
//		return middle;
//	else if (key < a[middle])
//		return binarySearch(a, left, middle, key);
//	else
//		return binarySearch(a, middle + 1, right, key);
//	return -1;
//}
//
//template <typename T>
//void quickSort(T* a, int last)
//{
//	int left = 0, right = last;
//	decltype(a[0]) middle = a[last / 2];
//	do
//	{
//		while (a[left] < middle)
//			++left;
//
//		while (a[right] > middle)
//			--right;
//
//		if (left <= right)
//		{
//			std::swap(a[left], a[right]);
//			++left;
//			--right;
//		}
//	} while (left <= right);
//
//	if (right > 0)
//		quickSort(a, right);
//	if (last > left)
//		quickSort(a + left, last - left);
//}
//
//int main()
//{
//	int arr1[] = { -1, -1, -5, 5, 2, 1, -3, 2, -10 };
//	double arr2[] = { 2.2, 3.1, -2.3 };
//	/*std::cout << binarySearch(arr1, 0, 6, 14) << std::endl;
//	int arr2[] = { -3};
//	std::cout << binarySearch(arr2, 0, 0, -3) << std::endl;*/
//	Array<int> a(arr1, 9);
//	std::cout << a << std::endl;
//	Array<double> b(arr2, 3);
//	std::cout << b << std::endl;
//
//	Array<int> c(3, 9);
//	std::cout << c << std::endl;
//	quickSort(a.getArr(), a.getSize() - 1);
//	std::cout << a << std::endl;
//	return 0;
//}

#include <iostream>

class A
{	
public:
	int n = 0;
	A(int value) 
		: n{ value }
	{
	}
	A max(const A& a, const A& b);

	bool isGreitherThan(const A& b) const
	{
		return n > b.n;
	}	
};

template <class T>
T max(const T& a, const T& b)
{
	return a > b ? a : b;
}

template <>
A max(const A& a, const A& b)
{
	return a.isGreitherThan(b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const A& a)
{
	os << a.n << " ";
	return os;
}

std::istream& operator>>(std::istream& is, A& a)
{	
	is >> a.n;
	return is;
}

int main()
{
	int a = 3, b = 5;
	std::cout << max(a, b) << std::endl;
	A a1(3), b1(1);
	std::cout << max(a1, b1) << std::endl;
	return 0;
}