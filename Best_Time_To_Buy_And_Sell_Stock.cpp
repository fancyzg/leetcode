//File Name  : Binary_Tree_Maxmium_Path_Sum.cpp
//Author     : Avanty
//Date       : 2014/5/16  9:45AM
//Decription :
//Best Time to Buy and Sell Stock Total Accepted: 13458 Total Submissions: 43814 My Submissions
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
#include<iostream>
#include<vector>
using namespace std;

//Time O(n)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
	int i,min_pre,max = 0;
	if(prices.size() <=1) return 0;
	min_pre = prices[0];
	for(i = 1; i < prices.size(); i++){
	    if(prices[i] - min_pre > max) max = prices[i] - min_pre;
	    if(prices[i] < min_pre) min_pre = prices[i];
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
//    prices.push_back(3);
    Solution sl;
    cout<<sl.maxProfit(prices)<<endl;
    return 0;
}
