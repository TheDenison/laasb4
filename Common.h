#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <iomanip> 
#include <cstring>
#include <windows.h>
#include "Date.h"
using namespace std;

class Date;
class delivery1;
class delivery2;


class Common
{
protected:
	double balance;
	Date date;
public:
	friend class Date;
	friend class delivery1;
	friend class delivery2;
	static int n_Common;
	Common();
	void set_balance(double a) { balance = a; };
	double get_balance() { return balance; };
	void print_menu();
	int scan_flag();
	int scan_double();
	int scan_int();
	int scan_type();
	void scan_month(char* a);

};

