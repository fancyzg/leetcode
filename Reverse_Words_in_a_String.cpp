/*************************************

 *File name:Reverse words in a string.cpp
 *Author:Avanty
 *Date:2014-3-16
 *Descriptions:

 Given an input string, reverse the string word by word.
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 Clarification:
 1. What constitutes a word?
 A sequence of non-space characters constitutes a word.
 2. Could the input string contain leading or trailing spaces?
 Yes. However, your reversed string should not contain leading or trailing spaces.
 3. How about multiple spaces between two words?
 Reduce them to a single space in the reversed string.

**************************************/

#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
    public:
	    void reverseWords(string &s) {
		string tmp;
		int i=0;
		int j=0;
		stack<string> stk_str;
		for(;i != s.size();i++)
		{
		    if(s[i] ==' ') 
		    {
			if(i != j)
			{
			    tmp = s.substr(j,i-j);
			    stk_str.push(tmp);
			    j=i+1;
			}
			else
			{
			    j = i+1;
			}
		    }
		}
		if(i != j)
		{
		    tmp = s.substr(j,i-j);
		    stk_str.push(tmp);
		}

		s = "";
		while(!stk_str.empty())
		{
		    s=s+stk_str.top();
		    stk_str.pop();
			s=s+" ";
		} 
		s = s.erase(s.size()-1,1);
		        
		    }
};

int main()
{
    Solution rev;
    string pre_str = "  fan zhi  guo  ";
    rev.reverseWords(pre_str);
    std::cout<<pre_str<<endl;
    return 0;
}
