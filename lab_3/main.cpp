#include <iostream>

using namespace std;

int fill_matrix(int ** const matrix, int rows, int cols)
{

	for (int i=0; i < rows; i++)
	{
		cout << "Enter [" << i << "] row: ";
		for (int j=0; j < cols; j++)
		{
			cin >> matrix[i][j];
		}
	}
}


void print_matrix(int ** const matrix, int rows, int cols)
{
	cout << endl;
	for (int i=0; i < rows; i++)
	{
		if (matrix[i] == NULL) continue;
		for (int j=0; j < cols; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

int zerorow(int* const row, int len)
{
	for(int i=0; i < len; i++)
	{
		if (row[i] != 0)
			return 0;
	}
	return 1;
}

void remove_zerorows(int ** const matrix, int rows, int cols)
{
	for (int i=0; i < rows; i++)
	{
		if (zerorow(matrix[i], cols))
		{
			delete [] matrix[i];
			matrix[i] = NULL;
		}
	}
}

int main()
{
	int **matrix;
	int rows, cols;

	cout << "Enter rows number: ";
	cin >> rows;
	cout << "Enter cols number: ";
	cin >> cols;

	matrix = new int* [rows];
	for(int i=0; i < rows; i++)
		matrix[i] = new int [cols];

	fill_matrix(matrix, rows, cols);

	remove_zerorows(matrix, rows, cols);

	print_matrix(matrix, rows, cols);

	for(int i=0; i < rows; i++)
		if( matrix[i] != NULL)
			delete [] matrix[i];
	delete matrix;

	return 0;
}
