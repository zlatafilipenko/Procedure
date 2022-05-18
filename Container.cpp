#include "Container.h"

void Init_Container(Container& C) {
    C.Len = 0;
}

void In_Container(Container& C, ifstream& ifst) {
    while (!ifst.eof()) //������ �� ����� �����
    {
        if ((C.Cont[C.Len] = In_Matrix(ifst)) != 0) //��������� ��������� ������� 
        {
            C.Len++;

            if (C.Len == C.Max_len) //�������� �� ������������ ����������
            {
                break;
            }
        }
    }
}

void Out_Container(Container& C, ofstream& ofst) {
    ofst << "Container contains " << C.Len
        << " elements." << endl; //������� ����� ����������

    for (int i = 0; i < C.Len; i++)
    {
        ofst << i << ": "; //������� ����� �������
        Out_Matrix(C.Cont[i], ofst); //������� �������

        ofst << "Sum of matrix elements = " << Sum_Matrix(C.Cont[i]) << endl;
    }
}

void Clear_Container(Container& C) {
    for (int i = 0; i < C.Len; i++)
    {
        delete C.Cont[i]; //������� ������, ���������� ��� ������ �������
    }

    C.Len = 0;
}

void Sort(Container& C)
{
    //��������� ���������
    for (int i = 0; i < C.Len - 1; i++)
    {
        for (int j = i + 1; j < C.Len; j++)
        {
            //������������ ���������� ����� ��������� ������
            if (Compare(C.Cont[i], C.Cont[j]))
            {
                Matrix* Temp = C.Cont[i];
                C.Cont[i] = C.Cont[j];
                C.Cont[j] = Temp;
            }
        }
    }
}