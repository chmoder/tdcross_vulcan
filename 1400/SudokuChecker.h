//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm14
//Due Date      :10.23.08
//
//Honor Pledge  On my honor as a student of the University of Nebraska at Omaha,
// I have neither given nor recieved unauthorized help on this homework
// assignment.
//
//Signed1: Thomas Cross
//Signed2: 1337
//Signed3: tom.bz2@gmail.com

//Partners  :List the full names, CIST 1400 section and e-mail addresses

// class sudoku checker

class SudokuChecker
{
	public:
		SudokuChecker ();
		void readGrid();
		void checkGrid();
	private:
	int x;
	int y;
	int sumR1, sumR2, sumR3, sumR4, sumC1, sumC2, sumC3, sumC4, sumQ1, sumQ2, sumQ3,sumQ4;
	int a, aa, aaa, aaaa, b, bb, bbb, bbbb, c, cc, ccc, cccc, d, dd, ddd, dddd;
int sudokutrue;

};
