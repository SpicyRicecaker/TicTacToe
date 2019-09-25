#include <iostream>
#include <cstring>
#define X_PIECE 2
#define O_PIECE 3
#define X_TURN 4
#define O_TURN 5
#define BLANK 0

void init(int (&board)[3][3], int& turn);
void printBoard(int (&board)[3][3]);

using namespace std;

void init(int (&board)[3][3], int& turn){
  for(int a = 0; a < 3; a++){
    for(int b = 0; b < 3; b++){
      board[b][a] = BLANK;
    }
  }
  turn = X_TURN;
}

void printBoard(int (&board)[3][3]){
  cout << "    1   2   3\n" << endl;
  for(int a = 0; a < 3; a++){
    cout << (char)(a + 'A') << "   ";
    for(int b = 0; b < 3; b++){
      if (board[b][a] == BLANK){
	cout << "_   ";
      }else if (board[b][a] == X_PIECE){
	cout << "X   ";
      }else if (board[b][a] == O_PIECE){
	cout << "O   ";
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

    cout << "It's player " << ((turn == X_TURN) ? "X" : "O") << "'s turn!" << endl;
    
    while(true){
      
      cin.get(decMove, 999);
      //cin.get() not sure why I need to remove but.
      cin.clear();
      cin.ignore(999, '\n');

      if(strlen(decMove) == 2 && ((decMove[0]=='A') || (decMove[0]=='a') || (decMove[0]=='B') || (decMove[0]=='b') || (decMove[0]=='C') || (decMove[0]=='c')) && ((decMove[1]=='1') || (decMove[1]=='2') || (decMove[1]=='3'))){
	decMove[0] = (int)toupper(decMove[0])-17;
	decMove[1]--;
	break;
      }
      
      cout << "Please enter a valid row letter followed by a valid column number :)" << endl;
    }

    
    
    if(board[decMove[1]-48][decMove[0]-48] == BLANK){
      if(turn == X_TURN){
	board[decMove[1]-48][decMove[0]-48] = X_PIECE;
	turn = O_TURN;
      }else{
	board[decMove[1]-48][decMove[0]-48] = O_PIECE;
        turn = X_TURN;
      }
    }else{
      cout << "Invalid Input" << endl;
    }

    
    

  }

}


