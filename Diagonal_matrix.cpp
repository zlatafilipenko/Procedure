#include "Diagonal_matrix.h"

void In_Diagonal_matrix(int N, Diagonal_matrix& D_m, ifstream& ifst)
{
    D_m.Array = new int[N]; //�������� ������ ��� ������������ �������
    
    for (int i = 0; i < N; i++)
    {
        ifst >> D_m.Array[i]; //���������� ����� ������� � �������
    }
}

void Out_Diagonal_matrix(Key_out K_o, int N, Diagonal_matrix& D_m, ofstream& ofst)
{
    ofst << "It's diagonal matrix with dimension = " << N << endl; //������� ����������� �������

    if (K_o == BY_LINE)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    ofst << D_m.Array[i] << " ";
                }
                else
                {
                    ofst << "0 ";
                }
            }
            ofst << endl;
        }
    }
    else if (K_o == BY_COLUMN)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    ofst << D_m.Array[j] << " ";
                }
                else
                {
                    ofst << "0 ";
                }
            }
            ofst << endl;
        }
    }
    else if (K_o == ONE_DIMENSIONAL)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    ofst << D_m.Array[i] << " ";
                }
                else
                {
                    ofst << "0 ";
                }
            }
        }

        ofst << endl;
    }
}