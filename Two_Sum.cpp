/**
  *FileName:    Two_Sum.cpp
  *Author:      Avanty
  *Date:        2014/4/13 2:21 pm

  *Description: Given an array of integers, 
  *             find two numbers such that they add up to a specific target number.
  *             The function twoSum should return indices of the two numbers such that they add up to the target, 
  *             where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
  *             You may assume that each input would have exactly one solution.
  *
  *Input:       numbers={2, 7, 11, 15}, target=9
  *Output:      index1=1, index2=2
  *
*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

/* O(n^2) algorithm is low efficient */
/*
class Solution {
    public:
	    vector<int> twoSum(vector<int> &numbers, int target) {
		int i,j;
		vector<int> ts;
		for(i = 0; i < numbers.size() - 1;i++)
		    for(j = i+1; j < numbers.size(); j++)
		    {
			if(numbers[i] + numbers[j] == target)
			{
			    ts.push_back(i);
			    ts.push_back(j);
			    return ts;
			}
		    }
		    return ts;    
		    }
};
*/

/* O(n) algorithm */
/*
class Solution {
    public:
	    vector<int> twoSum(vector<int> &numbers, int target) {
		int i,temp,cnt;
		vector<int> ts;
		map<int, int> alnum;
		cnt = numbers.size();

		for(i = 0; i < cnt; i++)
		{
		    temp = target -numbers[i];


		    if( alnum.count(temp))
		    {
			ts.push_back(alnum[temp] + 1);
			ts.push_back(i + 1);
			return ts;
		    }
		    else
		    {
			alnum[numbers[i]] = i;
		    }
		}
		return ts;
	    }
};
*/

/* O(nlogn) algorithm */

struct Node{
    int num;
    int pos;
};

bool cmp(Node a, Node b)
{
    return a.num < b.num;
}

class Solution {
    public:
	    vector<int> twoSum(vector<int> &numbers, int target) {
		int i,j,cnt,rl;
		vector<int> ts;
		cnt = numbers.size();
		vector<Node> N_numbers(cnt);
		for(i = 0; i < cnt ; i++)
		{
		    N_numbers[i].num = numbers[i];
		    N_numbers[i].pos = i;
		}
		sort(N_numbers.begin(),N_numbers.end(),cmp);
		
		i = 0; 
		j = cnt-1;
		while(i < j)
		{
		    rl = N_numbers[i].num + N_numbers[j].num;
		    if(rl == target)
		    {
			if(N_numbers[i].pos < N_numbers[j].pos)
			{
			    ts.push_back(N_numbers[i].pos+1);
			    ts.push_back(N_numbers[j].pos+1);
			}
			else
			{
			    ts.push_back(N_numbers[j].pos+1);
			    ts.push_back(N_numbers[i].pos+1);
			}
			return ts;
		    }
		    if(rl < target)
			i++;
		    else
			j--;
		}
		return ts;
	    }
};


int main()
{
    vector<int> ts,numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(11);
    numbers.push_back(15);
    Solution sl;
    ts = sl.twoSum(numbers,9);
    cout<<ts[0]<<" "<<ts[1]<<endl;
    return 0;
}
