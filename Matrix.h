#ifndef MATRIX_H
#define MATRIX_H

#include "Key.h"
#include "Diagonal_matrix.h"
#include "Two_dimensional_array.h"

//��������� "�������"
struct Matrix {
    Key K; //������������� ������� - ������������ ��� ������� ��������� ������
    int N; //����� �������

    //������ ������������ ������� ��� �������� ���������� �������
    union {
        Diagonal_matrix D_m;
        Two_dimensional_array T_d_a;
    };
};

//������� ����� �������
Matrix* In_Matrix(ifstream& ifst);

//������� ������ �������
void Out_Matrix(Matrix* M, ofstream& ofst);

//������� ������� ����� ��������� �������
int Sum_Matrix(Matrix* M);

//������� ��������� ���� ��������� ������
bool Compare(Matrix* First, Matrix* Second);

#endif //MATRIX_H