//File Name  : Count and Say.cpp
//Author     : Avanty
//Date       : 2014/6/24 10:21PM
//Decription :
//Count and Say Total Accepted: 10066 Total Submissions: 37831 My Submissions
//The count-and-say sequence is the sequence of integers beginning as follows:
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.

#include<iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
	string res = "1";
	string temp;
	int count = 1;
	int i = 0;
	while(n > 1){
	    temp = res;
	    res.clear();
	    while(i < temp.size()){
	    	while(i+1 < temp.size() && temp[i] == temp[i+1]){
		    i++;
		    count++;
		}
		res.push_back(count+'0');
		res.push_back(temp[i]);
		i++;
		count = 1;
	    }
	    i = 0;
	    n--;
	}
	return res;
    }
};

int main(){
    string res;
    Solution sl;
    res = sl.countAndSay(10);
    cout<<res<<endl;
    return 0;
}
