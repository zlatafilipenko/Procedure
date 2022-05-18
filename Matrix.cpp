#include "Matrix.h"
#include "Two_dimensional_array.h"
#include "Diagonal_matrix.h"

Matrix* In_Matrix(ifstream& ifst) {
    Matrix* M; //������� ��������� �� �������
    int K;

    ifst >> K; //��������� ������������� �������

    if (K == 1)
    {
        M = new Matrix; //�������� ������ ��� �������
        M->K = TWO_DIMENSIONAL_ARRAY; //���������� ��� �������

        int K_out = 0;

        ifst >> K_out; //��������� ������ ������ �������

        if (K_out == 1)
        {
            M->K_o = BY_LINE;
        }
        else if (K_out == 2)
        {
            M->K_o = BY_COLUMN;
        }
        else if (K_out == 3)
        {
            M->K_o = ONE_DIMENSIONAL;
        }

        ifst >> M->N; //��������� ����������� �������

        In_Two_dimensional_array(M->N, M->T_d_a, ifst); //��������� �������� �������

        return M;
    }
    else if (K == 2)
    {
        M = new Matrix; //�������� ������ ��� �������
        M->K = DIAGONAL_MATRIX; //���������� ��� �������

        int K_out = 0;

        ifst >> K_out; //��������� ������ ������ �������

        if (K_out == 1)
        {
            M->K_o = BY_LINE;
        }
        else if (K_out == 2)
        {
            M->K_o = BY_COLUMN;
        }
        else if (K_out == 3)
        {
            M->K_o = ONE_DIMENSIONAL;
        }

        ifst >> M->N; //��������� ����������� �������

        In_Diagonal_matrix(M->N, M->D_m, ifst); //��������� �������� �������

        return M;
    }
    else if (K == 3)
    {
        M = new Matrix; //�������� ������ ��� �������
        M->K = TRIANGULAR_MATRIX; //���������� ��� �������

        ifst >> M->N; //��������� ����������� �������

        In_Triangular_matrix(M->N, M->T_m, ifst); //��������� �������� �������

        return M;
    }
    else
    {
        return 0;
    }
}

void Out_Matrix(Matrix* M, ofstream& ofst) {
    if (M->K == TWO_DIMENSIONAL_ARRAY)
    {
        Out_Two_dimensional_array(M->K_o, M->N, M->T_d_a, ofst); //������� ������� ��������� ������
    }
    else if (M->K == DIAGONAL_MATRIX)
    {
        Out_Diagonal_matrix(M->K_o, M->N, M->D_m, ofst); //������� ������������ �������
    }
    else if (M->K == TRIANGULAR_MATRIX)
    {
        Out_Triangular_matrix(M->N, M->T_m, ofst); //������� ������������ �������
    }
    else
    {
        ofst << "Incorrect element!" << endl;
    }
}

int Sum_Matrix(Matrix* M) {
    if (M->K == TWO_DIMENSIONAL_ARRAY)
    {
        return Sum_Two_dimensional_array(M->N, M->T_d_a);
    }
    else if (M->K == DIAGONAL_MATRIX)
    {
        return Sum_Diagonal_matrix(M->N, M->D_m);
    }
    else
    {
        return -1;
    }
}

bool Compare(Matrix* First, Matrix* Second)
{
    return Sum_Matrix(First) > Sum_Matrix(Second);
}