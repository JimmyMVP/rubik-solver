#ifndef MATRIXOPS_H_
#define MATRIXOPS_H_
#include <iostream>
#include <vector>
using namespace std;


namespace matrixops
{
template<typename T>
void translateMatrix(T& M)
{

	const int size = M.size();
	typename T::value_type::value_type tmp;
	

	for(int i = 0; i < size-1; i++)
	{
		for(int j = i+1; j < size; j++)
		{
			tmp = M[i][j];
			M[i][j] = M[j][i];
			M[j][i] = tmp;
		}
	}


}

template<typename T>
void setRow(vector<vector<T> >&M, const unsigned int& index, vector<T> newRow)
{	
	if(M[0].size() != newRow.size()) 
		throw "Matrix row size different from row size";
	M[index] = newRow;
}

template<typename T>
void setColumn(vector<vector<T> >&M, const unsigned int& index, vector<T> newColumn)
{
	if(M.size() != newColumn.size()) 
		throw "Column size different from row size";
	
	for(int i=0; i< M.size(); i++)
	{
		M[i][index] = newColumn[i];
	}

}


template<typename T>
void rotateMatrixR(T& M)
{

	translateMatrix(M);
	const int rows = M.size();
	const int cols = M[0].size();
	typename T::value_type::value_type tmp;


	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols/2; j++)
		{
			tmp = M[i][j];
			M[i][j] = M[i][cols-1];
			M[i][cols-1] = tmp;
		}
	}


}

template<typename T>
void rotateMatrixL(T& M)
{

	translateMatrix(M);
	typename T::value_type::value_type tmp;
	const int rows = M.size();
	const int cols = M[0].size();
	for(int i = 0; i < rows/2; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			tmp = M[i][j];
			M[i][j] = M[rows - i][j];
			M[rows-i][j] = tmp;
		}
	}


}

}
#endif