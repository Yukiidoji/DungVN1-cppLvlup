#include<iostream>
#include<cstring>
#include <cstdlib>
using namespace std;

bool importData(int** pArr, int szRow, int szCol);
int** add2Matrix(int** pArr1, int** pArr2, int szRow, int szCol);
void PrintMatrix(int** pArr, int szRow, int szCol);
void freeMem(int** pArr, int szRow, int szCol);

int main()
{
	int **pArr1, **pArr2, **AddArr;
	int szRow, szCol;

	cout << "\nInput Row: ";
	cin >> szRow;
	cout << "\nInput Colums: ";
	cin >> szCol;

	if (szRow <= 0 || szCol <= 0)
		return 0;

	pArr1 = new int* [szRow];
	//Allocate memory first matrix
	for (int indexRow = 0; indexRow < szRow; indexRow++)
	{
		pArr1[indexRow] = new int[szCol];
	}

	//Allocate memory second matrix
	pArr2 = new int* [szRow];
	for (int indexRow = 0; indexRow < szRow; indexRow++)
	{
		pArr2[indexRow] = new int[szCol];
	}

	// Import matrix
	cout << "\nImport first matrix:";
	importData(pArr1, szRow, szCol);
	cout << "\nImport second matrix :";
	importData(pArr2, szRow, szCol);

	AddArr = (int**)add2Matrix(pArr1, pArr2, szRow, szCol);
	cout << "\nAddition matrix:\n";
	PrintMatrix(AddArr, szRow, szCol);
	freeMem(pArr1, szRow, szCol);
	freeMem(pArr2, szRow, szCol);
	freeMem(AddArr, szRow, szCol);
	return 0;
}

/*************************************************************
Function : Import data for matrix
Parameter:
		 pArr: pointer to memory allocated in function importData
		 szRow: row size of matrix
		 szCol: column size of matrix
Return :
		true: success
		false: fail
*************************************************************/
bool importData(int** pArr, int szRow, int szCol)
{
	int iRow, iCol;

	// Input matrix
	if (pArr)
	{
		for (int iRow = 0; iRow < szRow; iRow++) {
			for (int iCol = 0; iCol < szCol; iCol++)
			{
				cout << "Input Arr[" << iRow << "]" << "[" << iCol << "]" << endl;
				cin >> pArr[iRow][iCol];
			}			
		}
		return true;
	}
	return false;
}

/*************************************************************
Function : Add 2 matrix
Parameter: matrix 1, matrix 2, number of row, number of column
Return : pointer to memory which contains result
*************************************************************/
int** add2Matrix(int** pArr1, int** pArr2, int szRow, int szCol)
{
	int iRow, iCol;
	int** pArr3;
	// Allocate memory
	pArr3 = new int* [szRow];
	for (iRow = 0; iRow < szRow; iRow++)
	{
		pArr3[iRow] = new int[szCol];
	}

	// Add 2 matrix
	for (iRow = 0; iRow < szRow; iRow++)
		for (iCol = 0; iCol < szCol; iCol++)
		{
			pArr3[iRow][iCol] = pArr1[iRow][iCol] + pArr2[iRow][iCol];
		}
	return pArr3;
}

/*************************************************************
Function : display matrix pArr on console
Parameter: matrix,  number of row, number of column
Return : void
*************************************************************/
void PrintMatrix(int** pArr, int szRow, int szCol)
{
	int iRow, iCol;
	for (iRow = 0; iRow < szRow; iRow++)
	{
		cout << "\n";
		for (iCol = 0; iCol < szCol; iCol++)
		{
			cout << pArr[iRow][iCol];
		}
	}
}

/*************************************************************
Function : free  memory
Parameter: matrix, number of row, number of column
Return : void
*************************************************************/
void freeMem(int** pArr, int szRow, int szCol)
{
	int i, j;
	for (i = 0; i < szRow; i++)
	{
		if (pArr[i])
		{
			delete[]pArr[i];
			pArr[i] = NULL;
		}
	}
}