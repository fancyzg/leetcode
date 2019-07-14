//Word Search Total Accepted: 8583 Total Submissions: 44303 My Submissions
//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//For example,
//Given board =
//
//[
//  ["ABCE"],
//  ["SFCS"],
//  ["ADEE"]
//]
//word = "ABCCED", -> returns true,
//word = "SEE", -> returns true,
//word = "ABCB", -> returns false.
//
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isexist(vector<vector<char> >&board, int x, int y, vector<vector<bool> > & isused, string word){
        if(isused[x][y] == true) return false;
        if(word.length() == 1) return true;
        isused[x][y] = true;
        bool real = false;
        if(x-1 >= 0 && board[x-1][y] == word[1]) real = real || isexist(board,x-1,y,isused,word.substr(1));
        if(real){
            isused[x][y] = false;
            return true;
        }
        if(x+1 < board.size() && board[x+1][y] == word[1]) real = real || isexist(board,x+1,y,isused,word.substr(1));
        if(real){ 
            isused[x][y] = false;
            return true;
            
        }
        if(y-1 >= 0 && board[x][y-1] == word[1]) real = real || isexist(board,x,y-1,isused,word.substr(1));
        if(real){ 
            isused[x][y] = false;
            return true;}
        if(y+1 <board[0].size() && board[x][y+1] == word[1]) real = real || isexist(board,x,y+1,isused,word.substr(1));
        if(real){ 
            isused[x][y] = false;
            return true;
            
        }
        
        isused[x][y] = false;
        return real;
    }
    bool exist(vector<vector<char> > &board, string word) {
        if(word.length() == 0) return true;
        int i,j,k;
        int len,width;
        vector<int> vec_x,vec_y;
        width = board.size();
        if(width == 0) return false;
        len = board[0].size();
        if(len == 0) return false;
        vector<vector<bool> > isused(width,vector<bool>(len,false));
        for(i = 0; i < width; i++){
            for(j = 0; j < len; j++){
                if(word[0] == board[i][j]){
                    vec_x.push_back(i);
                    vec_y.push_back(j);
                }
            }
        }
        bool real = false;
        for(i = 0; i < vec_x.size(); i++){
            real = isexist(board,vec_x[i],vec_y[i],isused,word);
            if(real) return true;
        }
        return false;
    }
};

int main(){
    vector<vector<char> > board;
    vector<char> line;
    line.push_back('a');
    line.push_back('b');
    line.push_back('c');
    board.push_back(line);
    line[0] = 'a';
    line[1] = 'e';
    line[2] = 'd';
    board.push_back(line);
    line[0] = 'a';
    line[1] = 'f';
    line[2] = 'g';
    board.push_back(line);
    Solution sl;
    cout<<sl.exist(board,"abcdefg")<<endl;
    return 0;
}
