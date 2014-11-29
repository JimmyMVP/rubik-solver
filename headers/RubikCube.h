#ifndef RUBIK_H
#define RUBIK_H

#include <iostream>
#include <vector>
using namespace std;

enum Part{ROW, COLUMN};
class RubikCube
{
	private:
		 vector<vector<vector<unsigned char> > > m_sides;
		const unsigned m_rowsnum, m_columnsnum, m_sidesnum;
		void indexCheck(const unsigned int& index, Part p);
<<<<<<< HEAD
		void decideSidesDU(unsigned& side, unsigned& rot, unsigned& shift1, unsigned& shift2, unsigned& shift3);
		void decideSidesLR(unsigned& side, unsigned& rot, unsigned& shift1, unsigned& shift2, unsigned& shift3);
=======
		void decideSides(unsigned& side, unsigned& rot, unsigned& shift1, unsigned& shift2, unsigned& shift3);
>>>>>>> d49550ef796194c2effd8804f5070caa16bc15d1

	public:

		RubikCube(const unsigned  dimensions, const unsigned rows, const unsigned columns);
		bool randomize();
		const char operator()(unsigned side, unsigned i, unsigned j);
		friend ostream& operator<<(ostream& out, RubikCube& rc);
		void turnUp(unsigned side, unsigned index, Part p);
		void turnDown(unsigned side, unsigned index, Part p);


};
#endif