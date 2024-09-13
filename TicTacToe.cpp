#include <iostream>

using namespace std;

//Declare function arguments
const int BLANK = 0;
const int  X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;

void userInput(char &row, int &col);

int main() {
  int board[3][3];
  char rowIn = 'z';
  int colIn = 0;

  if (rowIn == 'a' || rowIn == 'b' || rowIn == 'c') {
    
  }



  
  return 0;
}

void userInput(char &row, int &col) {
  cout << "enter the row you want" << endl;
  cin >> rowIn;
  if (rowIn == 'a' || rowIn == 'b' || rowIn == 'c') {
    
  }
  cout << rowIn << endl;
  cout << "enter the column you want" << endl;
  cin >> colIn;
}
