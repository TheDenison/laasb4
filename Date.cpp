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

Date::Date() {
    day = 0;
    month = new char[60];
    strcpy(month, " ");
    year = 0;
}


Date:: ~Date() {
    delete[] month;
}