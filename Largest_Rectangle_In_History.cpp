//File Name  :Largest Rectangle in Histogram.cpp 
//Author     : Avanty
//Date       : 2014/5/23  2:19PM
//Description:
//Largest Rectangle in Histogram Total Accepted: 9050 Total Submissions: 44172 My Submissions
//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
//Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//For example,
//Given height = [2,1,5,6,2,3],
//return 10.
//
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
	int i,j,k;
	int val, max =0;
	vector<int> vec;
	for(i = 0; i < height.size();i++){
	    if(vec.size() == 0 || height[vec.back()] <= height[i]){
		vec.push_back(i);
	    }
	    else{
		j = vec.back();
		while(vec.size() != 0 && height[vec.back()] > height[i]){
		    k = vec.back();
		    vec.pop_back();
		    if(vec.empty()) val = (j+1)*height[k];
		    else  val = (j-vec.back()) * height[k];
		    if(max < val) max = val;
		}
		vec.push_back(i);
	    }
	}
	for(i = 0; i < vec.size(); i++){
	    if(i == 0) val = height[vec[0]] * height.size();
	    else val = height[vec[i]] *(vec.back() - vec[i-1]);
	    if(max < val) max = val;
	}
	return max;
    }
};

int main(){
    vector<int> height;
    height.push_back(2);
    height.push_back(1);
    height.push_back(5);
    height.push_back(6);
    height.push_back(2);
    height.push_back(3);
    Solution sl;
    cout<<sl.largestRectangleArea(height)<<endl;
    return 0;
}
