//File Name  : Simplify_Path.cpp 
//Author     : Avanty
//Date       : 2014/5/27  5:54PM
//Description:
//Spiral Matrix Total Accepted: 8217 Total Submissions: 40481 My Submissions
//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//Given the following matrix:
//
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//You should return [1,2,3,6,9,8,7,4,5].
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int i,j,n,m,step,cur_step,len_h,len_v,acc;
        vector<int> vec;
        i = 0;
        j = -1;
        n = matrix.size();
        if(n == 0) return vec;
        m = matrix[0].size();
        step = m*n;
        cur_step = 0;
        len_v = n-1;
        len_h = m; 
    
        while(cur_step < step) {
            acc = 0;
            while(acc++ < len_h){ vec.push_back(matrix[i][++j]);  if(++cur_step == step) return vec;}
	    len_h--;
            acc = 0;
            while(acc++ < len_v){ vec.push_back(matrix[++i][j]);  if(++cur_step == step) return vec;}
	    len_v--;
            acc = 0;
            while(acc++ < len_h){ vec.push_back(matrix[i][--j]);  if(++cur_step == step) return vec;}
	    len_h--;
            acc = 0;
            while(acc++ < len_v){ vec.push_back(matrix[--i][j]);  if(++cur_step == step) return vec;}
	    len_v--;
        }
        return vec;
    }
};

int main(){
    vector<vector<int> > matrix;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    matrix.push_back(vec);
    vec[0] = 3;
    vec[1] = 4;
    matrix.push_back(vec);
    Solution sl;
    vec = sl.spiralOrder(matrix);
    int i;
    for ( i = 0; i < vec.size(); i++) cout<<vec[i]<<endl;
    return 0;
}
