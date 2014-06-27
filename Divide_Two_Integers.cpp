//File Name  : Divide Two Integers.cpp 
//Author     : Avanty
//Date       : 2014/6/11  9:38PM
//Description:
//Divide Two Integers Total Accepted: 10818 Total Submissions: 68373 My Submissions
//Divide two integers without using multiplication, division and mod operator.

#include<iostream>
#include<algorithm>
#include<limits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned long int i,add,result;
        unsigned tmp;
        bool minus = false;
        if(dividend < 0 && divisor >0 || dividend > 0 && divisor < 0) minus = true;
        unsigned int dividend_x = abs(dividend);
	cout<<dividend_x<<endl;
        unsigned int divisor_y = abs(divisor);
        if(dividend_x == 0 || dividend_x < divisor_y ) return 0;
        result = 0;
        add = 0;
        while(add + divisor_y <= dividend_x){
            tmp = divisor_y;
            i = 1;
	    cout<<dividend_x<<" "<<divisor_y<<endl;
            while(add + (tmp<<1) <=dividend_x && tmp < 1<<31){
                tmp=tmp<<1;
                i=i<<1;
		cout<<i<<" "<<tmp<<endl;
		if(i == 0) break;
            }
            add = add+tmp;
            result +=i;
        }
        if(minus) return -result;
        else return result;
    }
};

int main(){
    Solution sl;
    int w = -2147483648LL;
    cout<<sl.divide(w,1)<<endl;
    return 0;
}
