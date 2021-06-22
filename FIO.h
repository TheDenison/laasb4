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

class delivery2;

class FIO
{
private:
    char* firstname;            //имя
    char* secondname;           //фамилия
    char* lastname;             //отчество
public:
    friend class delivery2;
    char* get_firstname() { return firstname; };
    char* get_secondname() { return secondname; };
    char* get_lastname() { return lastname; };
    void set_firstname(char* a) {
        delete[] firstname;
        firstname = new char[strlen(a) + 1];
        strcpy(firstname, a);
    };
    void set_secondname(char* a) {
        delete[] secondname;
        secondname = new char[strlen(a) + 1];
        strcpy(secondname, a);
    };
    void set_lastname(char* a) {
        delete[] lastname;
        lastname = new char[strlen(a) + 1];
        strcpy(lastname, a);
    };
    FIO();             //конструктор по-умолчанию
    ~FIO();            //деструктор
};



