#ifndef CONTAINER_H
#define CONTAINER_H

#include <fstream>

#include "Matrix.h"

using namespace std;

//���������
struct Container {
    enum { 
        Max_len = 100 
    }; // ������������ ����� ����������

    int Len; // ������� �����
    Matrix* Cont[Max_len]; //������ ������
};

//������� ������������� ����������
void Init_Container(Container& C);

//������� ����� ��������� � ���������
void In_Container(Container& C, ifstream& ifst);

//������� ����� ����������
void Out_Container(Container& C, ofstream& ofst);

//������� ������� ����������
void Clear_Container(Container& C);

#endif //CONTAINER_H