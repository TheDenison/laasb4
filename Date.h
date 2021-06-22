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
using namespace std;

class Common;

class Date {
protected:
    int day;            //день
    char* month;        //месяц
    int year;           //год
public:
    friend class Common;
    friend class delivery1;
    friend class delivery2;
    Date();             //конструктор по-умолчанию
    ~Date();            //деструктор

    int get_day() { return day; };
    char* get_month() { return month; };
    int get_year() { return year; };

    void set_day(int a) { day = a; };
    void set_month(char* a) {
        delete[] month;
        month = new char[strlen(a) + 1];
        strcpy(month, a);
    };
    void set_year(int a) { year = a; };

    friend istream& operator>>(istream& is, class delivery1& t);
    friend istream& operator>>(istream& is, class delivery2& t);

};

