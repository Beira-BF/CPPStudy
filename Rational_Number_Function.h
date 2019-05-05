#pragma once
#include "Rational_Number.h"
#include "Else_Function.h"
/*-------------------------------------------------有理数类的类型转换的实现------------------------------------------------------*/
Ra_Nu::operator int()
{
	int temp(0);
	if (sign)
		temp = -num / den;
	else
		temp = num / den;
	return temp;
}

void Ra_Nu::Int_to_Ra_Nu(int a)
{
	if (a < 0)
		this->sign = true;
	else
	{
		this->sign = false;
		this->den = 1;
		this->num = Abs(a);
	}
}

Ra_Nu::operator double()
{
	double temp(0.0);
	if (sign)
		temp = -num / den;
	else
		temp = num / den;
	return temp;
}

Ra_Nu::operator string()
{
	string Ra_string("");
	if (this->sign)
		Ra_string += "-";
	Ra_string += Int_to_string(this->num);
	Ra_string += "/";
	Ra_string += Int_to_string(this->den);
	return Ra_string;
}
/*-------------------------------------------------有理数类的类型转换实现完成-------------------------------------------------------*/

/*------------------------------------------------有理数类的赋值操作符的重载--------------------------------------------------------*/
void Ra_Nu::operator=(int a)
{
	if (a < 0)
		this->sign = true;
	else
		this->sign = false;
	this->num = Abs(a);
	this->den = 1;
}

void Ra_Nu::operator=(const string &Ra_string)
{
	this->Get_Ra_Nu(Ra_string);
}

void Ra_Nu::operator=(const Ra_Nu &ra1)
{
	this->sign = ra1.sign;
	this->den = ra1.den;
	this->num = ra1.num;
}

Ra_Nu Ra_Nu::operator-()
{
	Ra_Nu ra;
	ra = *this;
	ra.sign = !ra.sign;
	return ra;
}
/*----------------------------------------------有理数类的赋值操作符实现完成---------------------------------------------------------*/

void Ra_Nu::Get_Ra_Nu(const string &ra)
{
	int n(0);
	n = ra.size();
	vector<char> ra_g;
	for (int k(0); k < n; k++)
	{
		char r = ra[k];
		ra_g.push_back(r);
	}
	int j(0);
	int s(0);
	char test(0);
	test = ra_g[0];
	if (test == '0')
	{
		sign = false;
		this->num = 0;
		this->den = 1;
	}
	else
	{
		if (ra_g[0] == '-')
		{
			s = 1;
			sign = true;
		}
		else
		{
			s = 0;
			sign = false;
		}
		while (test != '/')
		{
			j++;
			test = ra_g[j];
		}
		this->num = 0;
		this->den = 0;
		char zero('0');
		for (int k = s; k < j; k++)
		{
			int temp(0);
			temp = ra_g[k] - zero;
			num += temp * power(10, j - k - 1);
		}
		for (int k = j + 1; k < n; k++)
		{
			int temp(0);
			temp = ra_g[k] - zero;
			den += temp * power(10, n - k - 1);
		}
	}
	this->Ra_Nu_simplification();
}

void Ra_Nu::Ra_Nu_display()
{
	if (sign)
		cout << '-';
	cout << this->num << '/' << this->den << endl;
}

void Ra_Nu::Ra_Nu_simplification()
{
	int com_div_max(1);
	com_div_max = Com_divisor_max(this->num, this->den);
	this->num /= com_div_max;
	this->den /= com_div_max;
	if (num == 0)
		this->sign = false;
}

/*----------------------------------------------有理数类的算术运算操作符的重载----------------------------------------------------*/
Ra_Nu Ra_Nu::operator+(Ra_Nu ra1)
{
	Ra_Nu ra;
	if (this->sign == ra1.sign)
	{
		ra.sign = this->sign;
		int den1(1);
		den1 = Com_multiple_min(this->den, ra1.den);
		ra.den = den1;
		this->num = this->num * den1 / this->den;
		this->den = den1;
		ra1.num = ra1.num * den1 / ra1.den;
		ra1.den = den1;
		ra.num = this->num + ra1.num;
	}
	else
	{
		int den1(1);
		int num1(0);
		int num2(0);
		num1 = this->num;
		num2 = ra1.num;
		den1 = Com_multiple_min(this->den, ra1.den);
		ra.den = den1;
		num1 = num1 * den1 / this->den;
		num2 = num2 * den1 / ra1.den;
		if (num1 >= num2)
		{
			ra.sign = this->sign;
		}
		else
		{
			ra.sign = ra1.sign;
		}
		int num_max(0);
		num_max = Max(num1, num2);
		int num_min(0);
		num_min = Min(num1, num2);
		ra.num = num_max - num_min;
	}
	ra.Ra_Nu_simplification();
	this->Ra_Nu_simplification();
	ra1.Ra_Nu_simplification();
	return ra;
}

Ra_Nu Ra_Nu::operator-(Ra_Nu ra1)
{
	Ra_Nu ra;
	Ra_Nu ra_this = *this;
	Ra_Nu ra_ra1 = ra1;
	ra_ra1 = -ra_ra1;
	ra = ra_this + ra_ra1;
	return ra;
}

Ra_Nu Ra_Nu::operator*(Ra_Nu ra1)
{
	Ra_Nu ra;
	if (this->sign == ra1.sign)
		ra.sign = false;
	else
		ra.sign = true;
	ra.num = this->num * ra1.num;
	ra.den = this->den * ra1.den;
	ra.Ra_Nu_simplification();
	return ra;
}

Ra_Nu Ra_Nu::operator/(const Ra_Nu &ra1)
{
	Ra_Nu ra;
	Ra_Nu ra_ra1;
	ra_ra1.sign = ra1.sign;
	ra_ra1.den = ra1.num;
	ra_ra1.num = ra1.den;
	ra = *this * ra_ra1;
	return ra;
}

void Ra_Nu::operator+=(const Ra_Nu &ra1)
{
	*this = *this + ra1;
}

void Ra_Nu::operator-=(const Ra_Nu &ra1)
{
	*this = *this - ra1;
}

void Ra_Nu::operator*=(const Ra_Nu &ra1)
{
	*this = *this * ra1;
}

void Ra_Nu::operator/=(const Ra_Nu &ra1)
{
	*this = *this / ra1;
}
/*--------------------------------------------有理数类的算术函数的操作符重载实现完成--------------------------------------------------------*/

/*----------------------------------------------有理数类的逻辑比较运算的操作符重载------------------------------------------------------*/
bool Ra_Nu::operator==(const Ra_Nu &ra1)
{
	if (this->sign != ra1.sign)
		return false;
	else
	{
		if (this->num == ra1.num && this->den == ra1.den)
			return true;
		else
			return false;
	}
}

bool Ra_Nu::operator!=(const Ra_Nu &ra1)
{
	return !(*this == ra1);
}

bool Ra_Nu::operator>(const Ra_Nu &ra1)
{
	if (this->sign != ra1.sign)
	{
		if (*this == ra1)
			return false;
		else
		{
			if (this->sign)
				return false;
			else
				return true;
		}
	}
	else
	{
		Ra_Nu Ra_this;
		Ra_Nu Ra_ra1;
		Ra_this = *this;
		Ra_ra1 = ra1;
		int den1(1);
		den1 = Com_divisor_max(Ra_this.den, Ra_ra1.den);
		Ra_this.num = Ra_this.num * den1 / Ra_this.den;
		Ra_this.den = den1;
		Ra_ra1.num = Ra_ra1.num * den1 / Ra_ra1.den;
		Ra_ra1.den = den1;
		if (this->sign)
		{
			if (Ra_this.num < Ra_ra1.num)
				return true;
			else
				return false;
		}
		else
		{
			if (Ra_this.num > Ra_ra1.num)
				return true;
			else
				return false;
		}
	}
}

bool Ra_Nu::operator<(const Ra_Nu &ra1)
{
	if (*this == ra1 || *this > ra1)
		return false;
	else
		return true;
}

bool Ra_Nu::operator>=(const Ra_Nu &ra1)
{
	return !(*this < ra1);
}

bool Ra_Nu::operator<=(const Ra_Nu &ra1)
{
	return !(*this > ra1);
}
/*----------------------------------------有理数类的逻辑比较运算的操作符重载实现完成---------------------------------------------*/

Ra_Nu Ra_Nu::Ra_Nu_power(const Ra_Nu &ra1, int a)
{
	Ra_Nu ra;
	if (a == 0)
	{
		ra = "0/1";
		return ra;
	}
	else
	{
		ra = ra1;
		for (int s = 1; s < a; s++)
		{
			ra *= ra1;
		}
		return ra;
	}
}