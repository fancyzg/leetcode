//File Name  :stinct Subsequences.cpp 
//Author     : Avanty
//Date       : 2014/5/18  1:39PM
//Decription :
//Distinct Subsequences Total Accepted: 8519 Total Submissions: 35340 My Submissions
//Given a string S and a string T, count the number of distinct subsequences of T in S.
//
//A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//Here is an example:
//S = "rabbbit", T = "rabbit"
//
//Return 3.
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int numDistinct(string S, string T) {
	int slen,tlen,i,j,acc,tmp;
	slen = S.length();
	tlen = T.length();
	if(slen == 0 || tlen == 0) return 0;
	vector<int> vec(slen,0);
	for(i = 0; i < tlen; i++){
	    acc = 0;
	    tmp = vec[i-1];
	    for( j = i; j < slen ; j++){
		if(T[i] == S[j]){
		    if(i == 0) acc++;
		    else acc = acc + tmp ;
		}
		tmp = vec[j];
		vec[j] = acc;	
	    }
	}
	return acc;
    }
};

int main(){
    string S("rabbbit");
    string T("rabbit");
    Solution sl;
    cout<<sl.numDistinct(S,T)<<endl;
    return 0;
}
