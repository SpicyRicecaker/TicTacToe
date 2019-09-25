#include <iostream>
#include <cstring>
#define X_PIECE 2
#define O_PIECE 3

void init(int (&board)[3][3], int& turn);
void printBoard(int (&board)[3][3]);

using namespace std;

void init(int (&board)[3][3], int& turn){
  for(int a = 0; a < 3; a++){
    for(int b = 0; b < 3; b++){
      board[b][a] = 0;
    }
  }
  turn = 0;
}

void printBoard(int (&board)[3][3]){
  cout << "    1   2   3\n" << endl;
  for(int a = 0; a < 3; a++){
    cout << (char)(a + 'A') << "   ";
    for(int b = 0; b < 3; b++){
      if (board[b][a] == 0){
	cout << "_   ";
      }
    }
    cout << "\n" << endl;
  }
}

int main(){
  int board[3][3];
  int turn;
  
  int xWins = 0;
  int oWins = 0;

  char decMove[4] = "";
    
  init(board, turn);

  bool running = true;

  while(running){
    printBoard(board);

    cout << "It's player " << turn + 1 << "'s turn!" << endl;

    cin.get(decMove, 4);
    cin.get();

    while(strlen(decMove) != 2 || ((decMove[0]!='A') && (decMove[0]!='a') && (decMove[0]!='B') && (decMove[0]!='b') && (decMove[0]!='C') && (decMove[0]!='c')) || ((decMove[1]!='1') && (decMove[1]!='2') && (decMove[1]!='3'))){
      cout << "Please enter a valid row letter followed by column number with no spaces in between. (e.g. A1)" << endl;
      cin.get(decMove, 999);
      cin.get();
    }

    cout << decMove << endl;

    
    running = false;
  }

}


