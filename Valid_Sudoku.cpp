//File Name  : Valid_Dudoku.cpp 
//Author     : Avanty
//Date       : 2014/5/18  2:59PM
//Decription :
//
//Valid Sudoku
//Total Accepted: 8433 Total Submissions: 30639
//
//Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//
//A partially filled sudoku which is valid.
//
//Note:
//A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int i,j,mid_x,mid_y;
        bool isused[10];
        bool isused_v[10];
        memset(isused,0,sizeof(isused));
        memset(isused_v,0,sizeof(isused_v));
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(isused[board[i][j] - '0'] == true) return false;
                    isused[board[i][j] - '0'] = true;
                }
                if(board[j][i] != '.') {
                    if(isused_v[board[j][i] - '0'] == true) return false;
                    isused_v[board[j][i] - '0'] = true;
                }
            }
            memset(isused,0,sizeof(isused));
            memset(isused_v,0,sizeof(isused_v));
        }
        memset(isused,0,sizeof(isused));
        for(i = 0; i < 9; i=i+3){
            for(j = 0; j < 9; j=j+3){
                for(mid_x = i; mid_x < i+3; mid_x++){
                    for(mid_y = j; mid_y < j+3;mid_y++){
                        if(board[mid_x][mid_y] != '.'){
                            if(isused[board[mid_x][mid_y] - '0'] == true) return false;
                            isused[board[mid_x][mid_y] - '0'] = true;
                        }
                    }
                }
                memset(isused,0,sizeof(isused));
            }
        }
        return true;
    }
        
};

int main(){
    return 0;
}
