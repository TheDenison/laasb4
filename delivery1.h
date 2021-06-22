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
#include "Date.h"

using namespace std;

class Common;

class delivery1 : public Common
{
private:
    char* firma;		// название фирмы поставщика
    char* adres;        // юридический адрес 
    int type;           // 1- поставщик сырья, 2- поставщик оборудования
public:
    delivery1();
    ~delivery1();
    static int n_delivery1;
    friend class Date;
    //get-методы
    char* get_firma() { return firma; };
    char* get_adres() { return adres; };
    int get_type() { return type; };

    //set-методы
    void set_firma(char* a) {
        delete[] firma;
        firma = new char[strlen(a) + 1];
        strcpy(firma, a);
    };
    void set_adres(char* a) {
        delete[] adres;
        adres = new char[strlen(a) + 1];
        strcpy(adres, a);
    };
    void set_type(int a) { type = a; };

    void print_tabl();
    void print_info(int i, delivery1* m);
    int month_in_digit(delivery1* m);

    delivery1& operator=(delivery1& m) {
        if (this->firma != nullptr) { delete[] this->firma; }
        if (this->adres != nullptr) { delete[] this->adres; }
        if (this->date.month != nullptr) { delete[] this->date.month; }
        this->firma = new char[strlen(m.firma) + 1];
        this->adres = new char[strlen(m.adres) + 1];
        this->date.month = new char[strlen(m.date.month) + 1];
        this->set_firma(m.get_firma());
        strcpy(this->adres, m.get_adres());
        this->set_type(m.type);
        this->set_balance(m.balance);
        this->date.set_day(m.date.get_day());
        strcpy(this->date.month, m.date.get_month());
        this->date.set_year(m.date.get_year());
        return *this;
    };
    friend istream& operator>>(istream& is, delivery1& t);

    void function_1(delivery1*& m);
    void function_2(delivery1* m);
    void function_3(delivery1* m);
    void function_4(delivery1* m);
    void function_5(delivery1* m);
    void function_6(delivery1* m);
    void function_7(delivery1* m);

    void save_work(delivery1* m, const char* file);
    delivery1* load_work(delivery1*& m, const char* file);
};

