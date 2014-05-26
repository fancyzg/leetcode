//File Name  : Triangle.cpp
//Author     : Avanty
//Date       : 2014/5/16  2:35:PM
//Decription :
//Triangle
//Total Accepted: 10182 Total Submissions: 38094
//
//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//
//[
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
//
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 
//
//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
	int i,j;
	int left,mid,right;
	vector<int> vec(triangle.size(),0);
	for( i = 0; i < triangle.size(); i++){
	    vec[i] = triangle[triangle.size()-1][i];
	}
	for(i = triangle.size()-2; i >= 0; i--){
	    for(j = 0; j < triangle[i].size();j++){
		left = vec[j];
		right = vec[j+1];
		vec[j]=triangle[i][j]+min(left,right);
	    }
	}
	return vec[0];
    }
};

//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
int main(){
    vector<vector<int> > triangle;
    vector<int> arr; 
/*    arr.push_back(2);
    triangle.push_back(arr);
    arr.clear();
    arr.push_back(3);
    arr.push_back(4);
    triangle.push_back(arr);
    arr.clear();
    arr.push_back(6);
    arr.push_back(5);
    arr.push_back(7);
    triangle.push_back(arr);
    arr.clear();
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(8);
    arr.push_back(3);
    triangle.push_back(arr);
    */
    arr.push_back(1);
    triangle.push_back(arr);
    arr.clear();
    arr.push_back(-2);
    arr.push_back(-5);
    triangle.push_back(arr);
    arr.clear();
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(9);
    triangle.push_back(arr);
    arr.clear();
    arr.push_back(-1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(-3);
    triangle.push_back(arr);
    Solution sl;
    cout<<sl.minimumTotal(triangle)<<endl;
    return 0;
}
