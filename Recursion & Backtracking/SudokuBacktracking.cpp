#include<bits/stdc++.h>
#define N 9
using namespace std;
bool findEmptyLocation(int board[N][N] , int &row , int &col){
             for(int i = 0 ; i < N ; i++){
                for(int j=0 ; j < N ; j++){
                    if(board[i][j] == 0){
                        row = i;
                        col = j;
                        return true;
                    }
                }
             }
             return false ;
}
bool isSaferow(int board[N][N] , int row , int num){
    for(int i = 0 ; i < N ; i++){
        if(board[row][i] == num){
            return false;
        }
    }
    return true;
}
bool isSafecol(int board[N][N] , int col , int num){
    for(int i = 0 ; i < N ; i++){
        if(board[i][col] == num){
            return false;
        }
    }
    return true;
}
bool isSafeGrid(int board[N][N] ,int row , int col , int num){
         int rowF = row - (row % 3);
         int colF = col - (col % 3);
         for(int i = 0 ; i  < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(board[i+rowF][j+colF] == num){
                    return false;

                }
            }
         }
         return true;
}
bool isSafe(int board[N][N] , int row , int col , int i){
if(isSaferow(board, row , i) && isSafecol(board , col , i) && isSafeGrid(board , row , col , i)){
    return true;
}
return false;

}



bool sudokuSolver(int board[][9])
{
    int row , col;
    if(!findEmptyLocation(board , row , col)){
        return true;
    }

    for(int i = 1 ; i <= 9 ;i++){
        if(isSafe(board , row , col , i)){
            board[row][col] = i;
            if(sudokuSolver(board)){
                return true ;

            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int bo[9][9];
    for(int i = 0; i < 9 ; i++){
        string s;
        cin >> s;
        for(int j = 0 ; j < 9 ; j++)
            bo[i][j] = s[j] - '0';
    }

    sudokuSolver(bo);
    for(int i = 0; i<9 ; i++)
        for(int j = 0; j < 9 ; j++)
            cout << bo[i][j] << " ";
        cout << "\n";


}


