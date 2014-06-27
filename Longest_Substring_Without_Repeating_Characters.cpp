//File Name  : Longest Substring Without Repeating Characters .cpp
//Author     : Avanty
//Date       : 2014/6/27/ 9:40AM
//Decription :
//Longest Substring Without Repeating Characters Total Accepted: 15847 Total Submissions: 71693 My Submissions
//Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;
/*
//O(n) space ,O(n) time
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	unordered_set<char> uset;
	vector<char> vec;
	int i,j,max = 0;
	for(i = 0; i < s.size(); i++){
	    if(uset.find(s[i]) == uset.end()){
		vec.push_back(s[i]);
		uset.insert(s[i]);
		if(vec.size() > max) max = vec.size();
	    }
	    else{
		for(j = 0; j < vec.size(); j++){
		    if(vec[j] != s[i]){
			uset.erase(vec[j]);
		    }
		    else break;
		}
		vec.erase(vec.begin(),vec.begin()+j+1);
		vec.push_back(s[i]);
	    }
	}
	return max;
    }
};
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	int start,end,max;
	unordered_set<char> uset;
	start = end = max = 0;
	while(end < s.size()){
	    if(uset.find(s[end]) == uset.end()){
		uset.insert(s[end]);
		if(end - start + 1 > max) max = end-start+1;
	    }
	    else{
		while(s[start] != s[end]) {
		    uset.erase(s[start]);
		    start++;
		}
		start++;
	    }
	    end++;
	}
	return max;
    }
};

int main(){
    Solution sl;
    string s("abcblabcbb");
    cout<<sl.lengthOfLongestSubstring(s)<<endl;
    return 0;
}
