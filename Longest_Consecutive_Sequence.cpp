//File Name  : Longest Consecutive Sequence.cpp
//Author     : Avanty
//Date       : 2014/5/12  4:41PM
//Decription :
//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//For example,
//Given [100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//
//Your algorithm should run in O(n) complexity.
//
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/*
// use unoredered_map
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
	int i,tmp,key_val,longest;
	unordered_map<int,int> hash_num;
	unordered_map<int,int>:: iterator iter;
	if(num.empty()) return 0;
	for(i = 0; i < num.size(); i++){
	    hash_num[num[i]] = i;
	}
	longest = 0;

	while(!hash_num.empty()){
	    iter = hash_num.begin();
	    key_val = iter->first;
	    hash_num.erase(iter);
	    tmp = 1;
	    i = key_val;
	    while(hash_num.find(++i) != hash_num.end() ){
		hash_num.erase(key_val);
		tmp++;
	    }
	    i = key_val;
	    while(hash_num.find(--i) != hash_num.end() ){
		hash_num.erase(key_val);
		tmp++;
	    }
	    if(tmp >longest) longest = tmp;
	}
	return longest;
        
    }
};
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
	int i,tmp,key_val,longest;
	unordered_set<int> hash_num;
	unordered_set<int>:: iterator iter;
	if(num.empty()) return 0;
	for(i = 0; i < num.size(); i++){
	    hash_num.insert(num[i]);
	}
	longest = 0;

	while(!hash_num.empty()){
	    iter = hash_num.begin();
	    key_val = *iter;
	    hash_num.erase(iter);
	    tmp = 1;
	    i = key_val;
	    while(hash_num.find(++i) != hash_num.end() ){
		hash_num.erase(i);
		tmp++;
	    }
	    i = key_val;
	    while(hash_num.find(--i) != hash_num.end() ){
		hash_num.erase(i);
		tmp++;
	    }
	    if(tmp >longest) longest = tmp;
	}
	return longest;
        
    }
};

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(7);
    num.push_back(8);
    num.push_back(9);
    num.push_back(10);
    num.push_back(11);
    num.push_back(12);
    Solution sl;
    cout<<sl.longestConsecutive(num)<<endl;
    return 0;
}
