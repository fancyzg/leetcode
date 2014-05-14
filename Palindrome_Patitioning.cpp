//File Name  : Palindrome_Patitioning.cpp
//Author     : Avanty
//Date       : 2014/5/11  1:22PM
//Decription :

//Given a string s, partition s such that every substring of the partition is a palindrome.

//Return all possible palindrome partitioning of s.
//
//For example, given s = "aab",
//Return
//
//  [
//    ["aa","b"],
//    ["a","a","b"]
//  ]
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool ispalindrome(string s){
    int i,len;
    len = s.length();
    for(i = 0; i < len; i++){
	if(s[i] != s[len-i-1]){
	    return false;
	}
    }
    return true;
}

class Solution {
public:
    vector<vector<string>> partition(string s) {
	int i,j,k;
	string pars;
	vector<string> onepar;
	vector<vector<string> > tmp;
	vector<vector<vector<string> > > parres(s.length(),tmp);
	if(s.length() == 0) return tmp;
	for(i = 0; i < s.length(); i++){
	    for(j = i; j >= 0; j--){
		if(ispalindrome(s.substr(j,i-j+1))){
		    if(j == 0){
			tmp.clear();
			tmp.push_back(onepar);
			tmp[0].push_back(s.substr(j,i-j+1));
			parres[i].push_back(tmp[0]);
		    }
		    else{
			tmp.assign(parres[j-1].begin(), parres[j-1].end());
			for(k = 0; k != tmp.size(); k++){
			    tmp[k].push_back(s.substr(j,i-j+1));
			    parres[i].push_back(tmp[k]);
			}
		    }
		}
	    }
	}
	return parres.back();
    }
};

int main(){
    string s("abaa");
    Solution sl;
    vector<vector<string>> res;
    res = sl.partition(s);
    int i,j;
    for(i = 0; i < res.size(); i++){
	for(j = 0; j < res[i].size(); j++){
	    cout<<res[i][j]<<" ";
	}
	cout<<endl;
    }
    return 0;
}
