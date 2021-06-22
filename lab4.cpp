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
#include "delivery1.h"
#include "delivery2.h"
#include "Common.h"
#include "FIO.h"
using namespace std;

int Common::n_Common = 0;
int delivery1::n_delivery1 = 0;
int delivery2::n_delivery2 = 0;


int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const char* file_delivery1 = "test_delivery1";
    const char* file_delivery2 = "test_delivery2";

    delivery1* delivery11 = new delivery1[1];
    delivery2* delivery22 = new delivery2[1];
    Common* common = new Common[1];

    int flag = 0;

    FILE* pf_1, * pf_2;

    if ((pf_1 = fopen(file_delivery1, "r+")) == NULL) {
        printf("\nФайла delivery1 нет, идёт создание!");
        pf_1 = fopen(file_delivery1, "w+");
        fclose(pf_1);
    }
    else {
        printf("\nФайл delivery1 найден, идёт загрузка!");
        delivery11->load_work(delivery11, file_delivery1);
    }

    if ((pf_2 = fopen(file_delivery2, "r+")) == NULL) {
        printf("\nФайла delivery2 нет, идёт создание!");
        pf_2 = fopen(file_delivery2, "w+");
        fclose(pf_2);
    }
    else {
        printf("\nФайл delivery2 найден, идёт загрузка!");
        delivery22->load_work(delivery22, file_delivery2);
    }

    common->print_menu();

    while (flag != 14) {
        printf("\nВведите номер функции меню: ");
        flag = common->scan_flag();
        if (flag == 1) {
            delivery11->function_1(delivery11);
        }
        if (flag == 2) {
            delivery11->function_2(delivery11);
        }
        if (flag == 3) {
            delivery11->function_3(delivery11);
        }
        if (flag == 4) {
            delivery11->function_4(delivery11);
        }
        if (flag == 5) {
            delivery11->function_5(delivery11);
        }
        if (flag == 6) {
            delivery11->function_6(delivery11);
        }
        if (flag == 7) {
            delivery11->function_7(delivery11);
        }
        if (flag == 8) {
            delivery22->function_8(delivery22);
        }
        if (flag == 9) {
            delivery22->function_9(delivery22);
        }
        if (flag == 10) {
            delivery22->function_10(delivery22);
        }
        if (flag == 11) {
            delivery22->function_11(delivery22);
        }
        if (flag == 12) {
            delivery22->function_12(delivery22);
        }
        if (flag == 13) {
            delivery22->function_13(delivery22);
        }
        if (flag == 14) {
            printf("\nПрограмма <<База данных: Производство (поставщики)>> завершила свою работу. До свидания!");
            printf("\n________________________________________________________________________________________\n");

        }
    }

    delivery11->save_work(delivery11, file_delivery1);
    delivery22->save_work(delivery22, file_delivery2);

    delete[] delivery11;
    delete[] delivery22;

    return 0;
}