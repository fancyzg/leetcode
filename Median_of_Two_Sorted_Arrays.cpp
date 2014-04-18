/*
 * File Name : Median_of_Two_Sorted_Arrays.cpp
 * Author    : Avanty
 * Date      : 2014/4/14 8:35 PM
 * Decreption: There are two sorted arrays A and B of size m and n respectively. 
 *             Find the median of the two sorted arrays. 
 *             The overall run time complexity should be O(log (m+n)).
 *             The median means, if m+n = odd, the middle, or the mean of middle two number.
*/ 

#include<iostream>
using namespace std;

class Solution {
    public:
	    double findMedianSortedArrays(int A[], int m, int B[], int n)
	    {
		int a_l,a_h,b_l,b_h;
		int a_m,b_m;
		a_l = 0, b_l = 0;
		a_h = m;
		b_h = n;
		while(a_l + 1 != a_h || b_l + 1 != b_h)
		{
		    if(a_l + 1 < a_h)
		    {
			a_m = (a_l+a_h)/2;
		    }
		    if(b_l + 1 < b_h)
		    {
			b_m = (b_l+b_h)/2;
		    }
		    if(A[a_m] <= B[b_m])
		    {
			a_l = a_m;
			b_h = b_m;
		    }
		    else
		    {
			a_h = a_m;
			b_l = b_m;
		    }
		    cout<<a_l<<" "<<b_l<<endl;
		}
		if((m + n)%2 == 0)
		{
		    cout<< a_l <<" "<<b_l<<" "<<endl;
		    return (A[a_l+1]+B[b_l+1])/2;
		}
		else
		{
		    if(A[a_l+1] < B[b_l+1])
			return A[a_l + 1];
		    else
			return B[b_l + 1];
		}
	    }
};

int main()
{
    Solution sl;
    int a[] = {1,3,5,7,9};
    int b[] = {2,4,6};
    int rl = sl.findMedianSortedArrays(a,5,b,3);
    cout <<rl<<endl;


}
