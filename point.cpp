//#include <iostream>
//#include <cmath>
//
//class Point
//{	
//	float x = 0.0f;
//	float y = 0.0f;
//	float z = 0.0f;
//public:
//	Point() = default;
//
//	Point(float value_x, float value_y, float value_z) : x{ value_x }, y{ value_y }, z{ value_z }
//	{		
//	}
//
//	Point(const Point& pnt) = default; //т.к. все поля стандартного типа
//	//Point(const Point& pnt)
//	//	: Point(pnt.x, pnt.y, pnt.z)
//	//{
//	//	//std::cout << "constructor" << std::endl;
//	//}
//
//	~Point() = default;
//
//	friend std::ostream& operator<<(std::ostream& os, const Point& pnt);
//	friend std::istream& operator>>(std::istream& is, Point& pnt);
//
//	Point& operator=(const Point& pnt) = default;
//	//const Point& operator=(const Point& pnt)
//	//{
//	//	//std::cout << "operator" << std::endl;
//	//	x = pnt.x;
//	//	y = pnt.y;
//	//	z = pnt.z;
//	//	return *this;
//	//}
//
//	const Point& operator+(int value)
//	{
//		x += value;
//		y += value;
//		z += value;
//		return *this;
//	}
//
//	bool operator==(const Point& pnt)
//	{
//		return pnt.x == x && pnt.y == y && pnt.z == z;		
//	}
//
//	bool operator!=(const Point& pnt)
//	{
//		return !operator==(pnt); //!(this->pnt);
//	}
//
//	float findLength(const Point& b) const
//	{
//		return sqrt(pow((b.x - x), 2) + pow((b.y - y), 2) + pow((b.z - z), 2));
//	}	
//	
//};
//
//std::ostream& operator<<(std::ostream& os, const Point& pnt)
//{	
//	os << "x = " << pnt.x << " y = " << pnt.y << " z = " << pnt.z << std::endl;
//	return os;
//}
//
//std::istream& operator>>(std::istream& is, Point& pnt)
//{	
//	is >> pnt.x >> pnt.y >> pnt.z;
//	return is;
//}
//
//int main()
//{
//	Point a(1.1, 1.3, 1.5);
//	Point b(3.1, 4.3, 1.5);
//	Point c = a;
//	std::cout << "Coordinate c " << c;
//	Point d;
//	std::cout << "Coordinate d " << d;
//	d = a;
//	std::cout << "Coordinate d " << d;
//	//Point f = a; //copy constructor
//	//std::cout << "the distance between two points = " << a.findLength(b) << std::endl;
//	//c = a; //copy operator
//	//std::cout << "Coordinate c " << c;
//	////std::cin >> d;
//	//d = c + 3;
//	//std::cout << "Coordinate d " << d;
//	//std::cout << "c != d " << (c != d) << std::endl;
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

	Array(Array&& obj) : arr{ obj.arr }, size{obj.size}
	{
		obj.arr = nullptr;
		obj.size = 0;
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

	Array(const std::initializer_list<int>& lst)
		:Array(lst.size())
	{
		int i = 0;
		for (const int& el : lst)
			arr[i++] = el;
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

//Array operator+(const Array&a, const Array&b) //global function
//{
//	Array c(a.size + b.size);
//	for (int i = 0; i < a.size; ++i)
//		c.arr[i] = a.arr[i];
//	for (int i = a.size; i < c.size; ++i)
//		c.arr[i] = b.arr[i - a.size];
//	return c;
//}
//
//std::ostream& operator<<(std::ostream& os, const Array& arr)
//{
//	for (int i = 0; i < arr.getSize(); ++i)
//		os << arr[i] << " ";
//	return os;
//}
//
//std::istream& operator>>(std::istream& is, Array& arr)
//{
//	for (int i = 0; i < arr.getSize(); ++i)
//		is >> arr[i];
//	return is;
//}

int main()
{
	Array arr1(6, 10);
	std::cout << arr1 << std::endl;
	Array arr2(10, 5);
	std::cout << arr2 << std::endl;
	arr2 = arr1;
	std::cout << arr1 << std::endl;
	arr1 = arr1;
	std::cout << arr1 << std::endl;
	Array x = { 1, 2, 3 };
	std::cout << x << std::endl;
	return 0;
}