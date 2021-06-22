#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iomanip> 
#include <cstring>
#include <windows.h>
#include "Common.h"
#include "Date.h"
#include "delivery1.h"
#include "delivery2.h"
#include "FIO.h"
using namespace std;

istream& operator>>(istream& is, delivery1& t) {
    bool check;
    char buf[60];
    //ввод названи€ фирмы
    cout << "\n\tƒобавление нового элемента в delivery11!\n";
    cout << "название фирмы поставщика: ";
    is >> buf;
    t.set_firma(buf);

    //ввод юридического адреса
    cout << "юридический адрес: ";
    is >> buf;
    t.set_adres(buf);

    //ввод типа поставщика
    cout << "тип поставщика( 1 - сырьЄ, 2 - оборудование): ";
    while (true) {
        is >> t.type;
        if (is.fail() || t.type > 2 || t.type < 1)
        {
            is.clear();
            is.ignore(32767, '\n');
            cout << "¬ведено некорректное зачение, попробуйте еще раз: ";
        }
        else break;
    }

    //ввод сальдо
    cout << "сальдо: ";
    while (true) {
        is >> t.balance;
        if (is.fail()) {
            is.clear();
            is.ignore(32767, '\n');
            cout << "¬ведено некорректное зачение, попробуйте еще раз: ";
        }
        else break;
    }
    //ввод даты
    cout << "введите дату поставки\n";
    //день
    do {
        try {
            cout << "день: ";
            is >> t.date.day;
            if (!cin) throw 1; // if year not int
            else if (t.date.day < 0) throw 2; // if year is negative
            check = false;
        }
        catch (int err) {
            if (err == 1) {
                cerr << endl <<  "¬ведено некорректное зачение, попробуйте еще раз: " << endl;
                cin.clear();
                cin.ignore(4096, '\n');
                check = true;
            }
            else if (err == 2) {
                cerr << endl << "Ќе может быть отрицательным!" << endl;
                check = true;
            }
        }
    } while (check);

    //мес€ц
    cout << "мес€ц(слово): ";
    is >> buf;
    while ((strcmp(buf, "€нварь") != 0) && (strcmp(buf, "февраль") != 0) && strcmp(buf, "март") != 0 && strcmp(buf, "апрель") != 0 && (strcmp(buf, "май") != 0 && strcmp(buf, "июнь") != 0 && (strcmp(buf, "июль") != 0) && (strcmp(buf, "август") != 0) && (strcmp(buf, "сент€брь") != 0) && (strcmp(buf, "окт€брь") != 0) && (strcmp(buf, "но€брь") != 0) && (strcmp(buf, "декабрь") != 0))) {
        cout << "¬ведено некорректное зачение, попробуйте еще раз: ";
        is >> buf;
    }
    t.date.month = new char[strlen(buf) + 1];
    t.date.set_month(buf);
    //год
    do {
        try {
            cout << "год: ";
            is >> t.date.year;
            if (!cin) throw 1; // if year not int
            else if (t.date.year < 0) throw 2; // if year is negative
            check = false;
        }
        catch (int err) {
            if (err == 1) {
                cerr << endl << "ѕоддерживаютс€ только цифры! ѕовторите ввод..." << endl;
                cin.clear();
                cin.ignore(4096, '\n');
                check = true;
            }
            else if (err == 2) {
                cerr << endl << "Ќе может быть отрицательным!" << endl;
                check = true;
            }
        }
    } while (check);
    return is;
}

istream& operator>>(istream& is, delivery2& t) {
    char buf[60];
    //ввод продавца
    cout << "\n\tƒобавление нового элемента в delivery22!\n";
    cout << "»нформаци€ о продавце\n";

    //ввод имени
    cout << "им€: ";
    is >> buf;
    t.fio.set_firstname(buf);

    //ввод фамилии
    cout << "фамили€: ";
    is >> buf;
    t.fio.set_secondname(buf);

    //ввод отчества
    cout << "отчество: ";
    is >> buf;
    t.fio.set_lastname(buf);

    //ввод сальдо
    cout << "сальдо: ";
    while (true) {
        is >> t.balance;
        if (is.fail()) {
            is.clear();
            is.ignore(32767, '\n');
            cout << "¬ведено некорректное зачение, попробуйте еще раз: ";
        }
        else break;
    }
    //ввод даты
    cout << "введите дату поставки\n";
    //день
    cout << "день: ";
    while (true) {
        is >> t.date.day;
        if (is.fail() || t.date.day > 31 || t.date.day < 1) {
            is.clear();
            is.ignore(32767, '\n');
            cout << "¬ведено некорректное зачение, попробуйте еще раз: ";
        }
        else break;
    }
    //мес€ц
    cout << "мес€ц(слово): ";
    is >> buf;
    while ((strcmp(buf, "€нварь") != 0) && (strcmp(buf, "февраль") != 0) && strcmp(buf, "март") != 0 && strcmp(buf, "апрель") != 0 && (strcmp(buf, "май") != 0 && strcmp(buf, "июнь") != 0 && (strcmp(buf, "июль") != 0) && (strcmp(buf, "август") != 0) && (strcmp(buf, "сент€брь") != 0) && (strcmp(buf, "окт€брь") != 0) && (strcmp(buf, "но€брь") != 0) && (strcmp(buf, "декабрь") != 0))) {
        cout << "¬ведено некорректное зачение, попробуйте еще раз: ";
        is >> buf;
    }
    t.date.month = new char[strlen(buf) + 1];
    t.date.set_month(buf);
    //год
    cout << "год: ";
    while (true) {
        is >> t.date.year;
        if (is.fail() || t.date.year < 1) {
            is.clear();
            is.ignore(32767, '\n');
            cout << "¬ведено некорректное зачение, попробуйте еще раз: ";
        }
        else break;
    }
    return is;
}