//File Name  : Word_Break_II.cpp
//Author     : Avanty
//Date       : 2014/5/8  10:52AM
//Decription :
//Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

//Return all such possible sentences.

//For example, given
//s = "catsanddog",
//dict = ["cat", "cats", "and", "sand", "dog"].

//A solution is ["cats and dog", "cat sand dog"].

#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

void print_path(string s, vector<vector<int> > &word_pre, vector<string> &ret, string path){
    int i,j;
    int len = s.length();
    string tmp;
    if(len == 0) ret.push_back(path);
    else{
	for(i = 0; i < word_pre[len].size(); i++){
	    tmp = path;
	    if(path.empty()) path = s.substr(word_pre[len][i]);
	    else path = s.substr(word_pre[len][i]) + " " + path;
	    print_path(s.substr(0, word_pre[len][i]),word_pre,ret,path); 
	    path = tmp;
	}
    }
}


class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
	int i,j;
	vector<int> tmp;
	string path;
	vector<string> ret;
	vector<vector<int> > word_pre(s.length()+1,tmp);
	word_pre[0].push_back(0);
	for(i = 1; i <= s.size(); i++){
	    for(j = 0; j < i; j++){
		if(!word_pre[j].empty() && dict.find(s.substr(j,i-j )) != dict.end()){
		    word_pre[i].push_back(j);
		}
	    }
	}
	print_path(s,word_pre,ret,path);
	return ret;
    }
};

int main(){
    string s = "leetcode";
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("le");
    dict.insert("et");
    dict.insert("code");
    Solution sl;
    vector<string> pr;
    pr = sl.wordBreak(s,dict);
    int i;
    for(i = 0; i< pr.size(); i++){
	cout<<pr[i]<<endl;
    }
    return 0;
}
