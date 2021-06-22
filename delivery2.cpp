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
#include "FIO.h"
#include "delivery2.h"
using namespace std;


void delivery2::print_tabl() {
    printf("\n___________________________________________________________________________________________________________");
    printf("\nИмя\t\t\tФамилия\t\t\tОтчество\t\tСальдо\t\t\tДата");
    printf("\n___________________________________________________________________________________________________________");
}

void delivery2::print_info(int i, delivery2* m) {
    printf("\n%s\t\t", m[i].fio.get_firstname());
    printf("%15s\t\t", m[i].fio.get_secondname());
    printf("%15s\t\t", m[i].fio.get_lastname());
    printf("%15lf\t\t", m[i].balance);
    printf("%2d", m[i].date.get_day());
    printf("%10s", m[i].date.get_month());
    printf("%4d", m[i].date.get_year());
    printf("\n___________________________________________________________________________________________________________");
};

int delivery2::month_in_digit(delivery2* m) {
    if (strcmp(m->date.month, "январь") == 0)   return 1;
    if (strcmp(m->date.month, "февраль") == 0)  return 2;
    if (strcmp(m->date.month, "март") == 0)     return 3;
    if (strcmp(m->date.month, "апрель") == 0)   return 4;
    if (strcmp(m->date.month, "май") == 0)      return 5;
    if (strcmp(m->date.month, "июнь") == 0)     return 6;
    if (strcmp(m->date.month, "июль") == 0)     return 7;
    if (strcmp(m->date.month, "август") == 0)   return 8;
    if (strcmp(m->date.month, "сентябрь") == 0) return 9;
    if (strcmp(m->date.month, "октябрь") == 0)  return 10;
    if (strcmp(m->date.month, "ноябрь") == 0)   return 11;
    if (strcmp(m->date.month, "декабрь") == 0)  return 12;
}

void delivery2::function_8(delivery2*& m) {       //Добавить новый элемент
    char buf[60];
    delivery2* t = new delivery2[n_delivery2 + 1];
    for (int i = 0; i < n_delivery2; i++) {
        t[i] = m[i];
    }
    cin >> t[n_delivery2];
    cout << "\n\tПоставщик успешно сохранён!\n";
    printf("___________________________________________________________________________________________________________\n");
    delivery2::n_delivery2++;
    delete[] m;
    m = t;
};

void delivery2::function_9(delivery2* m) {      //Распечатать базу поставщиков
    printf("\n\t\t\tБаза поставщиков");
    print_tabl();
    for (int i = 0; i < n_delivery2; i++) {
        print_info(i, m);
    }
}

void delivery2::function_10(delivery2* m) {     //Поиск продавца по ФИО
    char buf[100];
    printf("\nВведите ФИО продавца: ");
    FIO* name = new FIO[1];

    printf("\nимя: ");
    gets_s(buf);
    gets_s(buf);
    name->set_firstname(buf);

    printf("фамилия: ");
    gets_s(buf);
    name->set_secondname(buf);

    printf("отчество: ");
    gets_s(buf);
    name->set_lastname(buf);

    m->print_tabl();
    for (int i = 0; i < n_delivery2; i++) {
        if (strcmp(m[i].fio.get_firstname(), name->get_firstname()) == 0) {
            if (strcmp(m[i].fio.get_secondname(), name->get_secondname()) == 0) {
                if (strcmp(m[i].fio.get_lastname(), name->get_lastname()) == 0) {
                    m->print_info(i, m);
                }
            }
        }
    }
    printf("\nЕсли информация не вывелась, проверьте введённые данные!");
    delete[] name;
    printf("\n___________________________________________________________________________________________________________");
};

void delivery2::function_11(delivery2* m) {         //Сортировать по уменьшению сальдо
    print_tabl();
    delivery2 t;
    for (int i = 0; i < n_delivery2 - 1; i++) {
        for (int j = 0; j < n_delivery2 - i - 1; j++) {
            if (m[j].balance < m[j + 1].balance) {
                t = m[j];
                m[j] = m[j + 1];
                m[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < n_delivery2; i++) {
        print_info(i, m);
    }
};

void delivery2::function_12(delivery2* m) {              //Найти все поставки с заданной датой
    char buf[100];
    delivery2* date_now = new delivery2[1];
    //считываем дату
    cout << "Введите нужную дату\n";

    //день
    cout << "День: ";
    date_now->date.day = scan_int();

    //месяц
    cout << "Месяц(слово): ";
    scan_month(buf);
    date_now->date.set_month(buf);

    //год
    cout << "Год: ";
    date_now->date.year = scan_int();

    print_tabl();
    for (int i = 0; i < n_delivery2; i++) {
        int month = month_in_digit(&m[i]);
        int month_now = month_in_digit(date_now);
        if ((date_now->date.year == m[i].date.year) && (month_now == month) && (date_now->date.day == m[i].date.day)) {
            print_info(i, m);
        }
    }
    delete[] date_now;
}

void delivery2::function_13(delivery2* m) {              //Найти все поставки с датой больше, чем заданная
    char buf[100];
    delivery2* date_now = new delivery2[1];

    //считываем дату
    cout << "Введите нужную дату\n";

    //день
    cout << "День: ";
    date_now->date.day = scan_int();

    //месяц
    cout << "Месяц(слово): ";
    scan_month(buf);
    date_now->date.set_month(buf);

    //год
    cout << "Год: ";
    date_now->date.year = scan_int();

    print_tabl();
    for (int i = 0; i < n_delivery2; i++) {
        int month = month_in_digit(&m[i]);
        int month_now = month_in_digit(date_now);

        if (date_now->date.year < m[i].date.year) {
            print_info(i, m);
        }
        else if ((date_now->date.year == m[i].date.year) && (month_now < month)) {
            print_info(i, m);
        }
        else if ((date_now->date.year == m[i].date.year) && (month_now == month) && (date_now->date.day < m[i].date.day)) {
            print_info(i, m);
        }
    }
    delete[] date_now;
}

void delivery2::save_work(delivery2* m, const char* file) {
    FILE* pf;
    pf = fopen(file, "w+");
    fprintf(pf, "%i\n", n_delivery2);
    for (int i = 0; i < n_delivery2; i++) {
        fprintf(pf, "%s ", m[i].fio.get_firstname());
        fprintf(pf, "%s ", m[i].fio.get_secondname());
        fprintf(pf, "%s ", m[i].fio.get_lastname());
        fprintf(pf, "%lf ", m[i].balance);
        fprintf(pf, "%i ", m[i].date.get_day());
        fprintf(pf, "%s ", m[i].date.get_month());
        fprintf(pf, "%i\n", m[i].date.get_year());
    }
    fclose(pf);
};

delivery2* delivery2::load_work(delivery2*& m, const char* file) {
    FILE* pf;
    char buf[100];
    pf = fopen(file, "r");

    //считываем количество
    fscanf(pf, "%s", buf);
    n_delivery2 = atoi(buf);

    delete[] m;
    m = new delivery2[n_delivery2 + 1];
    for (int i = 0; !feof(pf); i++) {
        //считываем название
        fscanf(pf, "%s", buf);

        m[i].fio.set_firstname(buf);

        //считываем адрес
        fscanf(pf, "%s", buf);
        m[i].fio.set_secondname(buf);

        //считываем тип
        fscanf(pf, "%s", buf);
        m[i].fio.set_lastname(buf);

        //считываем сальдо
        fscanf(pf, "%s", buf);
        m[i].balance = atof(buf);

        //считыываем день
        fscanf(pf, "%s", buf);
        m[i].date.set_day(atoi(buf));

        //считываем месяц
        fscanf(pf, "%s", buf);
        m[i].date.set_month(buf);

        //считываем год
        fscanf(pf, "%s", buf);
        m[i].date.set_year(atoi(buf));
    }
    fclose(pf);
    return m;
};