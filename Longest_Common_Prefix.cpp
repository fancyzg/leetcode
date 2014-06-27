//File Name  : Longest Common Prefix.cpp
//Author     : Avanty
//Date       : 2014/6/25/ 3:37PM
//Decription :
//Longest Common Prefix Total Accepted: 12324 Total Submissions: 45650 My Submissions
//Write a function to find the longest common prefix string amongst an array of strings.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
	int i,j,k,len;
	string res;
	len = strs.size();
	if(len == 0 || strs[0] == "") return "";
	j = 0;
	while(true){
	    for(i = 0; i < strs.size(); i++){
		if(j > strs[i].length()-1 || strs[i][j] != strs[0][j]) break;
	    }
	    if(i < strs.size()) break;
	    else{
		res.push_back(strs[0][j]);
	    }
	    j++;
	}	
	return res;
    }
};
