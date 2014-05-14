//File Name  : Word_Ladder.cpp
//Author     : Avanty
//Date       : 2014/5/12  11:33PM
//Decription :
//Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

//Only one letter can be changed at a time
//Each intermediate word must exist in the dictionary
//For example,

//Given:
//start = "hit"
//end = "cog"
//dict = ["hot","dot","dog","lot","log"]
//As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//return its length 5.

//Note:
//Return 0 if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.

#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

/*
   MLE
struct Node{
    string s;
    vector<string> vs;
};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
	int i,j,k,len,size;
	vector<Node> vecnode;
	Node nodetmp;
	unordered_set<string>::iterator iter1, iter2;
	unordered_map<string,int> map_string;
	int **matrix;
	len = start.length();
	dict.insert(start);
	dict.insert(end);
	i = 0;
	for(iter1 = dict.begin(); iter1 != dict.end(); iter1++){
	    map_string[*iter1] = i++;
	}
	for(iter1 = dict.begin(); iter1 != dict.end(); iter1++){
	    nodetmp.s = *iter1;
	    for(iter2 = dict.begin(); iter2 != dict.end(); iter2++){
		j = 0;
		for(i = 0; i < len; i++){
		   if((*iter2)[i] != (*iter1)[i]) j++;
		}
		if(j == 1) nodetmp.vs.push_back(*iter2);
	    }
	    vecnode.push_back(nodetmp);
	    nodetmp.vs.clear();
	}
	size = vecnode.size();
	matrix = new int *[size];
	for(i = 0; i < size; i++){
	    matrix[i] = new int [size];
	}
	for(i = 0; i < size; i++){
	    for(j = 0; j < size; j++){
		matrix[i][j] = -1;
	    }
	}
	for(i = 0; i <size; i++){
	    for(j = 0; j < vecnode[i].vs.size(); j++){
		matrix[i][map_string[vecnode[i].vs[j]]] = 1;
	    }
	}

	int istart = map_string[start];
	int iend = map_string[end];
	int v = -1;
	int ret_val;
	bool *final = new bool [size];
	int *D = new int [size];
	int min = -1;
	for(i = 0; i <size; i++){
	    final[i] = false;
	    D[i] = matrix[istart][i];
	}
	final[istart] = true;
	D[istart] = 0;
	for( i = 1; i < size; i++){
	    min = -1;
	    v = -1;
	    for(j = 0; j < size; j++){
		if(!final[j]){
		    if((min == -1 && D[j] != -1) || (D[j] > 0 && D[j] < min)) { v = j; min = D[j];}
		}
	    }
	    if(v == -1) {
		ret_val = 0;
		goto ret;
	    }

	    final[v] = true; 
	    for(j = 0; j < size; j++){
		if(!final[j] && matrix[v][j] != -1 &&((D[j] == -1 )|| ( min + matrix[v][j] < D[j]))){
		    D[j] = min + matrix[v][j];
		}
	    }
	}

	ret_val = D[iend] + 1;
ret:	delete [] final;
	delete [] D;
	for(i = 0; i <size; i++)
	    delete [] matrix[i];
	delete [] matrix;
	return ret_val;
    }
};
*/
/*
//   MLE Memory Limit Exceed
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
	int i,j,k,len,size;
	unordered_set<string>::iterator iter1, iter2;
	unordered_map<string,int> string_int;
	bool **matrix;
	len = start.length();
	dict.insert(start);
	dict.insert(end);
	i = 0;
	size = dict.size();
	matrix = new bool *[size];
	for(i = 0; i < size; i++){
	    matrix[i] = new bool [size];
	}
	for(i = 0; i < size; i++){
	    for(j = 0; j < size; j++){
		matrix[i][j] = 0;
	    }
	}
	
//	i = 0;
//	for(iter1 = dict.begin(); iter1 != dict.end(); iter1++){
//	{
//	    string_int[*iter1] = i++;
//	}
//
	int l1,l2;
	for(iter1 = dict.begin(),l1=0; iter1 != dict.end(); iter1++,l1++){
	    for(iter2 = dict.begin(),l2=0; iter2 != dict.end(); iter2++,l2++){
		j = 0;
		for(i = 0; i < len; i++){
		   if((*iter2)[i] != (*iter1)[i]) j++;
		}
		if(j == 1) matrix[l1][l2] = 1;
	    }
	}

	int istart ;
	int iend ;
	for(iter1 = dict.begin(),l1=0; iter1 != dict.end(); iter1++,l1++){
	    if(*iter1 == start) istart = l1;
	    if(*iter1 == end) iend = l1;
	}
	int v = -1;
	int ret_val;
	bool *final = new bool [size];
	int *D = new int [size];
	int min = -1;
	for(i = 0; i <size; i++){
	    final[i] = false;
	    D[i] = matrix[istart][i];
	}
	final[istart] = true;
	D[istart] = 0;
	for( i = 1; i < size; i++){
	    min = -1;
	    v = -1;
	    for(j = 0; j < size; j++){
		if(!final[j]){
		    if((min == -1 && D[j] != 0) || (D[j] > 0 && D[j] < min)) { v = j; min = D[j];}
		}
	    }
	    if(v == -1) {
		ret_val = 0;
		goto ret;
	    }

	    final[v] = true; 
	    for(j = 0; j < size; j++){
		if(!final[j] && matrix[v][j] != 0 &&((D[j] == 0 )|| ( min + matrix[v][j] < D[j]))){
		    D[j] = min + matrix[v][j];
		}
	    }
	}

	ret_val = D[iend] + 1;
ret:	delete [] final;
	delete [] D;
//	for(i = 0; i <size; i++)
//	    delete [] matrix[i];
//	delete [] matrix;
	return ret_val;
    }
};
*/

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
	string tmp;
	char origin;
	int i,j,depth;
	queue<string> qstr;
	qstr.push(start);
	qstr.push(" ");
	depth = 1;
	while(!qstr.empty()){
	    tmp = qstr.front();
	    qstr.pop();
	    if(tmp != " "){
		for(i = 0; i < tmp.size(); i++){
		    origin = tmp[i];
		    for(j = 'a'; j <= 'z'; j++){
			if(j == origin) continue;
			tmp[i] = j;
			if(tmp == end) return depth+1;
			if(dict.find(tmp) != dict.end()){
			    qstr.push(tmp);
			    cout<<tmp<<endl;
			    dict.erase(tmp);
			}
		    }
		    tmp[i] = origin;
		}
	    }
	    else if(!qstr.empty()){
		qstr.push(" ");
		depth++;
	    }
	}
	return 0;
    }
};

int main(){
    string start,end;
    unordered_set<string> dict;
  start = "hot";
    end = "dog";
    dict.insert("hot");
//    dict.insert("dot");
    dict.insert("dog");
//    dict.insert("lot");
//    dict.insert("log");
    /*
    start = "a";
    end = "c";
    dict.insert("a");
    dict.insert("b");
    dict.insert("c");
    */
    Solution sl;
    cout<<sl.ladderLength(start, end, dict)<<endl;
    return 0;
}

