#include <iostream>
using namespace std;

class TransportStrategy
{
public:
	virtual void drive() = 0;
	virtual ~TransportStrategy() = default;
};
class BikeStrategy : public TransportStrategy
{
public:
	void drive() override
	{
		cout << "Bicycle selected" << endl;
	}
};
class BusStrategy : public TransportStrategy
{
public:
	void drive() override
	{
		cout << "Bus selected" << endl;
	}
};
class TaxiStrategy : public TransportStrategy
{
public:
	void drive() override
	{
		cout << "Taxi selected" << endl;
	}
};

class Human
{
protected:
	TransportStrategy* strategy;
	double sum;
	bool luggage;
public:
	Human(double s, bool l) : sum(s), luggage(l), strategy(nullptr) {}
	double getSum()
	{
		return sum;
	}
	bool getLuggage()
	{
		return luggage;
	}
	void setStrategy(TransportStrategy* strategy)
	{
		this->strategy = strategy;
	}
	void driveExecute()
	{
		if (strategy)
		{
			strategy->drive();
		}
		else
		{
			cout << "NO POSSIBLE OPTIONS!" << endl;
		}
	}
};

int main()
{
	cout << "- AVAILABLE VIHECLES -" << endl;
	cout << "1) Bike: price - 5, NO luggage" << endl;
	cout << "2) Bus: price - 50, luggage is ALLOWED" << endl;
	cout << "3) Taxi: price - 500, luggage is ALLOWED" << endl << endl;

	double money;
	cout << "Enter your amount of money" << endl;
	cout << "Money: ";
	cin >> money;

	bool isLuggage;
	cout << "Enter luggage information (1 - with luggage, 0 - without luggage)" << endl;
	cout << "Luggage: ";
	cin >> isLuggage;

	Human human = Human(money, isLuggage);
	BikeStrategy bike;
	BusStrategy bus;
	TaxiStrategy taxi;

	if (human.getSum() >= 500 && human.getLuggage() == 1)
	{
		human.setStrategy(&taxi);
	}
	else if (human.getSum() >= 50 && human.getLuggage() == 1)
	{
		human.setStrategy(&bus);
	}
	else if (human.getSum() >= 5 && human.getLuggage() == 0)
	{
		human.setStrategy(&bike);
	}
	human.driveExecute();
	return 0;
}