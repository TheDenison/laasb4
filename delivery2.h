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
#include "Common.h"
#include "FIO.h"
using namespace std;

class FIO; 

class delivery2 : public Common
{
private:
    FIO fio;

public:
    friend class FIO;
    static int n_delivery2;

    void print_tabl();
    void print_info(int i, delivery2* m);
    int month_in_digit(delivery2* m);

    delivery2& operator=(delivery2& m) {
        if (this->fio.firstname != nullptr) { delete[] this->fio.firstname; }
        if (this->fio.secondname != nullptr) { delete[] this->fio.secondname; }
        if (this->fio.lastname != nullptr) { delete[] this->fio.lastname; }
        if (this->date.month != nullptr) { delete[] this->date.month; }
        this->fio.firstname = new char[strlen(m.fio.firstname) + 1];
        this->fio.secondname = new char[strlen(m.fio.secondname) + 1];
        this->fio.lastname = new char[strlen(m.fio.lastname) + 1];
        this->date.month = new char[strlen(m.date.month) + 1];
        strcpy(this->fio.firstname, m.fio.get_firstname());
        strcpy(this->fio.secondname, m.fio.get_secondname());
        strcpy(this->fio.lastname, m.fio.get_lastname());
        this->set_balance(m.get_balance());
        this->date.set_day(m.date.get_day());
        strcpy(this->date.month, m.date.get_month());
        this->date.set_year(m.date.get_year());
        return *this;
    };
    friend istream& operator>>(istream& is, delivery2& t);


    void function_8(delivery2*& m);
    void function_9(delivery2* m);
    void function_10(delivery2* m);
    void function_11(delivery2* m);
    void function_12(delivery2* m);
    void function_13(delivery2* m);

    void save_work(delivery2* m, const char* file);
    delivery2* load_work(delivery2*& m, const char* file);
};