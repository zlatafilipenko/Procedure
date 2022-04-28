#include "Diagonal_matrix.h"

void In_Diagonal_matrix(int N, Diagonal_matrix& D_m, ifstream& ifst)
{
    D_m.Array = new int[N]; //�������� ������ ��� ������������ �������
    
    for (int i = 0; i < N; i++)
    {
        ifst >> D_m.Array[i]; //���������� ����� ������� � �������
    }
}

void Out_Diagonal_matrix(int N, Diagonal_matrix& D_m, ofstream& ofst)
{
    ofst << "It's diagonal matrix with dimension = " << N << endl; //������� ����������� �������

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                ofst << D_m.Array[i] << " "; //������� ������� �������; (i == j) -> ������ �� ���������
            }
            else
            {
                ofst << "0 "; //(i != j) -> �� ���������, ������� ����
            }
        }

        ofst << endl;
    }
}