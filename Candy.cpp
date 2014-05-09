//File Name  : Candy.cpp
//Author     : Avanty
//Date       : 2014/5/9  4:54PM
//Decription :
//There are N children standing in a line. Each child is assigned a rating value.

//You are giving candies to these children subjected to the following requirements:

//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//What is the minimum candies you must give?

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int candy(vector<int> &ratings) {
	int i,j,k;
	if(ratings.size() == 0) return 0;
	int sum = 1;
	int cnum = 1;
	int old_cnum = 1;
	bool old_add = true;
	j = 0;
	for(i = 1; i < ratings.size(); i++){
	    if(ratings[i] < ratings[i-1]){
		if(cnum == 1){
		    if(old_add || i - j < old_cnum - 1)
			sum = sum + (i - j) + 1;
		    else
			sum = sum + (i - j) + 2;
		}
		else{
		    old_cnum = cnum;
		    cnum = 1;
		    sum = sum + cnum;
		    j = i;
		}
	    }
	    else if(ratings[i] == ratings[i-1]){
		old_add = true;
		cnum = 1;
		sum = sum + cnum;
		j = i;
	    }
	    else{
		old_add = false;
		cnum++;
		sum = sum + cnum;
	    }
	}
	return sum;
    }
};

int main(){
    Solution sl;
    vector<int> ratings;
    ratings.push_back(3);//2
    ratings.push_back(2);//1
    ratings.push_back(2);//2
    ratings.push_back(1);//1
    ratings.push_back(4);//3
    ratings.push_back(2);//2
    ratings.push_back(1);//1
    ratings.push_back(2);//2
    ratings.push_back(3);//3
    ratings.push_back(1);//1
    cout<<sl.candy(ratings)<<endl;
}

