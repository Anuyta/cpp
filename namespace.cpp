#include <iostream>

class A
{
public:
	A() = default;

	virtual void func() const
	{		
	}

	virtual char test() = 0;

	virtual ~A() = default;
};

class B : public A
{
public:
	B() = default;

	char test()
	{
		return 'b';
	}
	void func() const override
	{
		std::cout << "class B\n";
	}

	~B() = default;
};

class C : public A
{
public:
	C() = default;

	char test()
	{
		return 'c';
	}

	void func() const override
	{
		std::cout << "class C\n";
	}

	~C() = default;
};

class D : public A
{
public:
	D() = default;

	char test()
	{
		return 'd';
	}

	void func() const override
	{
		std::cout << "class D\n";
	}

	~D() = default;
};

void doFunc(A* a)
{	
	a->func();
	if (a->test() == 'c')
		std::cout << "I'm object C\n";
}

int main()
{
	A* a = new B();
	A* a1 = new C();
	//doFunc(a);
	//doFunc(a1);

	std::cout << typeid(A).name();
	delete a;
	delete a1;
	return 0;
}