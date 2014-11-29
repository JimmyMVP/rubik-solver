#include "headers/RubikCube.h"
#include <iostream>
#include <windows.h>
#include "headers/MatrixOps.h"
#include <vector>
using namespace std;

template <typename T>
void vectorChange(T& v)
{
	for(int i = 0; i < v.size(); i++)
	{
		v[i] = 45;
	}
}



int main(int argc, char **argv)
{

	RubikCube rc(6,3,3);
	cout << "Made rubik cube!" << endl;
	
	cout << rc << endl;

	rc.turnUp(0, 3, COLUMN);

	cout << rc << endl;


	system("pause");
	return 0;
}


