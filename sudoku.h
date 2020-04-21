#pragma once
#include<bits/stdc++.h>
#include<iostream>

class sudoku
{
public:
    int cells[9][9];
public:
    void displaySudoku();
    bool useRow(int row,int number);
    bool useCol(int col,int number);
    bool useBox(int row,int col,int number);
    bool isValid(int row,int col,int number);
    bool findUnassignedLocation( int &row, int &col);
    bool solveSudoku();
};



//return true if the number has been used in the row
bool sudoku::useRow(int row, int number) {
  for (int col = 0; col < 9; col++)
    if (cells[row][col] == number)
      return true;
  return false;
}

// returns true if the number has been used in the column
bool sudoku::useCol(int col, int number) {
  for (int row = 0; row < 9; row++)
    if (cells[row][col] == number)
      return true;
  return false;
}

// returns true if the number has been used in the 3x3 box
bool sudoku::useBox(int row, int col, int number) {
  int StartRow = row - row % 3;
  int  StartCol = col - col % 3;
  for (int ii = 0; ii < 3; ii++)
    for (int jj = 0; jj < 3; jj++)
      if (cells[StartRow + ii][StartCol + jj] == number)
        return true;
  return false;
}


// checks whether or not it is valid to place "number" in the given position
bool sudoku::isValid( int row, int col, int number) {
  return !useRow(row, number) &&
       !useCol( col, number) &&
       !useBox(row, col, number);
}

// finds the first  empty cell in sudoku grid
bool sudoku::findUnassignedLocation( int &row, int &col) {
  for (row = 0; row < 9; row++)
    for (col = 0; col < 9; col++)
      if (cells[row][col] == 0)
        return true;
  return false;
}

// main sudoku solver function
bool sudoku::solveSudoku() {
  int row, col;

  //if sudoku is complete then return true
  if (!findUnassignedLocation( row, col))
    return true;

  for (int number = 1; number <= 9; number++) {
    // if safe
    if (isValid( row, col, number)) {
      // assign value
      cells[row][col] = number;

      if (solveSudoku())
        return true;

      cells[row][col] = 0;
    }
  }
  return false; // this triggers backtracking
}

// display the sudoku
void sudoku::displaySudoku() {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++)
      std::cout << cells[row][col] << " ";
    std::cout << std::endl;
  }
}
