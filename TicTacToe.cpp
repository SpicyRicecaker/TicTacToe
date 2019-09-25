#include <iostream>
#include <cstring>
#define X_PIECE 2
#define O_PIECE 3
#define X_TURN 4
#define O_TURN 5
#define BLANK 0

void init(int (&board)[3][3], int& turn);
void printBoard(int (&board)[3][3]);
bool checkWin(int pc, int (&board)[3][3]);
bool checkTie(int (&board)[3][3]);

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

bool checkWin(int pc, int (&board)[3][3]){
  if((board[0][0]==pc && board[0][1]==pc && board[0][2]==pc) || (board[1][0]==pc && board[1][1]==pc && board[1][2]==pc) || (board[2][0]==pc && board[2][1]==pc && board[2][2]==pc)){
  }else if ((board[0][0]==pc && board[1][0]==pc && board[2][0]==pc) || (board[1][0]==pc && board[1][1]==pc && board[1][2]==pc) || (board[2][0]==pc && board[2][1]==pc && board[2][2]==pc)){
  }else if((board[0][0]==pc && board[1][1]==pc && board[2][2]==pc) || (board[0][2]==pc && board[1][1]==pc && board[2][0]==pc)){ 
  }else{
    return false;
  }
  return true;
}

bool checkTie(int (&board)[3][3]){
  int pcs = 0;
  for(int a = 0; a < 3; a++){
    for(int b = 0; b < 3; b++){
      if(board[b][a]!=BLANK){
	pcs++;
      }
    }
  }
  if(pcs==9){
    return true;
  }
  return false;
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
      cout << "Make sure you choose an empty square :)" << endl;
    }

    if(checkWin(X_PIECE, board)==true){
      cout << "X Wins!" << endl;
      xWins++;
    }else if(checkWin(O_PIECE, board)==true){
      cout << "O Wins!" << endl;
      oWins++;
    }else if(checkTie(board)==true){
      cout << "It's a tie!" << endl;
    }else{
      continue;
    }

    cout << "Play again? (Y/N)" << endl;

    char in[3] = "";
    
    while(true){
      cin.get(in, 999);
      cin.clear();
      cin.ignore(999, '\n');

      if(strlen(in)==1 && (in[0] == 'Y' || in[0] == 'y' || in[0] == 'N' || in[0] == 'n')){
	break;
      }

      cout << "Please enter Y or N" << endl;
    }

    if(in[0] == 'N'){
      running = !running;
    }else {
      cout << "X Wins: " << xWins << ", O Wins: " << oWins << endl;
      init(board, turn);
    }
  }

}


