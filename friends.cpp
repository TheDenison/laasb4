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
    //���� �������� �����
    cout << "\n\t���������� ������ �������� � delivery11!\n";
    cout << "�������� ����� ����������: ";
    is >> buf;
    t.set_firma(buf);

    //���� ������������ ������
    cout << "����������� �����: ";
    is >> buf;
    t.set_adres(buf);

    //���� ���� ����������
    cout << "��� ����������( 1 - �����, 2 - ������������): ";
    while (true) {
        is >> t.type;
        if (is.fail() || t.type > 2 || t.type < 1)
        {
            is.clear();
            is.ignore(32767, '\n');
            cout << "������� ������������ �������, ���������� ��� ���: ";
        }
        else break;
    }

    //���� ������
    cout << "������: ";
    while (true) {
        is >> t.balance;
        if (is.fail()) {
            is.clear();
            is.ignore(32767, '\n');
            cout << "������� ������������ �������, ���������� ��� ���: ";
        }
        else break;
    }
    //���� ����
    cout << "������� ���� ��������\n";
    //����
    do {
        try {
            cout << "����: ";
            is >> t.date.day;
            if (!cin) throw 1; // if year not int
            else if (t.date.day < 0) throw 2; // if year is negative
            check = false;
        }
        catch (int err) {
            if (err == 1) {
                cerr << endl <<  "������� ������������ �������, ���������� ��� ���: " << endl;
                cin.clear();
                cin.ignore(4096, '\n');
                check = true;
            }
            else if (err == 2) {
                cerr << endl << "�� ����� ���� �������������!" << endl;
                check = true;
            }
        }
    } while (check);

    //�����
    cout << "�����(�����): ";
    is >> buf;
    while ((strcmp(buf, "������") != 0) && (strcmp(buf, "�������") != 0) && strcmp(buf, "����") != 0 && strcmp(buf, "������") != 0 && (strcmp(buf, "���") != 0 && strcmp(buf, "����") != 0 && (strcmp(buf, "����") != 0) && (strcmp(buf, "������") != 0) && (strcmp(buf, "��������") != 0) && (strcmp(buf, "�������") != 0) && (strcmp(buf, "������") != 0) && (strcmp(buf, "�������") != 0))) {
        cout << "������� ������������ �������, ���������� ��� ���: ";
        is >> buf;
    }
    t.date.month = new char[strlen(buf) + 1];
    t.date.set_month(buf);
    //���
    do {
        try {
            cout << "���: ";
            is >> t.date.year;
            if (!cin) throw 1; // if year not int
            else if (t.date.year < 0) throw 2; // if year is negative
            check = false;
        }
        catch (int err) {
            if (err == 1) {
                cerr << endl << "�������������� ������ �����! ��������� ����..." << endl;
                cin.clear();
                cin.ignore(4096, '\n');
                check = true;
            }
            else if (err == 2) {
                cerr << endl << "�� ����� ���� �������������!" << endl;
                check = true;
            }
        }
    } while (check);
    return is;
}

istream& operator>>(istream& is, delivery2& t) {
    char buf[60];
    //���� ��������
    cout << "\n\t���������� ������ �������� � delivery22!\n";
    cout << "���������� � ��������\n";

    //���� �����
    cout << "���: ";
    is >> buf;
    t.fio.set_firstname(buf);

    //���� �������
    cout << "�������: ";
    is >> buf;
    t.fio.set_secondname(buf);

    //���� ��������
    cout << "��������: ";
    is >> buf;
    t.fio.set_lastname(buf);

    //���� ������
    cout << "������: ";
    while (true) {
        is >> t.balance;
        if (is.fail()) {
            is.clear();
            is.ignore(32767, '\n');
            cout << "������� ������������ �������, ���������� ��� ���: ";
        }
        else break;
    }
    //���� ����
    cout << "������� ���� ��������\n";
    //����
    cout << "����: ";
    while (true) {
        is >> t.date.day;
        if (is.fail() || t.date.day > 31 || t.date.day < 1) {
            is.clear();
            is.ignore(32767, '\n');
            cout << "������� ������������ �������, ���������� ��� ���: ";
        }
        else break;
    }
    //�����
    cout << "�����(�����): ";
    is >> buf;
    while ((strcmp(buf, "������") != 0) && (strcmp(buf, "�������") != 0) && strcmp(buf, "����") != 0 && strcmp(buf, "������") != 0 && (strcmp(buf, "���") != 0 && strcmp(buf, "����") != 0 && (strcmp(buf, "����") != 0) && (strcmp(buf, "������") != 0) && (strcmp(buf, "��������") != 0) && (strcmp(buf, "�������") != 0) && (strcmp(buf, "������") != 0) && (strcmp(buf, "�������") != 0))) {
        cout << "������� ������������ �������, ���������� ��� ���: ";
        is >> buf;
    }
    t.date.month = new char[strlen(buf) + 1];
    t.date.set_month(buf);
    //���
    cout << "���: ";
    while (true) {
        is >> t.date.year;
        if (is.fail() || t.date.year < 1) {
            is.clear();
            is.ignore(32767, '\n');
            cout << "������� ������������ �������, ���������� ��� ���: ";
        }
        else break;
    }
    return is;
}