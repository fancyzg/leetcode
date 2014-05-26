//File Name  : Restore IP Addresses.cpp 
//Author     : Avanty
//Date       : 2014/5/21  12:37PM
//Description:
//Restore IP Addresses Total Accepted: 7991 Total Submissions: 39838 My Submissions
//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//For example:
//Given "25525511135",
//
//return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
//
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<string> restoreip(string s, int num){
	int i,j,k,len;
	string s_res,tmp;
	len = s.length();
	vector<string> vec,vec1;
	if(num == 1){
	    if(stoi(s.substr(0,1)) == 0 && len > 1) return vec;
	    if(len>0 && len < 4 && stoi(s) <= 255){
	    	vec.push_back(s);
		return vec;
	    }
	    else return vec;
	}
	if(len > num *3 || len < num) return vec;
	for(i = 0; i < 3; i++){
	    if(len > i+1 && stoi(s.substr(0,i+1)) <= 255 && ( i == 0 || stoi(s.substr(0,i+1))>pow(10,i)-1)){
		vec1 = restoreip(s.substr(i+1),num-1);
		for(j = 0; j < vec1.size(); j++){
		    s_res = s.substr(0,i+1);
		    s_res = s_res+ "." + vec1[j];
		    vec.push_back(s_res);
		}
	    }
	}
	return vec;
    }
    vector<string> restoreIpAddresses(string s) {
	int i,len;
	len = s.length();
	vector<string> vec;
	if(len > 12 || len < 4) return vec;
	return restoreip(s, 4);
    }
};

int main(){
    int i;
    //string s = "25525511135";
    string s = "010010";
    vector<string> vec;
    Solution sl;
    vec = sl.restoreIpAddresses(s);
    for(i = 0; i < vec.size(); i++){
	cout<<vec[i]<<endl;
    }
}
