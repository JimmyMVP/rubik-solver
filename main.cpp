#include "headers/RubikCube.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char **argv)
{

	RubikCube rc(6,3,3);
	cout << rc << endl;
	rc.turnUp(0, 3);
	cout << rc << endl;


	getchar();
	return 0;
}


