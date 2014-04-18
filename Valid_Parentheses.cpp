/*
 *FileName    : Valid_Parentheses.cpp
 *Author      : Avanty
 *Date	      : 2014/4/17 9:43PM
 *Description : Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
                The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *Method      : use stack
*/

#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    public:
	    bool isValid(string s) {
		vector<char> stk;
		char tmp;
		string::iterator it;
		for( it = s.begin(); it != s.end(); it++){
		    if(*it == '(' || *it == '[' || *it == '{'){
			stk.push_back(*it);
		    }
		    else{
			if(stk.size() == 0) return false;
			tmp = stk[stk.size()-1];
			stk.pop_back();
			if(!((tmp == '(' && *it == ')' ) ||(tmp == '[' && *it == ']')||( tmp == '{' && *it == '}' ))){
			    return false;
			}
		    }
		}
		if( stk.size() == 0 ) return true;
		else return false;
	    }
};

int main()
{
//    string s("{{}}[{}]");
//    string s("{{}[{}]");
    string s("]");
    Solution sl;
    cout<<sl.isValid(s);
    return 0;
}
