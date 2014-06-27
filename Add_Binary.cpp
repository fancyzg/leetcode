//File Name  :Add_Binary.cpp 
//Author     : Avanty
//Date       : 2014/5/28  9:53AM
//Description:
//Add Binary Total Accepted: 10037 Total Submissions: 39716 My Submissions
//Given two binary strings, return their sum (also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int i = a.size()-1;
        int j = b.size()-1;
        int tmp;
        char bit;
        int k = 0;
        while(i >=0 && j >=0){
            bit = (a[i] - '0' + b[j] - '0' + k)%2 + '0';
            ret.push_back(bit);
            k = (a[i] - '0' + b[j] - '0' + k)/2;
            i--;
            j--;
	    cout<<bit<<endl;
        }
        while(i >= 0){
            bit = (a[i] - '0' + k)%2 +'0';
            ret.push_back(bit);
            k = (a[i] - '0' + k)/2;
            i--;
        }
        while(j >= 0){
            bit = (b[j] - '0' + k)%2 +'0';
            ret.push_back(bit);
            k = (b[j] - '0' + k)/2;
            j--;
	    cout<<bit<<endl;
        }
        if(k == 1) ret.push_back('1');
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main(){
    string a = "1";
    string b = "111";
    Solution sl;
    cout<<sl.addBinary(a,b)<<endl;
    return 0;
}
