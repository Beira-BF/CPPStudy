#pragma once
#include <iostream>
#include <string>
#include "Else_Function.h"
using namespace std;
class Ra_Nu
{
	Ra_Nu friend operator+ (const Ra_Nu &, int);
	Ra_Nu friend operator+ (int, const Ra_Nu &);
	Ra_Nu friend operator- (const Ra_Nu &, int);
	Ra_Nu friend operator- (int, const Ra_Nu &);
	Ra_Nu friend operator* (const Ra_Nu &, int);
	Ra_Nu friend operator* (int, const Ra_Nu &);
	Ra_Nu friend operator/ (const Ra_Nu &, int);
	Ra_Nu friend operator/ (int, const Ra_Nu &);
	Ra_Nu friend operator+= (const Ra_Nu &, int);
	Ra_Nu friend operator+= (int, const Ra_Nu &);
	Ra_Nu friend operator-= (const Ra_Nu &, int);
	Ra_Nu friend operator-= (int, const Ra_Nu &);
	Ra_Nu friend operator*= (const Ra_Nu &, int);
	Ra_Nu friend operator*= (int, const Ra_Nu &);
	Ra_Nu friend operator/= (const Ra_Nu &, int);
	Ra_Nu friend operator/= (int, const Ra_Nu &);
	bool friend operator== (const Ra_Nu &, int);
	bool friend operator== (int, const Ra_Nu &);
	bool friend operator>= (const Ra_Nu &, int);
	bool friend operator>= (int, const Ra_Nu &);
	bool friend operator<= (const Ra_Nu &, int);
	bool friend operator<= (int, const Ra_Nu &);
	bool friend operator> (const Ra_Nu &, int);
	bool friend operator> (int, const Ra_Nu &);
	bool friend operator< (const Ra_Nu &, int);
	bool friend operator< (int, const Ra_Nu &);
public:
	Ra_Nu()
	{
		sign = false;
		den = 1;
		num = 0;
	}

	void Get_Ra_Nu(const string &ra);
	void Ra_Nu_simplification();
	void Ra_Nu_display();
	operator int();
	operator double();
	operator string();
	void Int_to_Ra_Nu(int);
	Ra_Nu operator+(Ra_Nu ra);
	Ra_Nu operator-(Ra_Nu ra);
	Ra_Nu operator-();
	Ra_Nu operator*(Ra_Nu);
	Ra_Nu operator/(const Ra_Nu &);
	bool operator>(const Ra_Nu &);
	bool operator<(const Ra_Nu &);
	bool operator>=(const Ra_Nu &);
	bool operator<=(const Ra_Nu &);
	bool operator==(const Ra_Nu &);
	bool operator!=(const Ra_Nu &);
	//string operator<<(const Ra_Nu &);
	//Ra_Nu operator>>(const string &);
	void operator=(const Ra_Nu &);
	void operator=(int);
	void operator=(const string &);
	void operator+=(const Ra_Nu &);
	void operator*=(const Ra_Nu &);
	void operator-=(const Ra_Nu &);
	void operator/=(const Ra_Nu &);
	Ra_Nu Ra_Nu_power(const Ra_Nu &,int);
private:
	int den;
	int num;
	bool sign;
};