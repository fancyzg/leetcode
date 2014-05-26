//File Name  : Buy and Sell Stock II.cpp
//Author     : Avanty
//Date       : 2014/5/16  10:10AM
//Decription :

//Best Time to Buy and Sell Stock II Total Accepted: 13265 Total Submissions: 37124 My Submissions
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//
#include<iostream>
#include<vector>
using namespace std;
//time O(n)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
	int i,pre,max = 0;
	if(prices.size() <= 1) return 0;
	pre = prices[0];
	for(i = 1; i < prices.size(); i++){
	   if(prices[i] > pre) max+=prices[i]-pre;
	   pre = prices[i];
	}
	return max;
    }
};

int main(){
    vector<int> prices;
//    prices.push_back(3);
//    prices.push_back(-1);
//    prices.push_back(9);
//    prices.push_back(5);
//    prices.push_back(7);
    Solution sl;
    cout<<sl.maxProfit(prices)<<endl;
    return 0;

}
