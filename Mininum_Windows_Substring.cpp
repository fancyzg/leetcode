//Minimum Window Substring Total Accepted: 7764 Total Submissions: 44127 My Submissions
//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//For example,
//S = "ADOBECODEBANC"
//T = "ABC"
//Minimum window is "BANC".
//
//Note:
//If there is no such window in S that covers all characters in T, return the emtpy string "".
//
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
//
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<cstring>
#include<vector>
#include<list>
using namespace std;
/*
class Solution {
public:
    string minWindow(string S, string T) {
        if(T.size() == 0 || S.size() == 0 || S.length() < T.length()) return "";
        int i,j,k;
        int len,start,end;
        start = 0; 
        end = 0;
        len = S.size();
        unordered_set<char> T_set;
        unordered_map<char,int> T_map;
        vector<int> pos;
        for(i = 0; i < T.length(); i++) T_set.insert(T[i]);
        for(i = 0; i < S.length(); i++){
            if(T_set.find(S[i]) != T_set.end()){
                if(T_map.find(S[i]) == T_map.end()){
                    pos.push_back(i);
                    T_map[S[i]] = pos.size()-1;
                    if(pos.size() == T.size()){
                        if(pos.back()-pos.front() < len){
                            len = pos.back()-pos.front()+1;
                            start = pos.front();
                            end = pos.back();
                        }
                        T_map.erase(S[pos.front()]);
                        pos.erase(pos.begin());
			for(j = 0; j < pos.size(); j++ ){
			   T_map[S[pos[j]]] = T_map[S[pos[j]]]-1;
			}
		    }
                }
                else{
                    for(j = T_map[S[i]]+1; j < pos.size(); j++ ){
                        T_map[S[pos[j]]] = T_map[S[pos[j]]]-1;
                    }
                    pos.erase(pos.begin()+T_map[S[i]]);
                    pos.push_back(i);
                    T_map[S[i]] = pos.size()-1;
                }
            }
            
        }
        if(len == S.size() && end == 0) return ""; 
        return S.substr(start,end-start+1);
    }
};
*/
/*
class Solution {
public:
    string minWindow(string S, string T) {
        if(T.size() == 0 || S.size() == 0 || S.length() < T.length()) return "";
        int i,j,k;
        int len,start,end;
        start = 0; 
        end = 0;
        len = S.size();
	if(S.size() == 1 && S[0] == T[0]) return S;
        unordered_set<char> T_set;
        unordered_map<char,list<int>::iterator> T_map;
        unordered_map<char,int> T_num;
        unordered_map<char,int> T_num_real;
        list<int> pos;
        list<int>::iterator iter;
        for(i = 0; i < T.length(); i++){
	    if(T_set.find(T[i]) == T_set.end()){
	    	T_set.insert(T[i]);
		T_num[T[i]] = 1;
		T_num_real[T[i]] = 0;
		}
	    else T_num[T[i]]++;
	}
        for(i = 0; i < S.length(); i++){
            if(T_set.find(S[i]) != T_set.end()){
                if(T_map.find(S[i]) == T_map.end()){
                    pos.push_back(i);
                    iter = pos.end();
                    iter--;
                    T_map[S[i]] = iter;
		    T_num_real[S[i]]++;
                }
                else{
		    if(T_num_real[S[i]] < T_num[S[i]]){
			T_num_real[S[i]]++;
                    	pos.push_back(i);
                    	iter = pos.end();
                    	iter--;
                    	T_map[S[i]] = iter;
		    }
		    else{
		//	cout<<T_num_real[S[i]]<<" "<<S[i]<<endl;
			pos.erase(T_map[S[i]]);
			pos.push_back(i);
			iter = pos.end();
			iter--;
			T_map[S[i]] = iter;
		    }
                }
                if(pos.size() == T.size()){
                    if(pos.back()-pos.front() < len){
                        len = pos.back()-pos.front()+1;
                        start = pos.front();
                        end = pos.back();
                    }
                    if(T_num_real[S[pos.front()]] == 1) T_map.erase(S[pos.front()]);
		    T_num_real[S[pos.front()]]--;
                    pos.erase(pos.begin());
		   // cout<<"len"<<len<<endl;
		}
            }
        }
        if(len == S.size() && end == 0) return ""; 
        return S.substr(start,end-start+1);
    }
};
*/

/*
class Solution {
public:
    string minWindow(string S, string T) {
	struct ListNode{
	    int val;
	    ListNode *pre;
	    ListNode *next;
	    ListNode(int x) {val = x;}
	};
        if(T.size() == 0 || S.size() == 0 || S.length() < T.length()) return "";
        int i,j,k;
        int len,start,end;
	int listsize = 0;
        start = 0; 
        end = 0;
        len = S.size();
	if(S.size() == 1 && S[0] == T[0]) return S;
        unordered_set<char> T_set;
        unordered_map<char,ListNode *> T_map;
        unordered_map<char,int> T_num;
        unordered_map<char,int> T_num_real;
        ListNode *pos, *head;
	head = pos = NULL;
        list<int>::iterator iter;
        for(i = 0; i < T.length(); i++){
	    if(T_set.find(T[i]) == T_set.end()){
	    	T_set.insert(T[i]);
		T_num[T[i]] = 1;
		T_num_real[T[i]] = 0;
		}
	    else T_num[T[i]]++;
	}
        for(i = 0; i < S.length(); i++){
            if(T_set.find(S[i]) != T_set.end()){
                if(T_map.find(S[i]) == T_map.end()){
		    if(head == NULL){
		//	cout<<"head == null"<<endl;
			head = new ListNode(i);
			pos = head;
		    }
		    else{
		//	cout<<"pos->val"<<pos->val<<endl;
			pos->next = new ListNode(i);
			pos->next->pre = pos;
		        pos = pos->next;
		    }
                    T_map[S[i]] = pos ;
		    T_num_real[S[i]]++;
		    listsize++;
                }
                else{
		    if(T_num_real[S[i]] < T_num[S[i]]){
			T_num_real[S[i]]++;
			pos->next = new ListNode(i);
			pos->next->pre = pos;
		        pos = pos->next;
                    	T_map[S[i]] = pos;
		        listsize++;
		    }
		    else{
		//	cout<<T_num_real[S[i]]<<" "<<S[i]<<endl;
		//	cout<<"listsize-----------"<<listsize<<endl;
			if(listsize == 1) {
			    head = new ListNode(i);
			    head = pos;
			}
			else{
			if(T_map[S[i]] == pos) {
			   pos =  pos->pre;
			}
			else if(T_map[S[i]] == head){
			    head = head->next;
			}
			else
			    T_map[S[i]]->pre->next = T_map[S[i]]->next;
			delete T_map[S[i]];

			pos->next = new ListNode(i);
			pos->next->pre = pos;
		        pos = pos->next;
                    	T_map[S[i]] = pos;
			}
		    }
                }
                if(listsize == T.size()){
                    if(pos->val- head->val < len){
                        len = pos->val - head->val +1;
                        start = head->val;
                        end = pos->val;
                    }
		    T_num_real[S[head->val]]--;
		    head = head->next;
		    listsize--;
		    //cout<<"len"<<len<<endl;
		    //cout<<"listsize"<<listsize<<endl;
		    //cout<<"T.size"<<T.size()<<endl;
		}
            }
        }
        if(len == S.size() && end == 0) return ""; 
        return S.substr(start,end-start+1);
    }
};
*/
/*
class Solution {
public:
    string minWindow(string S, string T) {
	int i,end=0,start=0,num = 0;
	int len = 1<<29;
	int T_char[256],data[256];
	vector<int> vec;
	memset(T_char, 0, sizeof(T_char));
	memset(data, 0, sizeof(data));
	for(i = 0; i < T.size(); i++){
	    T_char[T[i]]++;
	}
	for(i = 0; i < S.size(); i++){
	    if(T_char[S[i]]>0){
		data[S[i]]++;
		vec.push_back(i);
		if(data[S[i]] <= T_char[S[i]]) num++;
	    }
	    while(num == T.size()){
		if(len > i - vec.front() +1){
		    start = vec.front();
		    end = i;
		    len = end - start + 1;
		}
		data[S[vec.front()]]--;
		if(data[S[vec.front()]] < T_char[S[vec.front()]]) num--;
		vec.erase(vec.begin());
	    }
	}
	if(len < 1<<29) return S.substr(start,end-start+1);
	else return "";
    }
};
*/

/*
class Solution {
public:
    string minWindow(string S, string T) {
	int i,end=0,start=0,num = 0;
	int len = 1<<29;
	int T_char[256],data[256];
	list<int> vec;
	memset(T_char, 0, sizeof(T_char));
	memset(data, 0, sizeof(data));
	for(i = 0; i < T.size(); i++){
	    T_char[T[i]]++;
	}
	for(i = 0; i < S.size(); i++){
	    if(T_char[S[i]]>0){
		data[S[i]]++;
		vec.push_back(i);
		if(data[S[i]] <= T_char[S[i]]) num++;
	    }
	    while(num == T.size()){
		if(len > i - vec.front() +1){
		    start = vec.front();
		    end = i;
		    len = end - start + 1;
		}
		data[S[vec.front()]]--;
		if(data[S[vec.front()]] < T_char[S[vec.front()]]) num--;
		vec.erase(vec.begin());
	    }
	}
	if(len < 1<<29) return S.substr(start,end-start+1);
	else return "";
    }
};
*/

class Solution {
public:
    string minWindow(string S, string T) {
	struct ListNode{
	    int val;
	    ListNode *next;
	    ListNode(int x) { val = x;}
	};
	int i,end=0,start=0,num = 0;
	int len = 1<<29;
	int T_char[256],data[256];
	ListNode *head, *p;
	head = new ListNode(-1);
	p = head;
	memset(T_char, 0, sizeof(T_char));
	memset(data, 0, sizeof(data));
	for(i = 0; i < T.size(); i++){
	    T_char[T[i]]++;
	}
	for(i = 0; i < S.size(); i++){
	    if(T_char[S[i]]>0){
		data[S[i]]++;
		p->next = new ListNode(i);
		p = p->next;
		if(data[S[i]] <= T_char[S[i]]) num++;
	    }
	    while(num == T.size()){
		int tmp = head->next->val;
		if(len > i - tmp  +1){
		    start = tmp; 
		    end = i;
		    len = end - start + 1;
		}
		data[S[tmp]]--;
		if(data[S[tmp]] < T_char[S[tmp]]) num--;
		head->next = head->next->next;
	    }
	}
	if(len < 1<<29) return S.substr(start,end-start+1);
	else return "";
    }
};

int main(){
 //  string S("ADOBECODEBANCCDAB");
 // string T("ABCC");
//    string S("A");
  //  string T("A");
    //string S("AA");
    //string T("AA");
    string S("wegdtzwabazduwwdysdetrrctotpcepalxdewzezbfewbabbseinxbqqplitpxtcwwhuyntbtzxwzyaufihclztckdwccpeyonumbpnuonsnnsjscrvpsqsftohvfnvtbphcgxyumqjzltspmphefzjypsvugqqjhzlnylhkdqmolggxvneaopadivzqnpzurmhpxqcaiqruwztroxtcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanllpunlyohwfsssiazeixhebipfcdqdrcqiwftutcrbxjthlulvttcvdtaiwqlnsdvqkrngvghupcbcwnaqiclnvnvtfihylcqwvderjllannflchdklqxidvbjdijrnbpkftbqgpttcagghkqucpcgmfrqqajdbynitrbzgwukyaqhmibpzfxmkoeaqnftnvegohfudbgbbyiqglhhqevcszdkokdbhjjvqqrvrxyvvgldtuljygmsircydhalrlgjeyfvxdstmfyhzjrxsfpcytabdcmwqvhuvmpssingpmnpvgmpletjzunewbamwiirwymqizwxlmojsbaehupiocnmenbcxjwujimthjtvvhenkettylcoppdveeycpuybekulvpgqzmgjrbdrmficwlxarxegrejvrejmvrfuenexojqdqyfmjeoacvjvzsrqycfuvmozzuypfpsvnzjxeazgvibubunzyuvugmvhguyojrlysvxwxxesfioiebidxdzfpumyon");
    string T("ozgzyywxvtublcl");
    Solution sl;
    cout<<sl.minWindow(S,T)<<endl;
    return 0;
}
