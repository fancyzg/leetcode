//File Name  : Combination Sum_II .cpp
//Author     : Avanty
//Date       : 2014/6/23 10:21PM
//Decription :
//Combination Sum II Total Accepted: 9826 Total Submissions: 40582 My Submissions
//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//All numbers (including target) will be positive integers.
//Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
//A solution set is: 
//[1, 7] 
//[1, 2, 5] 
//[2, 6] 
//[1, 1, 6] 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void com(vector<int> &num, int index, int sum, int target,vector<vector<int> > &res, vector<int> &path){
	if(sum > target) return;
	if(sum == target){
	    res.push_back(path);
	    return;
	}
	for(int i = index; i < num.size(); i++){
	    path.push_back(num[i]);
	    com(num, i+1, sum + num[i],target, res, path);
	    path.pop_back();
	    while(i+1 < num.size()-1 && num[i] == num[i+1]) i++;
	}
    }	
	
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
	vector<int> path;
	vector<vector<int> >res;
	sort(num.begin(), num.end());
	com(num, 0, 0, target, res, path);
	return res;
    }
};

int main(){
    vector<int> vec;
    vector<vector<int> > res;
    vec.push_back(10);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(6);
    vec.push_back(1);
    vec.push_back(5);
    Solution sl;
    res = sl.combinationSum2(vec,8);
    for(int i = 0; i < res.size(); i++){
	for(int j = 0; j < res[i].size(); j++){
	    cout<<res[i][j]<<" ";
	}
	cout<<endl;
    }
    return 0;
}
