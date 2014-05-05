/*
  *FileName    : Valid_Parentheses.cpp
  *Author      : Avanty
  *Date        : 2014/4/17 9:43PM
  *Description : Given a string containing just the characters '(' and ')', 
                 find the length of the longest valid (well-formed) parentheses substring.
                 For "(()", the longest valid parentheses substring is "()", which has length = 2.
                 Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
	    int longestValidParentheses(string s) {
		vector<int> stk;
		int i;
		int last = -1;
		int tlv  = 0;
		int atlv = 0;
		int lv   = 0;
		if(s.size() == 0) return 0;
		for(i = 0; i < s.size(); i++){
		    if(s[i] == '('){
			stk.push_back(i);
			}
		    else if(!stk.empty()){
			stk.pop_back();
			if(stk.empty()){
			    if(lv < (i - last)) lv = i - last;
			}
			else{
			    if(lv < i - stk[stk.size()-1]) lv = i - stk[stk.size()-1];
			}
		    }
		    else{
			last = i;
		    }
		}
		return lv;
	    }
};

int main(){
    //string s("((())");
    //string s("((())");
    string s("))(())(()");
    Solution sl;
    cout<<sl.longestValidParentheses(s)<<endl;
    return 0;
}
