//File Name  : Clone_Graph.cpp
//Author     : Avanty
//Date       : 2014/5/8  11:19PM
//Decription :

//Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


//OJ's undirected graph serialization:
//Nodes are labeled uniquely.

//We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
//As an example, consider the serialized graph {0,1,2#1,2#2,2}.

//The graph has a total of three nodes, and therefore contains three parts as separated by #.

//First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//Second node is labeled as 1. Connect node 1 to node 2.
//Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
//Visually, the graph looks like the following:
//
//       1
//      / \
//     /   \
//    0 --- 2
//         / \
//         \_/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	int i;
	UndirectedGraphNode *head,*p,*q;
	vector<UndirectedGraphNode *>stk;
	unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mapnode;
	unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>:: iterator iter;
	if(node == NULL) return NULL;
	head = new UndirectedGraphNode(node->label);
	mapnode[node] = head;
	stk.push_back(node);
	while(stk.size() != 0){
	    p = stk.back();
	    q = mapnode[p];
	    stk.pop_back();
	    for(i = 0; i != p->neighbors.size(); i++){
		iter = mapnode.find(p->neighbors[i]);
		if( iter != mapnode.end()) q->neighbors.push_back(iter->second);
		else{
		    q->neighbors.push_back(new UndirectedGraphNode(p->neighbors[i]->label));
		    mapnode[p->neighbors[i]] = q->neighbors.back();
		    stk.push_back(p->neighbors[i]);
		}
	    }
	}
	return head;
    }
};

int main(){

    return 0;
}
