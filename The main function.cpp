#include <iostream>
#include"sudoku.h"
using namespace std;

int main() {
  sudoku grid;

  /*
  for example:
   0 0 0 2 6 0 7 0 1
   6 8 0 0 7 0 0 9 0
   1 9 0 0 0 4 5 0 0
   8 2 0 1 0 0 0 4 0
   0 0 4 6 0 2 9 0 0
   0 5 0 0 0 3 0 2 8
   0 0 9 3 0 0 0 7 4
   0 4 0 0 5 0 0 3 6
   7 0 3 0 1 8 0 0 0
  */

  cout << "Enter the numbers in Sudoku grid (Use 0 for empty cells): " << endl;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> grid.cells[i][j];
    }
  }
  cout << endl;

  if (grid.solveSudoku() == true) {
    cout << "The Solution is: " << endl;
    grid.displaySudoku();
  } else {
    cout << "There is no Solution" << endl;
  }

  return 0;
}
