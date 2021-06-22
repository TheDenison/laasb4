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
#include "delivery1.h"

using namespace std;

delivery1::delivery1() {
    firma = new char[60];
    strcpy(firma, " ");
    adres = new char[60];
    strcpy(adres, " ");
    type = 0;
}

delivery1:: ~delivery1() {
    delete[] firma;
    delete[] adres;
}

void delivery1::print_tabl() {
    printf("\n___________________________________________________________________________________________________________");
    printf("\nФирма\t\tЮридический адрес\t\tТип поставщика\t\tСальдо\t\t\tДата");
    printf("\n___________________________________________________________________________________________________________");
}

void delivery1::print_info(int i, delivery1* m) {
    printf("\n%s\t\t", m[i].get_firma());
    printf("%15s\t\t", m[i].get_adres());
    printf("%15d\t\t", m[i].type);
    printf("%15lf\t\t", m[i].balance);
    printf("%2d", m[i].date.get_day());
    printf("%10s", m[i].date.get_month());
    printf("%4d", m[i].date.get_year());
    printf("\n___________________________________________________________________________________________________________");
};

int delivery1::month_in_digit(delivery1* m) {
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

void delivery1::function_1(delivery1*& m) {       //Добавить новый элемент
    char buf[60];
    delivery1* t = new delivery1[n_delivery1 + 1];
    for (int i = 0; i < n_delivery1; i++) {
        t[i] = m[i];
    }
    cin >> t[n_delivery1];
    cout << "\n\tПоставщик успешно сохранён!\n";
    printf("___________________________________________________________________________________________________________\n");
    delivery1::n_delivery1++;
    delete[] m;
    m = t;
};

void delivery1::function_2(delivery1* m) {      //Распечатать базу поставщиков
    printf("\n\t\t\tБаза поставщиков");
    print_tabl();
    for (int i = 0; i < n_delivery1; i++) {
        print_info(i, m);
    }
}

void delivery1::function_3(delivery1* m) {     //Поиск поставщика по названию фирмы
    char buf[100];
    printf("Введите название фирмы поставщика: ");
    gets_s(buf);
    gets_s(buf);
    char* name = new char[strlen(buf) + 1];
    strcpy(name, buf);
    m->print_tabl();
    for (int i = 0; i < n_delivery1; i++) {
        if (strcmp(m[i].get_firma(), name) == 0) {
            m->print_info(i, m);
        }
    }
    printf("\nЕсли информация не вывелась, проверьте введённые данные!");
    delete[] name;
    printf("\n___________________________________________________________________________________________________________");
};

void delivery1::function_4(delivery1* m) {        //Фильтр по типу(найти поставщиков заданного типа)
    printf("Введите тип поставщика(1- поставщик сырья, 2- поставщик оборудования): ");
    int typ = 0;
    while (true) {
        typ = scan_int();
        if (typ == 1 || typ == 2) {
            break;
        }
        else printf("Введено некорректное зачение, попробуйте еще раз: ");
        typ = scan_int();
    }
    print_tabl();
    for (int i = 0; i < n_delivery1; i++) {
        if (m[i].type == typ) {
            print_info(i, m);
        }
    }
    printf("\nЕсли информация не вывелась, проверьте введённые данные!");
    printf("\n___________________________________________________________________________________________________________");
};

void delivery1::function_5(delivery1* m) {         //Сортировать по уменьшению сальдо
    print_tabl();
    delivery1 t;
    for (int i = 0; i < n_delivery1 - 1; i++) {
        for (int j = 0; j < n_delivery1 - i - 1; j++) {
            if (m[j].balance < m[j + 1].balance) {
                t = m[j];
                m[j] = m[j + 1];
                m[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < n_delivery1; i++) {
        print_info(i, m);
    }
};

void delivery1::function_6(delivery1* m) {              //Найти все поставки с заданной датой
    char buf[100];
    delivery1* date_now = new delivery1[1];
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
    for (int i = 0; i < n_delivery1; i++) {
        int month = month_in_digit(&m[i]);
        int month_now = month_in_digit(date_now);
        if ((date_now->date.year == m[i].date.year) && (month_now == month) && (date_now->date.day == m[i].date.day)) {
            print_info(i, m);
        }
    }
    delete[] date_now;
}

void delivery1::function_7(delivery1* m) {              //Найти все поставки с датой больше, чем заданная
    char buf[100];
    delivery1* date_now = new delivery1[1];

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
    for (int i = 0; i < n_delivery1; i++) {
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

void delivery1::save_work(delivery1* m, const char* file) {
    FILE* pf;
    pf = fopen(file, "w+");
    fprintf(pf, "%i\n", n_delivery1);
    for (int i = 0; i < n_delivery1; i++) {
        fprintf(pf, "%s ", m[i].get_firma());
        fprintf(pf, "%s ", m[i].get_adres());
        fprintf(pf, "%i ", m[i].type);
        fprintf(pf, "%lf ", m[i].balance);
        fprintf(pf, "%i ", m[i].date.get_day());
        fprintf(pf, "%s ", m[i].date.get_month());
        fprintf(pf, "%i\n", m[i].date.get_year());
    }
    fclose(pf);
};

delivery1* delivery1::load_work(delivery1*& m, const char* file) {
    FILE* pf;
    char buf[100];
    pf = fopen(file, "r");

    //считываем количество
    fscanf(pf, "%s", buf);
    n_delivery1 = atoi(buf);

    delete[] m;
    m = new delivery1[n_delivery1 + 1];
    for (int i = 0; !feof(pf); i++) {
        //считываем название
        fscanf(pf, "%s", buf);

        m[i].set_firma(buf);

        //считываем адрес
        fscanf(pf, "%s", buf);
        m[i].set_adres(buf);

        //считываем тип
        fscanf(pf, "%s", buf);
        m[i].type = atoi(buf);

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