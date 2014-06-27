//File Name  : Merge k Sorted Lists.cpp 
//Author     : Avanty
//Date       : 2014/6/10  7:19PM
//Description:
//Merge k Sorted Lists Total Accepted: 11535 Total Submissions: 49998 My Submissions
//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

//Have you been asked this question in an interview? 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
//TLE
class Solution {
public:
    ListNode *find_min(vector<ListNode *> &lists, vector<bool> &vec, int &avil) {
        int pos = -1, min = 1<<29;
        ListNode *p = NULL;
        for(int i = 0; i < lists.size(); i++){
            if(vec[i] == true){
                if(lists[i] == NULL)
                {
                    vec[i] = false;
                    avil--;
                }
                else{
                    if(lists[i]->val < min) min = lists[i]->val;
                    p = lists[i];
                    pos = i;
                }
            }
        }
        if(p != NULL){
            lists[pos] = lists[pos]->next;
        }
        return p;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = NULL;
        int listsize = lists.size();
        vector<bool> vec(listsize,true);
        int avil = listsize;
        if(avil == 1) return lists[0];
        ListNode *p,*q;
        while(avil > 0){
            p = find_min(lists,vec,avil);
            if(p != NULL){
                if(head == NULL){
                   head = p;
                    q = head;
                }
                else{
                    q->next = p;
                    q = q->next;
                }
            }
        }
        return head;
    }
};
*/
