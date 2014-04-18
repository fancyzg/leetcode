/*
 *File name:Single_Number.cpp
 *Author:Avanty
 *Date:2014-3-19

 *Descriptions:
 *Given an array of integers, every element appears twice except for one. Find that single one.
 *
 *Note:
 *Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
**/

#include<iostream>
using namespace std;
class Solution {
    public:
	    int singleNumber(int A[], int n) {
		int i,snum;
		snum = A[0];
		for(i = 1; i < n; i++)
		{
		    snum = snum ^ A[i];
		}
		return snum;
		        
		    }
};

int main()
{
    int a[5] = { 2,12,29,12,2};
    Solution sl;
    cout<<sl.singleNumber(a,5)<<endl;
    return 0;
}
