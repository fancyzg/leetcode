//Search a 2D Matrix Total Accepted: 11446 Total Submissions: 37459 My Submissions
//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//For example,
//
//Consider the following matrix:
//
//[
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//]
//Given target = 3, return true.
#include<iostream>
#include<vector>
using namespace std;
/*
class Solution {
public:
    bool find_in_line(vector<int> &line, int i, int j, int target){
        int l,h,m;
        l = i;
        h = j;
        while(l<=h){
            m = (l+h)/2;
            if(line[m] == target) return true;
            if(line[m] > target) h = m-1;
            if(line[m] < target) l = m+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int width,len,angle;
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        width = matrix.size();
        len = matrix[0].size();
        angle = width;
        if(angle > len) angle = len;
        int i;
        for(i = 0; i < angle; i++){

            if(matrix[i][i] == target) return true;
            if(matrix[i][i] > target){
                 break;
            }
        }
        if(i < angle){
            if(matrix[i][0] <= target) return find_in_line(matrix[i],0,i-1,target);
            else{
                if(i -1 < 0 ) return false;
                return find_in_line(matrix[i-1],i,len-1,target);
            }
        }
        else{
	    if(i == len){
		if(i > width) return false;
		else{
		    for(;i < width;i++){
			if(matrix[i][0] == target) return true;
			if(matrix[i][0] > target) break;
		    }
		    if(i < width) return find_in_line(matrix[i-1],1,len-1,target);
		    else return find_in_line(matrix[i-1],1,len-1,target);
		}
	    }
            return find_in_line(matrix[i-1],i,len-1,target);
        }
    }
};

*/
class Solution {
public:
    bool find_in_line(vector<int> &line, int i, int j, int target){
        int l,h,m;
        l = i;
        h = j;
        while(l<=h){
            m = (l+h)/2;
            if(line[m] == target) return true;
            if(line[m] > target) h = m-1;
            if(line[m] < target) l = m+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int width,len,angle;
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        width = matrix.size();
        len = matrix[0].size();
        int i;
	for(i=0;i < width;i++){
	    if(matrix[i][0] == target) return true;
	    if(matrix[i][0] > target) break;
	}
	if(i < width) return find_in_line(matrix[i-1],1,len-1,target);
	else return find_in_line(matrix[i-1],1,len-1,target);
    }
};
int main(){
    vector<vector<int> > matrix;
    vector<int> vec;
/*    vec.push_back(-8);
    vec.push_back(-7);
    vec.push_back(-6);
    vec.push_back(-5);
    vec.push_back(-3);
    vec.push_back(-3);
    matrix.push_back(vec);
    vec[0] = -1;vec[1] = -1;vec[2] = -1;vec[3] = -1;vec[4] = 0;vec[5] = 0;
    matrix.push_back(vec);
    vec[0] = 1;vec[1] = 3;vec[2] = 3;vec[3] = 3;vec[4] = 5;vec[5] = 7;
    matrix.push_back(vec);
    */
    vec.push_back(1);
    matrix.push_back(vec);
    vec[0] = 3;
    matrix.push_back(vec);
    Solution sl;
    cout<<sl.searchMatrix(matrix,3)<<endl;
    return 0;
}
