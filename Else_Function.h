#pragma once
#include "Else.h"
int Abs(int &a)
{
	if (a <= 0)
		return -a;
	else
		return a;
}

int Max(int a, int b)
{
	return a >= b ? a : b;
}

int Min(int a, int b)
{
	return a <= b ? a : b;
}

int Com_divisor_max(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return 1;
	}
	int max(0);
	int min(0);
	max = Max(a, b);
	min = Min(a, b);
	int temp(0);
	temp = max % min;
	if (temp == 0)
		return min;
	else
		return Com_divisor_max(min, temp);
}

int Com_multiple_min(int a, int b)
{
	int multiple(1);
	multiple = a * b;
	int com_div(1);
	com_div = Com_divisor_max(a, b);
	int temp(1);
	temp = multiple / com_div;
	return temp;
}

int power(int a, int n)
{
	int temp(1);
	if (n == 0)
	{
		if (a == 0)
			throw a;
		else
			return 1;
	}
	else
	{
		for (int k(0); k < n; k++)
		{
			temp *= a;
		}
		return temp;
	}
}

std::string Int_to_string(int a)
{
	std::string Int_string("");
	int pw(0);
	if (a == 0)
		Int_string = "0";
	if (a == 1)
		Int_string = "1";
	else
	{
		std::deque<char> Int_char;
		while (a >= power(10,pw))
		{
			++pw;
		}
		for (int k(1); k <= pw; k++)
		{
			char temp(0);
			char number('0');
			temp = a % 10;
			number += temp;
			Int_char.push_front(number);
			a -= temp;
			a /= 10;
		}
		for (std::deque<char>::iterator iter = Int_char.begin(); iter != Int_char.end(); iter++)
		{
			Int_string += *iter;
		}
	}
	return Int_string;
}