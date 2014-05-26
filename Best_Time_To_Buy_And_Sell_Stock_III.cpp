//File Name  : Buy and Sell Stock III.cpp
//Author     : Avanty
//Date       : 2014/5/16  10:14AM
//Decription :
//Best Time to Buy and Sell Stock III Total Accepted: 8525 Total Submissions: 38752 My Submissions
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
//Note:
//You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//
#include<iostream>
#include<vector>
using namespace std;
//time O(n)
class Solution {
public:
    int maxone(vector<int> &prices, int &cur1, int &cur2){
	int i,tmp,min,max = 0;
	tmp = 0;
	cur1 = cur2 = 0;
	if(prices.size() <= 1) return 0;
	min = prices[0];
	for(i = 1; i < prices.size(); i++){
	    if(prices[i] - min > max) {
		max = prices[i] - min;
		cur2 = i;
		cur1 = tmp;
		
	    }
	    if(min > prices[i]){
		min = prices[i];
		tmp = i;
	    }
	}
	return max;
    }
    int rmaxone(vector<int> &prices){
	int i,max,min = 0;
	if(prices.size() <= 1) return 0;
	max = prices[0];
	for(i = 1; i < prices.size(); i++){
	    if(prices[i] - max < min) min = prices[i] - max;
	    if(max < prices[i]) max = prices[i];
	}
	return 0-min;
    }
    int maxProfit(vector<int> &prices) {
	int i,j,min,max,cur1,cur2;
	int cmax,cmax1,cmax2,cmax3;
	if(prices.size() <= 1) return 0;
	max = maxone(prices,cur1,cur2);
	vector<int> pr1;
	for(i = 0 ; i < cur1; i++){
	    pr1.push_back(prices[i]);
	}
	vector<int> pr2;
	for(i = cur2+1 ; i < prices.size(); i++){
	    pr2.push_back(prices[i]);
	}
	vector<int> pr3;
	for(i = cur1+1; i < cur2; i++){
	    pr3.push_back(prices[i]);
	}
	cmax1 = maxone(pr1,cur1,cur2);
	cmax2 = maxone(pr2,cur1,cur2);
	cmax3 = rmaxone(pr3);
	cmax = cmax1;
	if(cmax < cmax2) cmax = cmax2;
	if(cmax < cmax3) cmax = cmax3;
	return max + cmax;
    }
};

int main(){
    vector<int> prices;
    prices.push_back(2);
    prices.push_back(1);
    prices.push_back(4);
    prices.push_back(5);
    prices.push_back(2);
    prices.push_back(9);
    prices.push_back(7);
    Solution sl;
    cout<<sl.maxProfit(prices)<<endl;
    return 0;
}
