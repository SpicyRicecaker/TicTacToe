/*
  Author: Andy Li
  Date: 9/26/2019
  TicTacToe: A program that simulates a game of Tic Tac Toe between two players, using the command line.
*/
#include <iostream>
#include <cstring>
#define X_PIECE 2
#define O_PIECE 3
#define X_TURN 4
#define O_TURN 5
#define BLANK 0

void init(int (&board)[3][3]);
void printBoard(int (&board)[3][3]);
bool checkWin(int pc, int (&board)[3][3]);
bool checkTie(int (&board)[3][3]);

using namespace std;

//The init function initializes or clears the board
void init(int (&board)[3][3]){
  for(int a = 0; a < 3; a++){
    for(int b = 0; b < 3; b++){
      board[b][a] = BLANK;
    }
  }
}

//The printboard function prints out the row letter and column number of the board in addition to the pieces and blank spaces
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

//The check win function takes in a specified piece and the board and returns true if that piece appears 3 times in a row in any horizontal, vertical, or diagonal fashion, otherwise false
bool checkWin(int pc, int (&board)[3][3]){
  //Horizontals
  if((board[0][0]==pc && board[0][1]==pc && board[0][2]==pc) || (board[1][0]==pc && board[1][1]==pc && board[1][2]==pc) || (board[2][0]==pc && board[2][1]==pc && board[2][2]==pc)){
  }
  //Veritcals
  else if ((board[0][0]==pc && board[1][0]==pc && board[2][0]==pc) || (board[1][0]==pc && board[1][1]==pc && board[1][2]==pc) || (board[2][0]==pc && board[2][1]==pc && board[2][2]==pc)){
  }
  //Diagonals
  else if((board[0][0]==pc && board[1][1]==pc && board[2][2]==pc) || (board[0][2]==pc && board[1][1]==pc && board[2][0]==pc)){ 
  }else{
    return false;
  }
  return true;
}

//The checkTie function checks if the board has been filled up or not
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

//Main function of the program, includes game loop
int main(){
  //Setting up variables needed to run the game 
  int board[3][3];
  int turn = X_TURN;
  
  int xWins = 0;
  int oWins = 0;

  char decMove[4] = "";
    
  init(board);

  bool running = true;

  //Every turn
  while(running){
    //Print out the current board
    printBoard(board);

    //Tell the current player's turn
    cout << "It's player " << ((turn == X_TURN) ? "X" : "O") << "'s turn!" << endl;

    //Then scan for a valid move by 
    while(true){
      //Getting 4 char inputs, so we can check if the length of the string is greater than 2
      cin.get(decMove, 4);
      //Resetting the error flag, so future input works  
      cin.clear();
      //Then skipping the next 999 characters until the new line
      cin.ignore(999, '\n');

      //Then accept the input if and only if the length of the string is 2, the first character is A,a,B,b,C, or c, and the second character is 1,2, or 3
      if(strlen(decMove) == 2 && ((decMove[0]=='A') || (decMove[0]=='a') || (decMove[0]=='B') || (decMove[0]=='b') || (decMove[0]=='C') || (decMove[0]=='c')) && ((decMove[1]=='1') || (decMove[1]=='2') || (decMove[1]=='3'))){
	//Convert these characters to the actual matrix coordinates, so they are easier to modify later
	decMove[0] = (int)toupper(decMove[0])-17;
	decMove[1]--;
	//Then get away with our input
	break;
      }
      //Or tell the user that their input is invalid and repeat the process over again 
      cout << "Please enter a valid row letter followed by a valid column number :)" << endl;
    }
    
    //Then check if that chosen square is occupied or not, otherwise place the corresponding piece to the turn
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

    //Then check for game-ending conditions like wins or ties, and increment the win counter if needed
    if(checkWin(X_PIECE, board)==true){
      cout << "X Wins!" << endl;
      xWins++;
      turn = X_TURN;
    }else if(checkWin(O_PIECE, board)==true){
      cout << "O Wins!" << endl;
      oWins++;
    }else if(checkTie(board)==true){
      cout << "It's a tie!" << endl;
    }else{
      continue;
    }

    //Prompt the user if they want to play again, accepting only Y,y,N, or n 
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

    //If they say no, exit the program, otherwise reset the board and continue
    if(in[0] == 'N'){
      running = !running;
    }else {
      cout << "X Wins: " << xWins << ", O Wins: " << oWins << endl;
      init(board);
    }
  }

}


