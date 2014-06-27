//File Name  : Insert Interval.cpp 
//Author     : Avanty
//Date       : 2014/5/30  9:48AM
//Description:
//Insert Interval Total Accepted: 8928 Total Submissions: 44613 My Submissions
//Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
//Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
//Example 2:
//Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
//
//This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
//
//Have you been asked this question in an interview? 
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include<iostream>
#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int i,j,k;
        bool start = true;
        int interstart;
        bool start_m = false;
        int interend;
        bool end_m = false;
        if(intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        interstart = intervals.size();
        interend = intervals.size();
        for(i = 0; i < intervals.size(); i++) {
            if(start && intervals[i].start > newInterval.start) {
                start = false;
                start_m = false;
                interstart = i;
            }
            if(start && intervals[i].end >= newInterval.start) {
                start = false;
                start_m = true;
                interstart = i;
            }
            if(start == false && intervals[i].start > newInterval.end){
                end_m = false;
                interend = i;
                break;
            }
            if(start == false && intervals[i].end > newInterval.end) {
                end_m = true;
                interend = i;
                break;
            }
        }
        if(interstart == intervals.size()) {
            intervals.push_back(newInterval);
        }
        else if(!start_m && !end_m) {
            if(interstart != interend) intervals.erase(intervals.begin()+interstart,intervals.begin()+interend);
            intervals.insert(intervals.begin()+interstart,newInterval);
        }
        else if(start_m && !end_m) {
            if(interstart +1 != interend) intervals.erase(intervals.begin()+interstart+1, intervals.begin()+interend);
            intervals[interstart].end = newInterval.end;
        }
        else if(!start_m && end_m) {
            if(interstart != interend) intervals.erase(intervals.begin()+interstart,intervals.begin()+interend);
            intervals[interstart].start = newInterval.start;
        }
        else if(start_m && end_m) {
            newInterval.start = intervals[interstart].start;
            newInterval.end = intervals[interend].end;
            intervals.erase(intervals.begin()+interstart,intervals.begin()+interend+1);
            intervals.insert(intervals.begin()+interstart,newInterval);
        }
        return intervals;
    }
};

int main(){
    vector<Interval> vec;
//    vec.push_back(Interval(1,3));
//    vec.push_back(Interval(6,9));
    
    vec.push_back(Interval(1,2));
    vec.push_back(Interval(3,5));
    vec.push_back(Interval(6,7));
    vec.push_back(Interval(8,10));
    vec.push_back(Interval(12,16));
//    vec.push_back(Interval(5,8));
    int i;
    Solution sl;
    vec = sl.insert(vec,Interval(11,15));
    for(i = 0; i < vec.size(); i++) cout<<vec[i].start<<" "<<vec[i].end<<endl;
    return 0;
}
