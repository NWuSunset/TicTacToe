#include <iostream>

using namespace std;

//Declare function arguments
const int BLANK = 0;
const int  X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;

void userInput(char &row, int &col);
void makeBoard(char board[3][3]);

int main() {
  char board[3][3] ={ {' ',' ',' '},
		      {' ',' ',' '},
		      {' ',' ',' '} };
  int row = -1;
  char rowIn = ' ';
  int col = -1;
  char player = 'X'; //X is starting player

  
  makeBoard(board);
  
  bool correctInput = false;
  while (correctInput == false) {
  cout << "Enter a row (a-c) and column (1-3)" << endl;
  cin >> rowIn >> col;

  col--; //aline with array starting at 0

  //set the rows to the row numbers in the array
  if (rowIn == 'a') {
    row = 0;
  } else if (rowIn == 'b') {
    row = 1;
  } else if (rowIn == 'c') {
    row = 2;
  }

  //check for invalid inputs
  if (row > 2 || row < 0 || col > 2 || col < 0) {
    cout << "Invalid column. Try again" << endl;
  } else if (board[row][col] != ' ') {
    cout << "Invalid move. Try again" << endl;
  } else {
    correctInput = true;
  }
  
  }  
  cout << row << col << endl;

  board[row][col] = player;

  //checkWin; //impliment this later

  //Switch players
  player = (player == 'X') ? 'O' : 'X'; //if player == X then swtich O if not switch X
  
  return 0;
}

void makeBoard(char board[3][3]) {
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      cout << board[x][y]; //print out a column  
    }
    cout << "\n"; 
  }
}

void userInput(char &row, int &col) {
  cout << "enter the row you want" << endl;
  cin >> row;
  if (row == 'a' || row == 'b' || row == 'c') {
    
  }
  cout << row << endl;
  cout << "enter the column you want" << endl;
  cin >> col;
}
