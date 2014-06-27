//File Name  : Trapping Rain Water.cpp 
//Author     : Avanty
//Date       : 2014/6/6  9:05PM
//Decription :
//Trapping Rain Water
//Total Accepted: 9635 Total Submissions: 34451
//
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//For example,
//Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//
//
//The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
#include<iostream>
#include<vector>
using namespace std;
/*
class Solution {
public:
    int trap(int A[], int n) {
        int water,i,j,k;
        vector<int> stk;
        water = i = 0;
        while(i < n){
            if(A[i] > 0){
		stk.push_back(i);
          	k = 0;
		for(j = stk.size()-2; j >=0; j--){
		    if(A[stk[j]] > k){
			 water += (i-stk[j]-1) * (min(A[stk[j]],A[i])-k);
			 k = A[stk[j]];
			 if(k >= A[i]) break;
		    }
		}
	    }
	    i++;
        }
        return water;
    }
};
*/

class Solution {
public:
    int trap(int A[], int n) {
        int water,i,j,k,max;
        vector<int> stk;
        vector<bool> savetime;
        max = water = i = 0;
        
        while(i < n){
            if(A[i] > 0){
                if(A[i]>=max) savetime.push_back(false);
                else savetime.push_back(true);
	        	stk.push_back(i);
          	    k = 0;
	        	for(j = stk.size()-2; j >=0; j--){
		            if(A[stk[j]] > k){
			            water += (i-stk[j]-1) * (min(A[stk[j]],A[i])-k);
			            k = A[stk[j]];
			            if(k >= A[i] || savetime[j]) break;
		            }
		        }
	        }
	        i++;
        }
        return water;
    }
};


int main(){
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sl;
    cout<<sl.trap(A,12)<<endl;
    return 0;
}
