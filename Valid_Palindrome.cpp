//File Name  : .cpp
//Author     : Avanty
//Date       : 2014/5/12  2:23PM
//Decription :
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.
//
//Note:
//Have you consider that the string might be empty? This is a good question to ask during an interview.

//For the purpose of this problem, we define empty string as valid palindrome.

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
	if(s.empty()) return true;
	int i,j;
	char c1,c2;
	i = 0;
	j = s.length()-1;
	while(i < j){
	    while(!((s[i]>='A'&&s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9'))) {i++; if(i == s.length()) return true;}
	    while(!((s[j]>='A'&&s[j]<='Z')||(s[j]>='a' && s[j]<='z')||(s[j]>='0' && s[j]<='9'))) j--;
	    c1 = s[i];
	    c2 = s[j];
	    if(c1 >=97) c1-=32;
	    if(c2 >=97) c2-=32;
	    if(c1 != c2) return false;
	    i++;
	    j--;
	}
	return true;
    }
};

int main(){
//    string s("A man, a plan, a canal: Panama");
    //string s("race a car");
//    string s(".,");
    string s("1a2");
    Solution sl;
    cout<<sl.isPalindrome(s)<<endl;
    return 0;
}
