#include <iostream>
using namespace std;

class TransportStrategy
{
public:
	virtual void drive() = 0;
};
class BikeStrategy : public TransportStrategy
{
public:
	void drive() override
	{
		if (getSum())
	}
};

class Human
{
protected:
	double sum;
	bool luggage;
public:
	Human(double s, bool l) : sum(s), luggage(l) {}
	double getSum()
	{
		return sum;
	}
	bool getLuggage()
	{
		return luggage;
	}
};

int main()
{

	return 0;
}