//File Name  : Simplify_Path.cpp 
//Author     : Avanty
//Date       : 2014/5/30  11:21AM
//Description:
//Merge Intervals Total Accepted: 9275 Total Submissions: 46096 My Submissions
//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//Given [1,3],[2,6],[8,10],[15,18],
//return [1,6],[8,10],[15,18].
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
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
/*
TLE
bool intervalcmp(const Interval &a,const  Interval &b) { return a.start < b.start; }

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int i,j,k;
        if(intervals.empty() || intervals.size() == 1) return intervals;
        i = 0;
        sort(intervals.begin(),intervals.end(),intervalcmp);
        while(i < intervals.size()-1) {
            if(intervals[i].end >= intervals[i+1].start){
                j = intervals[i+1].end;
                intervals.erase(intervals.begin()+i+1);
                if(j > intervals[i].end) intervals[i].end = j;
            }
            else i++;
        }
        return intervals;
    }
};

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool intervalcmp(const Interval &a, const Interval &b) { return a.start < b.start; }
class Solution {
public:

    vector<Interval> merge(vector<Interval> &intervals) {
        int i,j,k;
        vector<Interval> ret;
        if(intervals.empty() || intervals.size() == 1) return intervals;
        i = 0;
        sort(intervals.begin(),intervals.end(),intervalcmp);
        ret.push_back(intervals[0]);
        j = 0;
        while(i < intervals.size()-1) {
            if(ret[j].end >= intervals[i+1].start){
                k = intervals[i+1].end;
                //intervals.erase(intervals.begin()+i+1);
                if(k > ret[j].end) ret[j].end = k;
            }
            else{
                ret.push_back(intervals[i+1]);
                j++;
                
            }
            i++;
        }
        return ret;
    }
};

int main(){
    vector<Interval> vec;
    vec.push_back(Interval(1,3));
    vec.push_back(Interval(2,6));
    vec.push_back(Interval(8,10));
    vec.push_back(Interval(15,18));
    Solution sl;
    vec = sl.merge(vec);
    int i;
    for(i = 0; i < vec.size(); i++) cout<<vec[i].start<<" "<<vec[i].end<<endl;
    return 0;
} 
