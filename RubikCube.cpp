#include "headers/RubikCube.h"
#include <cassert>
#include <iostream>
#include <cstdlib>
#include "headers/MatrixOps.h"

using namespace std;
using namespace matrixops;

RubikCube::RubikCube(const unsigned  dimensions, const unsigned columns, const unsigned rows):m_columnsnum(columns),
m_sidesnum(dimensions), m_rowsnum(rows)
{

	m_sides.resize(dimensions);
	for(int i = 0; i < dimensions; i++)
	{
		m_sides[i].resize(rows);
		for(int j = 0; j < rows; j++)
		{
			m_sides[i][j].resize(columns);
			for(int k = 0; k < columns; k++)
			{
				m_sides[i][j][k] = rand() % 256;
			}
		}
	}

	randomize();
}

const char RubikCube::operator()(unsigned side, unsigned i, unsigned j)
{	
	assert(side >= 0 && i >= 0 && j >= 0);
	assert(side < m_sidesnum && i < m_rowsnum && j < m_columnsnum);
	
	return m_sides[side][i][j];
}


/*	
	Shifts are supposed clockwise y axis, clockwise x axis, counter clockwise z axis. The method is supplied with a
	column index.
*/
void RubikCube::turnUp(unsigned side, unsigned index)
{	
	if(side < 0 || side > 5)
		throw "Invalid side operation";
	indexCheck(index);
	
	unsigned rot, shift1, shift2,shift3;
	decideSidesDU(side, rot, shift1, shift2, shift3);
	rotateMatrixR(m_sides[side]);
	
	

}

void RubikCube::turnDown(unsigned side, unsigned index)
{
	indexCheck(index);
}

void RubikCube::turnLeft(unsigned side, unsigned index)
{
	indexCheck(index);
}

void RubikCube::turnRight(unsigned side, unsigned index)
{
	indexCheck(index);
}


/*
	Front side: 0
	Back side: 	5
	Down side:	1
	Up side:	3
	Left side:	2
	Right side:	4

	Alternative???

*/

void RubikCube::decideSidesDU(unsigned& side, unsigned& rot, unsigned& shift1, unsigned& shift2, unsigned& shift3) {

	switch(side)
	{
		case 0:
			rot = 4;
			shift1 = 3;
			shift2 = 5;
			shift3 = 1;
			break;
		case 1:
			rot = 4;
			shift1 = 0;
			shift2 = 3;
			shift3 = 5;
			break;
		case 2:
			rot = 0;
			shift1 = 3;
			shift2 = 4;
			shift3 = 1;
			break;
		case 3:
			rot = 4;
			shift1 = 5;
			shift2 = 1;
			shift3 = 0;
			break;
		case 4:
			rot = 0;
			shift1 = 1;
			shift2 = 2;
			shift3 = 3;
			break;
		case 5:
			rot = 4;
			shift1 = 1;
			shift2 = 0;
			shift3 = 3;
			break;
	}

}


void RubikCube::decideSidesLR(unsigned& side, unsigned& rot, unsigned& shift1, unsigned& shift2, unsigned& shift3) {

	switch(side)
	{
		case 0:
			rot = 3;
			shift1 = 2;
			shift2 = 5;
			shift3 = 4;
			break;
		case 1:
			rot = 0;
			shift1 = 2;
			shift2 = 3;
			shift3 = 4;
			break;
		case 2:
			rot = 3;
			shift1 = 5;
			shift2 = 4;
			shift3 = 0;
			break;
		case 3:
			rot = 0;
			shift1 = 4;
			shift2 = 1;
			shift3 = 2;
			break;
		case 4:
			rot = 3;
			shift1 = 0;
			shift2 = 2;
			shift3 = 5;
			break;
		case 5:
			rot = 3;
			shift1 = 4;
			shift2 = 0;
			shift3 = 2;
			break;
	}
}


ostream& operator<<(ostream& out, RubikCube& rc)
{
	for(int i = 0; i < rc.m_sidesnum; i++)
	{
		out << "--------- Side " <<  i+1 << " ------------" << endl;
		for(int j = 0; j < rc.m_rowsnum; j++)
		{	
			out << endl;
			for(int k = 0; k < rc.m_columnsnum; k++)
			{
				out << (int)rc.m_sides[i][j][k] << "\t"; 
			}
			out << endl;
		}
		out << endl;
	}
	return out;
}

void RubikCube::indexCheck(const unsigned int& index)
{

	if(index >= m_sides[0][0].size() || index < 0)
		throw "Index not in borders";

}


//TODO Randomize cube
bool RubikCube::randomize()
{

	for(int i = 0; i < 100; i++)
	{
		
	}

}