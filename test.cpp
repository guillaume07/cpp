#include "stdafx.h"
#include <iostream>
#include <array>
#include <string> 
#include <bitset> 
#include <cmath> 
#include <vector> 
#include <iterator>  

void f(int&& l){}

void main()
{
	int d;
	f(std::move(d));
	std::cin.ignore(); 
}

