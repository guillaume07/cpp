#include "stdafx.h" 
#include <iostream>
#include <type_traits>
#include <string>

struct OnlyMovable
{
	int * nb;
	std::string _name;
	OnlyMovable(std::string name) :_name(std::move(name))
	{
		nb = new int[5]{1, 2, 4, 5, 4};
	}

	OnlyMovable(OnlyMovable&& foo)
	{
		std::cout << "OnlyMovable&&" << "\n";
	};

	OnlyMovable& operator=(OnlyMovable /*&&*/ foo) //uncomment to skip call to move ctor
	{
		std::swap(nb, foo.nb);
		return *this;
	};

	~OnlyMovable()
	{
		std::cout << _name << "\n";

		if (_name == "foo1")
			std::cin.ignore();
	}
};

int main()
{
	OnlyMovable foo1("foo1");

	foo1 = OnlyMovable("foo");
}
