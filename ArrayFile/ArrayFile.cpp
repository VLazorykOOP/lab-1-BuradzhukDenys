 // ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>

#include <time.h>

using namespace std;

const int MAX_SIZE = 200;
typedef double* pDouble;

//ConsoleInputArrayDouble
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0; 
    do {
        cout << "Input size Array ( 0 < size <= " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size > sizeMax);
    return size;
}

//ConsoleInputArrayDouble
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

//RndInputArrayDouble
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

//WriteArrayTextFile 
void WriteArrayTextFile(int n, double *arr, const char *fileName )
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << " ";
    fout << endl;
    fout.close(); //
}

void WriteMaxNegativeInFile(double MaxNegative, const char *fileName)
{
    ofstream fout(fileName, ios::app);
    if (fout.fail()) return;
    fout << MaxNegative << endl;
    fout.close(); //
}

void WriteArrayTextFileFiveElements(int n, double *arr, const char* fileName)
{
    ofstream fout(fileName);
    int count = 0;
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
    {
        if (count == 5)
        {
            fout << endl;
            count = 0;
        }
        fout << arr[i] << " ";
        count++;
    }
    fout << endl;
    fout.close(); //
}

//ReadArrayTextFile
int ReadArrayTextFile(int n, pDouble &pA, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0 || size > n) size = n;   
    pA = new double[size];
    for (int i = 0; i < n; i++)
       fin >> pA[i];
    fin.close();
    return size;
}

int ReadVectorTextFile(int n, vector<double> &A, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0 || size > n) size = n;
    A.resize(size);   
    for (int i = 0; i < n; i++)
       fin >> A[i];
    fin.close();
    return size;
}

void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) *sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

void WriteMaxNegativeBinFile(double MaxNegative, const char* fileName)
{
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&MaxNegative, sizeof(double));
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

//Task 1(a,b,c,d)
void Task1(int sizeMax)
{
    char ch;
    double Arr[MAX_SIZE];
    int sizeB = 0;
    double B[sizeB];
    pDouble A = nullptr;
    pDouble DynamicB = nullptr;
    vector<double> VectorA;
    vector<double> VectorB;
    ShowMenuInput();
    cin.ignore();
    ch = getchar();
    switch (ch)
    {
    case '1':
    {
        system("cls");
        int size = ConsoleInputArray(sizeMax, Arr);
        for (int i = 0; i < size; i++)
        {
            if (Arr[i] < 0)
            {
                B[sizeB] = Arr[i];
                sizeB++;
            }
        }
        WriteArrayTextFile(size, Arr, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/1.txt");
        WriteArrayTextFile(sizeB, B, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/2.txt");
        cout << "Arrays A and B is recorded in a file";
        getchar();
        break;
    }
    case '2':
    {
        system("cls");
        int size = RndInputArray(sizeMax, Arr);
        for (int i = 0; i < size; i++)
        {
            if (Arr[i] < 0)
            {
                B[sizeB] = Arr[i];
                sizeB++;
            }
        }
        WriteArrayBinFile(size, Arr, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/1.bin");
        WriteArrayBinFile(sizeB, B, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/2.bin");
        getchar();
        break;
    }
    case '3':
    {
        system("cls");
        int size = ReadArrayTextFile(sizeMax, A, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/1.bin");
        DynamicB = new double[size];
        for (int i = 0; i < size; i++)
        {
            if (A[i] < 0)
            {
                DynamicB[sizeB] = A[i];
                sizeB++;
            }
        }
        WriteArrayTextFile(size, A, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/1.txt");
        WriteArrayTextFile(sizeB, B, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/2.txt");
        delete[] A;
        delete[] DynamicB;
        break;
    }
    case '4':
    {
        int size = ReadVectorTextFile(sizeMax, VectorA, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/1.txt");
        for (int i = 0; i < size; i++)
        {
            if (VectorA[i] < 0)
            {
                VectorB.push_back(VectorA[i]);
            }
        }
        cout << "Vector A: ";
        for (const auto& element : VectorA) {
            std::cout << element << " ";
        }
        cout << "\nArray B with negative numbers: ";
        for (const auto& element : VectorB) {
            std::cout << element << " ";
        }
        break;
    }
    case '5':
        break;
    default:
        cout << "ERROR";
        break;
    }
}

//Task2 (a,b,c,d)
void Task2(int sizeMax)
{
    char ch;
    double maxNegative = -1, T;
    double Arr[MAX_SIZE];
    pDouble A = nullptr;
    vector<double> VectorA;
    double *ptrCurr = nullptr;
    ShowMenuInput();
    cin.ignore();
    ch = getchar();
    switch (ch)
    {
    case '1':
    {
        system("cls");
        int size = ConsoleInputArray(sizeMax, Arr);
        cout << "Enter element T: ";
        cin >> T;
        ptrCurr = Arr;
        bool FoundT = false;
        for (int i = 0; i < size; i++)
        {
            if (*ptrCurr == T)
            {
                FoundT = true;
                break;
            }
            if (*ptrCurr < 0 && (maxNegative == -1 || *ptrCurr > maxNegative))
            {
                maxNegative = *ptrCurr;
            }
            ptrCurr++;
        }
        if (!FoundT)
        {
            cout << "Element T not found in the array." << endl;
        }
        WriteArrayTextFile(size, Arr, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/MaxNegative.txt");
        if (maxNegative != -1)
        {
            WriteMaxNegativeInFile(maxNegative, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/MaxNegative.txt");
        }
        else
        {
            cout << "No negative elements in the array" << endl;
        }
        break;
    }
    case '2':
    {
        system("cls");
        int size = RndInputArray(sizeMax, Arr);
        cout << "Enter element T: ";
        cin >> T;
        ptrCurr = Arr;
        bool FoundT = false;
        for (int i = 0; i < size; i++)
        {
            if (*ptrCurr == T)
            {
                FoundT = true;
                break;
            }
            if (*ptrCurr < 0 && (maxNegative == -1 || *ptrCurr > maxNegative))
            {
                maxNegative = *ptrCurr;
            }
            ptrCurr++;
        }
        if (!FoundT)
        {
            cout << "Element T not found in the array." << endl;
        }
        WriteArrayBinFile(size, Arr, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/MaxNegative.bin");
        if (maxNegative != -1)
        {
            WriteMaxNegativeInFile(maxNegative, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/MaxNegative.bin");
        }
        else
        {
            cout << "No negative elements in the array" << endl;
        }
        break;
    }
    case '3':
    {
        system("cls");
        int size = ReadArrayTextFile(sizeMax, A, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/MaxNegative.txt");
        cout << "Enter element T: ";
        cin >> T;
        ptrCurr = A;
        bool FoundT = false;
        for (int i = 0; i < size; i++)
        {
            if (*ptrCurr == T)
            {
                FoundT = true;
                break;
            }
            if (*ptrCurr < 0 && (maxNegative == -1 || *ptrCurr > maxNegative))
            {
                maxNegative = *ptrCurr;
            }
            ptrCurr++;
        }
        if (!FoundT)
        {
            cout << "Element T not found in the array." << endl;
        }
        WriteArrayTextFile(size, A, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/MaxNegative.txt");
        if (maxNegative != -1)
        {
            WriteMaxNegativeInFile(maxNegative, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/MaxNegative.txt");
            delete[] A;
            break;
        }
        else
        {
            cout << "No negative elements in the array" << endl;
            delete[] A;
            break;
        }
    }
    case '4':
    {
        int size = ReadVectorTextFile(sizeMax, VectorA, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/MaxNegative.txt");
        cout << "Enter element T: ";
        cin >> T;
        ptrCurr = &VectorA.front();
        bool FoundT = false;
        for (int i = 0; i < size; i++)
        {
            if (*ptrCurr == T)
            {
                FoundT = true;
                break;
            }
            if (*ptrCurr < 0 && (maxNegative == -1 || *ptrCurr > maxNegative))
            {
                maxNegative = *ptrCurr;
            }
            ptrCurr++;
        }
        if (!FoundT)
        {
            cout << "Element T not found in the array." << endl;
        }
        for (int i = 0; i < VectorA.size(); i++)
        {
            cout << VectorA[i] << " ";
        }
        if (maxNegative != -1)
        {
            cout << "\nMax negative number - " << maxNegative << endl;
        }
        else
        {
            cout << "No negative elements in the array" << endl;
        }
        break;
    }
    case '5':
        break;
    default:
        cout << "ERROR";
        break;
    }
}

void Task3(int sizeMax)
{
    char ch;
    double Arr[MAX_SIZE];
    int sizeB = 0;
    double B[sizeB];
    pDouble A = nullptr;
    pDouble DynamicB = nullptr;
    vector<double> VectorA;
    vector<double> VectorB;
    ShowMenuInput();
    cin.ignore();
    ch = getchar();
    switch (ch)
    {
    case '1':
    {
        system("cls");
        int size = ConsoleInputArray(sizeMax, Arr);
        for (int i = 0; i < size; i++)
        {
            bool newNumber = false;
            for (int j = i + 1; j < size; j++)
            {
                if (Arr[i] == Arr[j] && sizeB > 0)
                {
                    for (int k = 0; k < sizeB; k++)
                    {
                        if (Arr[i] == B[k])
                        {
                            newNumber = false;
                            break;
                        }
                        else newNumber = true;
                    }
                    if (newNumber)
                    {
                        B[sizeB] = Arr[i];
                        sizeB++;
                    }
                }
                else if (Arr[i] == Arr[j] && sizeB == 0)
                {
                    B[sizeB] = Arr[i];
                    sizeB++;
                }
            }
        }
        WriteArrayTextFile(size, Arr, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/Arr.txt");
        WriteArrayTextFileFiveElements(sizeB, B, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/B.txt");
        cout << "Arrays A and B is recorded in a file";
        break;
    }
    case '2':
    {
        system("cls");
        int size = RndInputArray(sizeMax, Arr);
        for (int i = 0; i < size; i++)
        {
            if (Arr[i] < 0)
            {
                B[sizeB] = Arr[i];
                sizeB++;
            }
        }
        WriteArrayBinFile(size, Arr, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/1.bin");
        WriteArrayBinFile(sizeB, B, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/2.bin");
        break;
    }
    case '3':
    {
        system("cls");
        int size = ReadArrayTextFile(sizeMax, A, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/1.bin");
        DynamicB = new double[size];
        for (int i = 0; i < size; i++)
        {
            if (A[i] < 0)
            {
                DynamicB[sizeB] = A[i];
                sizeB++;
            }
        }
        WriteArrayTextFile(size, A, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/1.txt");
        WriteArrayTextFile(sizeB, B, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/2.txt");
        delete[] A;
        delete[] DynamicB;
        break;
    }
    case '4':
    {
        int size = ReadVectorTextFile(sizeMax, VectorA, "D:/Codes/Visual Code Codes/OOP/lab-1-BuradzhukDenys/1.txt");
        for (int i = 0; i < size; i++)
        {
            if (VectorA[i] < 0)
            {
                VectorB.push_back(VectorA[i]);
            }
        }
        cout << "Vector A: ";
        for (const auto& element : VectorA) {
            std::cout << element << " ";
        }
        cout << "\nArray B with negative numbers: ";
        for (const auto& element : VectorB) {
            std::cout << element << " ";
        }
        break;
    }
    case '5':
        break;
    default:
        cout << "ERROR";
        break;
    }
}

void TaskV()
{
    char ch;
    ShowMainMenu();
    ch = getchar();
    system("cls");
    switch (ch) {
        case '1': Task1(MAX_SIZE); break;
        case '2': Task2(MAX_SIZE); break;
        case '3': Task3(MAX_SIZE); break;
    }
}

int main()
{ 
    TaskV();
}