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
#include "FIO.h"
using namespace std;

FIO::FIO() {
	firstname = new char[60];
	strcpy(firstname, " ");
	secondname = new char[60];
	strcpy(secondname, " ");
	lastname = new char[60];
	strcpy(lastname, " ");
}

FIO:: ~FIO() {
	delete[] firstname;
	delete[] secondname;
	delete[] lastname;
}

