//File Name  : Word_Ladder.cpp
//Author     : Avanty
//Date       : 2014/5/12  2:23PM
//Decription :
//Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
//
//Only one letter can be changed at a time
//Each intermediate word must exist in the dictionary
//For example,
//
//Given:
//start = "hit"
//end = "cog"
//dict = ["hot","dot","dog","lot","log"]
//
//Return
//  [
//    ["hit","hot","dot","dog","cog"],
//    ["hit","hot","lot","log","cog"]
//  ]
//
//Note:
//All words have the same length.
//All words contain only lowercase alphabetic characters.

#include<iostream>
#include<unordered_set>
#include<string>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void getladders(string end, vector<string> &oneladder, vector<vector<string>> &ladders, unordered_map<string,vector<string>> &backtrace){
	int i;
	if(backtrace.find(end) == backtrace.end()){
	    reverse(oneladder.begin(),oneladder.end());
	    ladders.push_back(oneladder);
	    reverse(oneladder.begin(),oneladder.end());
	    return;
	}
	else{
	    for(i = 0; i < backtrace[end].size(); i++){
		oneladder.push_back(backtrace[end][i]);
		getladders(backtrace[end][i],oneladder,ladders,backtrace);
		oneladder.pop_back();
	    }
	}
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
	int i,j,k;
	bool isfind = false;
	string str;
	char c;
	string origin;
	vector<string> qstr;
	vector<string> vstr;
	unordered_map<string,vector<string>> back_trace;
	unordered_set<string>::iterator iter;
	dict.erase(start);
	dict.erase(end);
	for(iter = dict.begin(); iter != dict.end(); iter++){
	    back_trace[*iter] = vstr; 
	}
	qstr.push_back(start);
	qstr.push_back("#");
	while(!qstr.empty()){
	    str = qstr.front();
	    qstr.erase(qstr.begin());
	    vstr.push_back(str);
	    if(str != "#"){
		for(i = 0; i < str.size(); i++){
		    origin = str;
		    c = str[i];
		    for( j = 'a'; j <= 'z'; j++){
			if(c == j) continue;
			str[i] = j;
			if(str == end) {
			    isfind = true;
			    back_trace[end].push_back(origin);
			    goto ENDWHILE;
			}
			if(dict.find(str) != dict.end()){
			    cout<<str<<endl;
			    back_trace[str].push_back(origin);
 			    if(find(qstr.begin(),qstr.end(),str) == qstr.end())
			       qstr.push_back(str);
			}
		    }
		    str = origin;
		}
	    }
	    else if(!qstr.empty()){
		if(isfind) break;
		qstr.push_back("#");
		for(i = 0; i < qstr.size(); i++){
		    if(dict.find(qstr[i]) != dict.end()) {
			dict.erase(qstr[i]);
			cout<<qstr[i]<<endl;
		    }
		}
	    }
ENDWHILE:;
	}
	vector<string> oneladder;
	vector<vector<string>> ladders_ret;
	if(isfind == false) return ladders_ret;
	oneladder.push_back(end);
	getladders(end,oneladder,ladders_ret,back_trace);
	return ladders_ret;
    }
};

int main(){
    int i,j;
    Solution sl;
    string start,end;
    unordered_set<string> dict;
    start = "hot";
    end = "dog";
    dict.insert("hot");
//    dict.insert("dot");
    dict.insert("dog");
//    dict.insert("lot");
//    dict.insert("log");
    vector<vector<string>> ret = sl.findLadders(start,end,dict);
    for(i = 0; i < ret.size(); i++){
	for(j = 0; j < ret[i].size(); j++){
	    cout<<ret[i][j]<<" ";
	}
	cout<<endl;
    }
    return 0;
}
