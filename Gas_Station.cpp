//File Name  : Gas_Station.cpp
//Author     : Avanty
//Date       : 2014/5/10  7:42PM
//Decription :
//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

//Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

//Note:
//The solution is guaranteed to be unique.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	vector<int> gasmcost;
	vector<int> gas_need;
	int i,ret;
	int sum = 0;
	for(i = 0; i != gas.size(); i++){
	    gasmcost.push_back(gas[i] - cost[i]);
	    sum += (gas[i] - cost[i]);
	}
	if(sum < 0) return -1;
	sum = 0;
	ret = 0;
	for(i = 0; i != gasmcost.size(); i++){
	    sum += gasmcost[i];
	    if(sum < 0){
		sum = 0;
		ret = i+1;
	    }
	}
	return ret;
    }
};

int main(){
    vector<int> gas,cost;
    gas.push_back(2);
    gas.push_back(3);
    gas.push_back(1);
    //gas.push_back(4); gas.push_back(5);
    cost.push_back(3);
    cost.push_back(1);
    cost.push_back(2);
//    cost.push_back(2);
//    cost.push_back(3);

    Solution sl;
    cout<<sl.canCompleteCircuit(gas,cost)<<endl;

}
