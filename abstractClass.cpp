#include <iostream>
#include <cmath>

class Figure
{
public:
	virtual double area() = 0;	

	virtual ~Figure()
	{
		std::cout << "~Figure" << std::endl;
	}
};

class Triangle : public Figure
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;

public:
	Triangle() = default;

	Triangle(double a_, double b_, double c_) :
		a{ a_ }, b{ b_ }, c{ c_ }
	{
	}

	double area()
	{
		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}

	~Triangle()
	{
		std::cout << "~Triangle" << std::endl;
	}
};

class Quadrate : public Figure
{
	double a = 0.0;

public:
	Quadrate() = default;

	Quadrate(double a_) :
		a{ a_ }
	{
	}

	double area()
	{
		return a*a;
	}

	~Quadrate()
	{
		std::cout << "~Quadrate" << std::endl;
	}
};

class Rectangle : public Figure
{
	double a = 0.0;
	double b = 0.0;

public:
	Rectangle() = default;

	Rectangle(double a_, double b_) :
		a{ a_ }, b{ b_ }
	{
	}

	double area()
	{
		return a*b;
	}

	~Rectangle()
	{
		std::cout << "~Rectangle" << std::endl;
	}
};

class Rhombus : public Figure
{
	double d1;
	double d2;

public:
	Rhombus(double d1_, double d2_) :
		d1{ d1_ }, d2{ d2_ }
	{
	}

	double area()
	{
		return (d1*d2) / 2;
	}
};

void printArea(Figure* fig)
{
	std::cout << fig->area() << std::endl;
}

int main()
{
	Figure* tr = new Triangle(2.2, 5.1, 3.0);
	Figure* quad = new Quadrate(2.2);
	Figure* rec = new Rectangle(2.2, 5.1);
	printArea(tr);
	printArea(quad);
	printArea(rec);
	delete tr;
	delete quad;
	delete rec;
	return 0;
}