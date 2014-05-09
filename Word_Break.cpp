//File Name  : Word_Break.cpp
//Author     : Avanty
//Date       : 2014/5/8  10:44PM
//Decription :
//Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].

//Return true because "leetcode" can be segmented as "leet code".	

#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;
/*
//TLE RECERTIVE
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
	int i = 0;
	int j = 1;
	bool onereal = false;
	if(s.empty()) return true;
	for(i = 0 ; i < s.size(); i++){
	    if(dict.find(s.substr(0,i+1)) != dict.end() ){
		onereal = onereal || wordBreak(s.substr(i+1,s.size()-i-1), dict);
	    }
	}
	return onereal;
    }
};
*/

//DP 
//0<i<j
//isword(s.substr(0,j)) = isword(s.substr(0,i)) && isword(s.substr(i,j));
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
	int i,j;
	vector<bool> isword(s.length()+1,false);
	isword[0] = true;
	for(i = 1; i <= s.length(); i++){
	    for(j = 0; j< i; j++){
		if(isword[j] && dict.find(s.substr(j,i-j)) != dict.end() ){
		    isword[i] = true;
		    break;
		}
	    }
	}
	return isword[s.length()];
    }
};

int main(){
    string s = "leetcode";
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");
    Solution sl;
    cout<<sl.wordBreak(s, dict)<<endl;
    return 0;
}
