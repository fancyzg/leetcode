//File Name  : Implement strStr.cpp
//Author     : Avanty
//Date       : 2014/6/24/ 12:25AM
//Decription :
//Letter Combinations of a Phone Number Total Accepted: 11219 Total Submissions: 43385 My Submissions
//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below.
//
//
//
//Input:Digit string "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//Note:
//Although the above answer is in lexicographical order, your answer could be in any order you want.
//

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    void letter(string digits, string w[],string &le, vector<string> &res){
	if(digits != ""){
	    for(int i = 0; i < w[digits[0] - '0'].size(); i++){
		le.push_back(w[digits[0]-'0'][i]);
	    	letter(digits.substr(1), w,le,res);
		le.pop_back();
	    }
	}
	else{
	    res.push_back(le);
	}
    }
    vector<string> letterCombinations(string digits){
	int i,j;
	string w[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	vector<string> res;
	string le;
	if(digits != ""){
	    letter(digits,w,le,res); 
	}
	else res.push_back(le);
	return res;
    }
};

int main(){
    Solution sl;
    vector<string> res;
    res = sl.letterCombinations("3994");
    for(int i = 0; i < res.size(); i++){
	cout<<res[i]<<endl;
    }
    return 0;
}
