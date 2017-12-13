#include "money.h"

int money_t::get_dollars( )
{
	return dollars;
}

int money_t::get_cents()
{
	return cents;
}

void money_t::set_dollars(int dollars_amt)
{
	if (dollars_amt < 0)
		dollars = 0;
	else
		dollars = dollars_amt;
}

void money_t::set_cents(int cents_amt)
{
	if (cents_amt < 0)
		cents = 0;
	else
		cents = cents_amt;
}

void money_t::set(int dollar_amt, int cent_amt)
{
	//if (dollar_amt < 0)
	//	dollars = 0;
	//else
		dollars = dollar_amt;

	//if (cent_amt < 0)
	//	cents = 0;
	//else
		cents = cent_amt;
}

int money_t::value_in_cents()
{
	int money;
	money = dollars * 100;
	money = money + cents;

	return money;
}

double money_t::compute_value()
{
	double money;
	money = dollars;
	//cents is still an int unless changed
	money = money + (double)cents/100;
	return money;
}


money_t::money_t()
{
	dollars = 0;
	cents = 0;
}


money_t::money_t(double amt)
{
	if (amt < 0)
	{
		amt = 0;
	}
	else
	{
		dollars = (int)amt;
		cents = (amt-dollars)*100;
	}
}

money_t::money_t(int d, int c)
{
	if (dollars < 0)
	{
		dollars = 0;
	}
	else if (cents < 0)
	{
		cents = 0;
	} 
	else
	{
		dollars = d; 
		cents = c;
	}	
}

money_t::~money_t()
{
	cout << "destructor invoked" << endl;
}

