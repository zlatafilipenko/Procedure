#ifndef MATRIX_H
#define MATRIX_H

#include "Key.h"
#include "Diagonal_matrix.h"
#include "Two_dimensional_array.h"

//��������� "�������"
struct Matrix {
    Key K; //������������� ������� - ������������ ��� ������� ��������� ������
    int N; //����� �������
    Key_out K_o; //������ ������ �������

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

#endif //MATRIX_H