#include <iostream>

using namespace std;

bool playAgain();
void resetBoard(char board[3][3]);
void makeBoard(char board[3][3]);
bool checkWin(char player, char board[3][3]);

int main() {
  char board[3][3] ={ {' ',' ',' '},
		      {' ',' ',' '},
		      {' ',' ',' '} };
  int row = -1;
  char rowIn = ' ';
  int col = -1;
  char player = 'X'; //X is starting player
  int turns = 0;
  bool gameStatus = true;
  int xWins = 0;
  int oWins = 0;
  int ties = 0;
  
  while (gameStatus) {
    makeBoard(board); //print board to start a turn
  
    bool correctInput = false;
    //Wait till the user enters a valid input
    while (correctInput == false) {
      cout << "Enter a row (a-c) and column (1-3)" << endl;

      //Prevent the console from printing to infinity
      while (cin.fail()) {
	cin.clear();
	cin.ignore(100, '\n');
      }
  
      cin >> rowIn >> col; //input will look like: 'row''column'. Ex: a1

      col--; //aline with array starting at 0 (so if user enters 3 it's actually 2 in the array)

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
    //set the player's move on the board
    board[row][col] = player;

    //Check if that player made a winning move
    if (checkWin(player, board)) {
      makeBoard(board);
      cout << player << " Wins!" << endl;
      (player == 'X') ? xWins++ : oWins++; //add to the total win counter
      cout << "X Wins: " << xWins << "    O Wins: " << oWins << "    Ties: " << ties << endl;  
      if (playAgain()) {
	resetBoard(board);
	turns = 0;
      } else {
	gameStatus = false;
      }
    }

    turns++;
    //Switch players
    player = (player == 'X') ? 'O' : 'X'; //if player == X then swtich O if not switch X

  //Check for a Tie
  if (turns == 9 && !checkWin('X', board) && !checkWin('X', board)) {
    makeBoard(board);
    cout << "Tie" << endl;
    ties++;
    cout << "X Wins: " << xWins << "    O Wins: " << oWins << "    Ties: " << ties << endl;
    if (playAgain()) {
      resetBoard(board);
      turns = 0;
    } else {
      gameStatus = false;
    }
  }
 }
  return 0;
}

//prompts player if they want to play again
bool playAgain() {
  char answ;
  cout << "Play again? (y/n)" << endl;
  cin >> answ;

  if (answ == 'n') {
    return false;
  } else if (answ == 'y') {
    return true;
  }
  return false;
}

//resets the board to blank
void resetBoard(char board[3][3]) {
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      board[x][y] = ' ';
    }
  }
}

//display the board in the console
void makeBoard(char board[3][3]) {
  int rowNum = 0;
  cout << "-----------" << endl;
  cout << " " << " 1 2 3" << endl; //column numbers
  for (int x = 0; x < 3; x++) {
    //Printing the row numbers
    if (rowNum == 0) {cout << "a ";}
    if (rowNum == 1) {cout << "b ";}
    if (rowNum == 2) {cout << "c ";}
    for (int y = 0; y < 3; y++) {
      cout << board[x][y] << " "; //print out the board spaces  
    }
    rowNum++; //incriment for each row
    cout << "\n";
  }
  cout << "-----------" << endl;
}

//checks for win conditions
bool checkWin(char player, char board[3][3]) {
  for (int i; i < 3; i++) {
    //horizontal
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    } else if (board[i][0] == player && board[i][1] == player && board[i][2]) { //vertical
      return true;
    }
  }
  //diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  } else if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
    return true;
  }
  return false;
}


