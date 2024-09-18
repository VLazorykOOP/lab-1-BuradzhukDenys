﻿ // ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>

#include <time.h>

using namespace std;

const int MAX_SIZE = 200;
typedef double* pDouble;
/*
*   ConsoleInputArrayDouble
*   
*/
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0; 
    do {
        cout << "Input size Array ( 0 < size <= " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size > sizeMax);
    return size;
}
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputArray(int sizeMax, double Arr[])
{
    int size = ConsoleInputSizeArray(sizeMax);
        for (int i = 0; i < size; i++) 
        {
            cout << "Array[" << i << "] ";
            cin >> Arr[i];
        }
    return size;
}

/*
*   ConsoleOutputArray
*
*/
void ConsoleOutputArray(int size, double Arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1=0, r2=0;
    srand(size);
    for (int i = 0; i < size; i++)
    {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
    }
    return size;
}

int ConsoleInputDynamicArray(int sizeMax, pDouble &pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

void ConsoleInputVector(int sizeMax, vector<double> &A)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> d; A.push_back(d);
    }
    return ;
}


/*
*  WriteArrayTextFile 
*
*/

/*
*   ClearArrayTextFile
*
*/

void ClearArrayTextFile(const char *fileName)
{
    ofstream fout(fileName);
    fout.close();
}

void WriteArrayTextFile(int n, double *arr, const char *fileName )
{
    ofstream fout(fileName, ios::app);
    if (fout.fail()) return;
    fout << "size: " << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << " ";
    fout << endl;
    fout.close(); //
}
/*
*  ReadArrayTextFile
*
*/


int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;   
    for (int i = 0; i < n; i++)
       fin>> arr[i];
    fin.close();
    return size;
    
}


void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) *sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size=0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    return size;
}

void ShowMainMenu()
{
    system("cls");
    cout << "Main Menu\n";
    cout << "1.  Task 1\n";
    cout << "2.  Task 2\n";
    cout << "3.  Task 3\n";
}

void ShowMenuInput()
{
    system("cls");
    cout << "Menu Input\n";
    cout << "1. Console array to file 1.txt\n";
    cout << "2. Console size, random array to binary file 1.bin\n";
    cout << "3. Dynamic array from .txt file to new .txt file and console\n";
    cout << "4. Dynamic array(vector) from file to console\n";
    cout << "5. Exit\n";
}

void MenuInput()
{

}

double Task1(int sizeMax, double Arr[])
{
    char ch;
    m1:
    cin.ignore();
    ShowMenuInput();
    ch = getchar();
    switch (ch)
    {
    case '1':
    {
        system("cls");
        int size = ConsoleInputArray(sizeMax, Arr);
        int sizeB = 0;
        double B[sizeB];
        for (int i = 0; i < size; i++)
        {
        if (Arr[i] < 0)
        {
            B[sizeB] = Arr[i];
            sizeB++;
        }
        }
        ClearArrayTextFile("D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/1.txt");
        WriteArrayTextFile(size, Arr, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/1.txt");
        WriteArrayTextFile(sizeB, B, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/1.txt");
        getchar();
        goto m1;
        break;
    }
    case '2':
        cout << "2";
        break;
    case '3':
        cout << "3";
        break;
    case '4':
        cout << "4";
        break;
    case '5':
        break;
    default:
        cout << "ERROR";
        break;
    }
}

double Task2(int sizeMax, double A[])
{
}

double Task3(int sizeMax, double A[])
{
}

void TaskV(double Arr[])
{
    char ch;
    ShowMainMenu();
    ch = getchar();
    system("cls");
    switch (ch) {
        case '1': Task1(MAX_SIZE, Arr); break;
        case '2': Task2(MAX_SIZE, Arr); break;
        case '3': Task3(MAX_SIZE, Arr); break;
    }
}

int main()
{ 
    double A[MAX_SIZE];
    TaskV(A);
    //ConsoleOutputArray(RndInputArray(MAX_SIZE, A), A);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.