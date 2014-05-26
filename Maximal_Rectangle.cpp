//File Name  : Maximal Rectangle .cpp 
//Author     : Avanty
//Date       : 2014/5/23  11:08AM
//Description:
//Maximal Rectangle Total Accepted: 6353 Total Submissions: 29581 My Submissions
//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
	int len,width;
	int i,j,k,max_local,max,recl;
	max = 0;
	max_local= 0;
	width = matrix.size();
	if(width == 0) return 0;
	len = matrix[0].size();
	if(len == 0) return 0;
	vector<vector<int> >matrix_line(width, vector<int>(len,0));
	for(i = 0; i < width; i++){
	    for(j = 0; j < len; j++){
		if(matrix[i][j] == '1'){
//		    cout<<"i="<<i<<" "<<"j="<<j<<endl;
		    if(j == 0) matrix_line[i][j] = 1;
		    else matrix_line[i][j] = matrix_line[i][j-1] + 1;
//		    cout<<"matrix_line:"<<matrix_line[i][j]<<endl;
		    recl = max_local = matrix_line[i][j];
		    for(k = i-1; k >=0; k--){
			if(matrix_line[k][j] == 0) break;
			if(matrix_line[k][j] < recl) recl = matrix_line[k][j];
			if(recl * (i-k+1) > max_local ) max_local = recl * (i - k +1);
//			cout<<max_local<<endl;
		    }
		}
		if(max_local > max) max = max_local;
	    }
	}
        return max; 
    }
};
 
int main(){
    Solution sl;
    vector<char> vec(4,'0');
    vector<vector<char> > matrix;
    matrix.push_back(vec);
    vec[1] = '1';
    matrix.push_back(vec);
    vec[2] = '1';
    matrix.push_back(vec);
    vec[3] = '1';
    matrix.push_back(vec);
    cout<<sl.maximalRectangle(matrix)<<endl;
    return 0;
}
