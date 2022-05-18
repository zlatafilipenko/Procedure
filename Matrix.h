#ifndef MATRIX_H
#define MATRIX_H

#include "Key.h"
#include "Diagonal_matrix.h"
#include "Two_dimensional_array.h"
#include "Triangular_matrix.h"

//��������� "�������"
struct Matrix {
    Key K; //������������� ������� - ������������ ��� ������� ��������� ������
    int N; //����� �������
    Key_out K_o; //������ ������ �������

    //������ ������������ ������� ��� �������� ���������� �������
    union {
        Diagonal_matrix D_m;
        Two_dimensional_array T_d_a;
        Triangular_matrix T_m;
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