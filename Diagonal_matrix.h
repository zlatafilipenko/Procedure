#ifndef DIAGONAL_MATRIX_H
#define DIAGONAL_MATRIX_H

#include <fstream>

#include "Key.h"

using namespace std;

//��������� "������������ �������"
struct Diagonal_matrix {
    int* Array; //������
};

//������� ����� ������������ �������
void In_Diagonal_matrix(int N, Diagonal_matrix& D_m, ifstream& ifst);

//������� ������ ������������ �������
void Out_Diagonal_matrix(Key_out K_o, int N, Diagonal_matrix& D_m, ofstream& ofst);

//������� �������� ����� ��������� ������������ �������
int Sum_Diagonal_matrix(int N, Diagonal_matrix& D_m);

#endif //DIAGONAL_MATRIX_H