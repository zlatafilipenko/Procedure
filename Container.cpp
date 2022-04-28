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
    }
}

void Clear_Container(Container& C) {
    for (int i = 0; i < C.Len; i++) 
    {
        delete C.Cont[i]; //������� ������, ���������� ��� ������ �������
    }
    
    C.Len = 0;
}