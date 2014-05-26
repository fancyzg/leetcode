//File Name  : Pascal's Triangle.cpp
//Author     : Avanty
//Date       : 2014/5/16  7:23PM
//Decription :
//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]
//
//Have you been asked this question in an interview?
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
	int i,j;
	vector<vector<int> > ptria;
	vector<int> vec;
	for(i = 1; i < numRows+1; i++){
	    for(j = 0; j < i; j++){
		if(j == 0) vec.push_back(1);
		else if(j == i-1) vec.push_back(1);
		else vec.push_back(ptria[i-2][j-1]+ptria[i-2][j]);
	    }
	vec.clear();
	ptria.push_back(vec);
	}
	return ptria;
    }
};
