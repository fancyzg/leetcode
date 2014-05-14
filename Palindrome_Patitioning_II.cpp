//File Name  : Palindrome_Patitioning_II.cpp
//Author     : Avanty
//Date       : 2014/5/11  2:37PM
//Decription :

//Given a string s, partition s such that every substring of the partition is a palindrome.

//Return the minimum cuts needed for a palindrome partitioning of s.

//For example, given s = "aab",
//Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
//TLE
class Solution {
public:
    int minCut(string s) {
	int i,j,k;
	string pars;
	vector<string> onepar;
	vector<vector<string> > tmp;
	vector<vector<vector<string> > > parres(s.length(),tmp);
	if(s.length() == 0) return 0;
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
	int mcut = s.size();
	for(i = 0; i < parres.back().size(); i++){
	     j = parres[parres.size()-1][i].size();
	     if(mcut >j) mcut = j;
	}
	return mcut-1;
    }
};
*/

/* TLE
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
    int minCut(string s) {
	int i,j,k;
	vector<int> mcut;
	int inner_mcut;
	if(s.length() == 0) return 0;
	for(i = 0; i < s.length(); i++){
	    inner_mcut = s.length();
	    for(j = 0; j <= i; j++){
		if(ispalindrome(s.substr(j,i-j+1))){
		    if(j == 0){
			inner_mcut = 0;
			continue;
		    }
		    else{
			if(inner_mcut > mcut[j-1] + 1) inner_mcut = mcut[j-1] + 1;
			}
		}
	    }
		mcut.push_back(inner_mcut);
	}
	return mcut.back();
    }
};
*/
void ispalindrome(string s, bool **matrix){
    int i,j,len;
    len = s.size();
    for(i = 0; i < len; i++){
	for(j = i; j >= 0; j--){
	    if(i == j) matrix[i][j] = true;
	    else if(i == j+1){
		if(s[i] == s[j]) matrix[i][j] = true;
		else matrix[i][j] = false;
	    }
	    else{
		if(s[i] == s[j] && matrix[i-1][j+1]) matrix[i][j] = true;
		else matrix[i][j] = false;
	    }
	}
    }
}

class Solution {
public:
    int minCut(string s) {
	int i,j,k;
	vector<int> mcut;
	int inner_mcut;
	bool **matrix;
	if(s.length() == 0) return 0;
	matrix = new bool *[s.length()];
	for(i = 0; i < s.length(); i++){
	    matrix[i] = new bool [s.length()];
	}
	ispalindrome(s, matrix);
	
	for(i = 0; i < s.length(); i++){
	    inner_mcut = s.length();
	    for(j = 0; j <= i; j++){
		if(matrix[i][j]){
		    if(j == 0){
			inner_mcut = 0;
			continue;
		    }
		    else{
			if(inner_mcut > mcut[j-1] + 1) inner_mcut = mcut[j-1] + 1;
			}
		}
	    }
	    mcut.push_back(inner_mcut);
	}
	for(i = 0; i < s.length(); i++){
	    delete []matrix[i];
	}
	    delete []matrix;
	
	return mcut.back();
    }
};

int main(){
    string s("aba");
    Solution sl;
    int res;
    res = sl.minCut(s);
    cout<<res<<endl;
    return 0;
}
