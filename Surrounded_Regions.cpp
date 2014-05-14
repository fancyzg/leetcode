//File Name  : Surrounded_regions.cpp
//Author     : Avanty
//Date       : 2014/5/12  2:38PM
//Decription :
//Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//For example,
//X X X X
//X O O X
//X X O X
//X O X X
//After running your function, the board should be:
//
//X X X X
//X X X X
//X X X X
//X O X X

#include<iostream>
#include<vector>
using namespace std;

void fill_region(int i, int j,vector<vector<char>> &board, bool ** matrix){
	int row,col;
	int x,y;
	bool isedge = false;
	vector<int> row_stk;
	vector<int> col_stk;
	vector<int> row_stk_s;
	vector<int> col_stk_s;
	row = board.size();
	col = board.back().size();
	matrix[i][j] = true;
	row_stk.push_back(i);
	col_stk.push_back(j);
	row_stk_s.push_back(i);
	col_stk_s.push_back(j);
	while(!row_stk.empty()){
	    x = row_stk.back();
	    y = col_stk.back();
	    row_stk.pop_back();
	    col_stk.pop_back();
	    if(x == 0 || x == row -1 || y == 0 || y == col -1){
		isedge = true;
	    }
	    if(x-1>=0 &&  board[x-1][y] == 'O' && matrix[x-1][y] == false) { matrix[x-1][y] = true; row_stk.push_back(x-1); col_stk.push_back(y); row_stk_s.push_back(x-1); col_stk_s.push_back(y);}
	    if(x+1<=row-1 && board[x+1][y] == 'O' && matrix[x+1][y] == false) { matrix[x+1][y] = true; row_stk.push_back(x+1); col_stk.push_back(y); row_stk_s.push_back(x+1); col_stk_s.push_back(y);}
	    if(y-1>=0 && board[x][y-1] == 'O' && matrix[x][y-1] == false) { matrix[x][y-1] = true; row_stk.push_back(x); col_stk.push_back(y-1); row_stk_s.push_back(x); col_stk_s.push_back(y-1);}
	    if(y+1<=col-1 && board[x][y+1] == 'O' && matrix[x][y+1] == false) { matrix[x][y+1] = true; row_stk.push_back(x); col_stk.push_back(y+1); row_stk_s.push_back(x); col_stk_s.push_back(y+1);}
	}
	if(isedge == false){
	    while(!row_stk_s.empty()){
		x = row_stk_s.back();
		y = col_stk_s.back();
		row_stk_s.pop_back();
		col_stk_s.pop_back();
		board[x][y] = 'X';
	    }
	}
}

class Solution {
public:
    void solve(vector<vector<char>> &board) {
	int i,j;
	int row,col;
	bool **matrix;
	row = board.size();
	if(row == 0) return;
	col = board.back().size();
	if(col == 0) return;
	matrix = new bool *[row];
	for(i = 0; i < row; i++){
	    matrix[i] = new bool [col];
	}
	for(i = 0 ; i < row; i++){
	    for(j = 0; j < col; j++){
		matrix[i][j] = false;
	    }
	}
	for(i = 0 ; i < row; i++){
	    for(j = 0; j < col; j++){
		if(board[i][j] == 'O' && matrix[i][j] == false){
		    fill_region(i,j,board,matrix);
		}
	    }
	}
    }
};

int main(){
    int i,j;
    vector<vector<char>> board;
    vector<char> line;
    line.push_back('X');
    line.push_back('X');
    line.push_back('X');
    line.push_back('X');
    board.push_back(line);
    line[1] = 'O';
    line[2] = 'O';
    board.push_back(line);
    line[1] = 'X';
    board.push_back(line);
    line[1] = 'O';
    line[2] = 'X';
    board.push_back(line);
    Solution sl;
    sl.solve(board);
    for(i = 0; i < board.size(); i++){
	for(j = 0; j < board.back().size();j++){
	    cout<<board[i][j]<<" ";
	}
	cout<<endl;
    }
    return 0;

}
