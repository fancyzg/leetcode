//File Name  : Pascal's Triangle.cpp
//Author     : Avanty
//Date       : 2014/5/16  7:23PM
//Decription :
//Pascal's Triangle II
//Total Accepted: 9493 Total Submissions: 31679
//
//Given an index k, return the kth row of the Pascal's triangle.
//
//For example, given k = 3,
//Return [1,3,3,1].
//
//Note:
//Could you optimize your algorithm to use only O(k) extra space? 
//
#include<isotream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
	int i,j,tmp1,tmp2;
	vector<int> vec(rowIndex+1,0);
	for(i = 0; i < rowIndex+1; i++){
	    tmp2 = 1;
	    for(j = 0; j < i+1; j++){
		if(j == 0) vec[j] = 1;
		else if(j == i) vec[j] = 1; 
		else {
		    tmp1 = tmp2;
		    tmp2 = vec[j];
		    vec[j] = tmp1+tmp2;
		}
	    }
	}
	return vec;
    }
};
