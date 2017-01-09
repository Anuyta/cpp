#include <iostream>

class computer
{
protected:
	char* cpu;
	int valueMemory;	
	int energyConsumption; //энергопотребление

public:
	char model;
	computer()
	{
		//std::cout << "computer\n";
	}
	~computer()
	{
		//std::cout << "~computer\n";
	}

	virtual void show() 
	{
		std::cout << "show computer\n";
	}
};

class server : public computer
{
	char* kind;

public:	
	server()
	{
		//std::cout << "server\n";
	}
	~server()
	{
		//std::cout << "~server\n";
	}

	void show() 
	{
		std::cout << "show server\n";
	}
};

class laptop : public computer
{
	int batteryVolume;

public:
	laptop()
	{
		//std::cout << "laptop\n";
	}
	~laptop()
	{
		//std::cout << "~laptop\n";
	}

	void show() 
	{
		std::cout << "show laptop\n";
	}
};

void doShow(computer* comp)
{
	//((laptop*)&comp)->show();
	comp->show();
}


int main()
{
	/*laptop lap;
	doShow(lap);

	server s;
	doShow(s);*/

	computer* c = new laptop();
	doShow(c);

	return 0;
}