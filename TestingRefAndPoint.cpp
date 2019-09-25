#include <iostream>

void addOne(int (&ptrBoard)[3][3]);
void printBoard(int board[3][3]);

using namespace std;

void addOne(int (&ptrBoard)[3][3]){
  
  for(int a = 0; a < 3; a++){
    for(int b = 0; b < 3; b++){
      ptrBoard[b][a] += 1;
    }
  }
}

void printBoard(int board[3][3]){
  for(int a = 0; a < 3; a++){
    for(int b = 0; b < 3; b++){
      cout << board[b][a] << " ";
    }
    cout << "" << endl;
  }
}

int main(){
  int board[3][3];
  for(int a = 0; a < 3; a++){
    for(int b = 0; b < 3; b++){
      board[b][a] = 5;
    }
  } 
  
  addOne(board);

  printBoard(board);
}

  
