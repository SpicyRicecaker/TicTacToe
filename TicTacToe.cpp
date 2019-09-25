#include <iostream>
#include <cstring>
#define X 2
#define O 3

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
    
  init(board, turn);

  bool running = true;

  while(running){
    printBoard(board);

    cout << "It is player " << turn + 1 << "'s turn!" << endl;
    running = false;
  }

}


