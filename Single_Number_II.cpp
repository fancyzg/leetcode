/*
 *File name:Single_Number.cpp
 *Author:Avanty
 *Date:2014-3-19
 *Given an array of integers, every element appears three times except for one. Find that single one.
 *
 *Note:
 *Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include<iostream>
using namespace std;

class Solution {
    public:
	    int singleNumber(int A[], int n) {
		int i,x1 = 0, x2 = 0, x3 =0;
		for(i = 0; i < n; i++)
		{
		    x2 |= x1&A[i];
		    x1 ^= A[i];
		    x3 = x1&x2;
		    x2 &= ~x3;
		    x1 &= ~x3;
		}
		return x1;
		    }
};

int main()
{
    int A[10] = { 12,12,132,12,43,132,43,34,132,43};
    Solution sl;
    cout<<sl.singleNumber(A,10)<<endl;
    return 0;
}

