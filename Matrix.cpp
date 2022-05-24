#include "Matrix.h"
#include "Two_dimensional_array.h"
#include "Diagonal_matrix.h"

Matrix* In_Matrix(ifstream& ifst) {
    Matrix* M; //������� ��������� �� �������

    string Temp_str = "";
    ifst >> Temp_str;

    //���������, ��� ������������� ������� - ����� ����� �� 1 �� 3
    if (Temp_str != "1" && Temp_str != "2" && Temp_str != "3" && Temp_str != "")
    {
        //���� ������ �������� �������� �������, �� ���������� ���� �� �����
        ifst >> Temp_str;
        ifst >> Temp_str;
        ifst >> Temp_str;

        while (ifst.peek() != '\n')
        {
            ifst >> Temp_str;
        }

        M = new Matrix;

        M->K = ERROR;

        return M;
    }

    int K = atoi(Temp_str.c_str());

    if (K == 1)
    {
        M = new Matrix; //�������� ������ ��� �������
        M->K = TWO_DIMENSIONAL_ARRAY; //���������� ��� �������

        ifst >> Temp_str;

        //���������, ��� ������ ������ ������� - ����� ����� �� 1 �� 3
        if (Temp_str != "1" && Temp_str != "2" && Temp_str != "3")
        {
            //���� ������ �������� �������� �������, �� ���������� ���� �� �����
            ifst >> Temp_str;
            ifst >> Temp_str;

            while (ifst.peek() != '\n')
            {
                ifst >> Temp_str;
            }

            M = new Matrix;

            M->K = ERROR;

            return M;
        }

        int K_out = atoi(Temp_str.c_str());

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

        ifst >> Temp_str;

        //���������, ��� ������ ������� - ����� ������� ����
        if (atoi(Temp_str.c_str()) <= 0)
        {
            //���� ������ �������� �������� �������, �� ���������� ���� �� �����
            ifst >> Temp_str;

            while (ifst.peek() != '\n')
            {
                ifst >> Temp_str;
            }

            M = new Matrix;

            M->K = ERROR;

            return M;
        }

        //���������, ��� ������ ������� - ����� �����
        for (int i = 0; i < Temp_str.size(); i++)
        {
            if ((Temp_str[i] == '.') || (Temp_str[i] == ','))
            {
                //���� ������ �������� �������� �������, �� ���������� ���� �� �����
                ifst >> Temp_str;

                while (ifst.peek() != '\n')
                {
                    ifst >> Temp_str;
                }

                M = new Matrix;

                M->K = ERROR;

                return M;
            }
        }

        M->N = atoi(Temp_str.c_str()); //��������������������� �������

        In_Two_dimensional_array(M->N, M->T_d_a, ifst); //��������� �������� �������

        //���� ������� ������ �������, �� ��� ��������
        if (M->T_d_a.Array == NULL)
        {
            M->K = ERROR;
        }

        return M;
    }
    else if (K == 2)
    {
        M = new Matrix; //�������� ������ ��� �������
        M->K = DIAGONAL_MATRIX; //���������� ��� �������

        ifst >> Temp_str;

        if (Temp_str != "1" && Temp_str != "2" && Temp_str != "3")
        {
            ifst >> Temp_str;
            ifst >> Temp_str;

            while (ifst.peek() != '\n')
            {
                ifst >> Temp_str;
            }

            M = new Matrix;

            M->K = ERROR;

            return M;
        }

        int K_out = atoi(Temp_str.c_str());

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

        ifst >> Temp_str;

        if (atoi(Temp_str.c_str()) <= 0)
        {
            ifst >> Temp_str;

            while (ifst.peek() != '\n')
            {
                ifst >> Temp_str;
            }

            M = new Matrix;

            M->K = ERROR;

            return M;
        }

        for (int i = 0; i < Temp_str.size(); i++)
        {
            if ((Temp_str[i] == '.') || (Temp_str[i] == ','))
            {
                ifst >> Temp_str;

                while (ifst.peek() != '\n')
                {
                    ifst >> Temp_str;
                }

                M = new Matrix;

                M->K = ERROR;

                return M;
            }
        }

        M->N = atoi(Temp_str.c_str()); //��������������������� �������

        In_Diagonal_matrix(M->N, M->D_m, ifst); //��������� �������� �������

        if (M->D_m.Array == NULL)
        {
            M->K = ERROR;
        }

        return M;
    }
    else if (K == 3)
    {
        M = new Matrix; //�������� ������ ��� �������
        M->K = TRIANGULAR_MATRIX; //���������� ��� �������

        ifst >> Temp_str;

        if (Temp_str != "1" && Temp_str != "2" && Temp_str != "3")
        {
            ifst >> Temp_str;
            ifst >> Temp_str;

            while (ifst.peek() != '\n')
            {
                ifst >> Temp_str;
            }

            M = new Matrix;

            M->K = ERROR;

            return M;
        }

        int K_out = atoi(Temp_str.c_str());

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

        ifst >> Temp_str;

        if (atoi(Temp_str.c_str()) <= 0)
        {
            ifst >> Temp_str;

            while (ifst.peek() != '\n')
            {
                ifst >> Temp_str;
            }

            M = new Matrix;

            M->K = ERROR;

            return M;
        }

        for (int i = 0; i < Temp_str.size(); i++)
        {
            if ((Temp_str[i] == '.') || (Temp_str[i] == ','))
            {
                ifst >> Temp_str;

                while (ifst.peek() != '\n')
                {
                    ifst >> Temp_str;
                }

                M = new Matrix;

                M->K = ERROR;

                return M;
            }
        }

        M->N = atoi(Temp_str.c_str()); //��������������������� �������

        In_Triangular_matrix(M->N, M->T_m, ifst); //��������� �������� �������

        if (M->T_m.Array == NULL)
        {
            M->K = ERROR;
        }

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
        Out_Triangular_matrix(M->K_o, M->N, M->T_m, ofst); //������� ������������ �������
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
    else if (M->K == TRIANGULAR_MATRIX)
    {
        return Sum_Triangular_matrix(M->N, M->T_m);
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