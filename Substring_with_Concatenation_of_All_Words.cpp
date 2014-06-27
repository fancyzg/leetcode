//File Name  : Substring with Concatenation.cpp
//Author     : Avanty
//Date       : 2014/6/24 10:36SAM
//Decription :
//Substring with Concatenation of All Words Total Accepted: 8252 Total Submissions: 46627 My Submissions
//You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
//
//For example, given:
//S: "barfoothefoobarman"
//L: ["foo", "bar"]
//
//You should return the indices: [0,9].
//(order does not matter).

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
	vector<int> res;
	int len = L[0].size();
	int i,j,sum = 0;
	if(len * L.size() > S.size()) return res;
	unordered_map<string,int> umapL;
	unordered_map<string,int> umaps;
	for(i = 0; i < L.size(); i++) umapL[L[i]]++;

	for(i = 0; i <= S.size() - L.size()*len; i++){
	    for(j = i; j < S.size(); j = j + len){
		string tmp = S.substr(j,len);
		if(umapL.find(tmp) != umapL.end() && umaps[tmp] < umapL[tmp]){
		    umaps[tmp]++;
		    sum++;
		}
		else break;
	    }
	    if(sum == L.size()) res.push_back(i);
	    umaps.clear();
	    sum = 0;
	}
	return res;
    }
};
int main(){
    Solution sl;
    vector<int> res;
//    string S("lingmindraboofooowingdingbarrwingmonkeypoundcake");
    string S("aaa");
    vector<string> L;
    L.push_back("a");
    L.push_back("a");
//    L.push_back("fooo");
//    L.push_back("barr");
//    L.push_back("wing");
//    L.push_back("ding");
//    L.push_back("wing");

    res = sl.findSubstring(S,L);
    for(int i = 0; i < res.size(); i++){
	cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
