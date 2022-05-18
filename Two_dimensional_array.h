#ifndef TWO_DIMENSIONAL_ARRAY_H
#define TWO_DIMENSIONAL_ARRAY_H

#include <fstream>

using namespace std;

//��������� ���������� �������
struct Two_dimensional_array {
    int** Array;
};

//������� ����� ���������� �������
void In_Two_dimensional_array(int N, Two_dimensional_array& T_d_a, ifstream& ifst);

//������� ������ ���������� �������
void Out_Two_dimensional_array(int N, Two_dimensional_array& T_d_a, ofstream& ofst);

//������� �������� ����� ��������� ���������� �������
int Sum_Two_dimensional_array(int N, Two_dimensional_array& T_d_a);

#endif //TWO_DIMENSIONAL_ARRAY_H