#ifndef MATRIX_H_
#define MATRIX_H_
#include <vector>
#include <sstream>
#include <iostream>


template<typename T>
class Matrix
{	
	private:

		vector<vector<T> > m_elements;

	public:

		Matrix(vector<vector<T> > m);
		Matrix(uint& size);

		void rotateR();
		void rotateL();
		void transpose();

		T operator(unsigned& i, unsigned& j)();
		

};




#endif