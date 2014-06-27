//File Name  : Combination Sum .cpp
//Author     : Avanty
//Date       : 2014/6/23 10:07PM
//Decription :
//Combination Sum Total Accepted: 12591 Total Submissions: 47955 My Submissions
//Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times.
//
//Note:
//All numbers (including target) will be positive integers.
//Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//For example, given candidate set 2,3,6,7 and target 7, 
//A solution set is: 
//[7] 
//[2, 2, 3] 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void com(vector<int> &candidates, int index, int sum, int target, vector<vector<int> >&res, vector<int> &path){
	if(sum > target) return;
	if(sum == target) {
	    res.push_back(path);
	    return;
	}
	for(int i = index; i < candidates.size(); i++){
	    path.push_back(candidates[i]);
	    com(candidates,i,sum+candidates[i],target,res,path);
	    path.pop_back();
	}
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	vector<int> path;
	vector<vector<int> >res;
	sort(candidates.begin(),candidates.end());
	com(candidates, 0, 0, target, res, path);
	return res;
    }
};

int main(){
    vector<int> vec;
    vector<vector<int> > res;
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(7);
    Solution sl;
    res = sl.combinationSum(vec,7);
    for(int i = 0; i < res.size(); i++){
	for(int j = 0; j < res[i].size(); j++){
	    cout<<res[i][j]<<" ";
	}
	cout<<endl;
    }
    

    return 0;
}
