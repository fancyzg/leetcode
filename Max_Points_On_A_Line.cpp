/**
 *File name:Max_Ponits_In_A_Line.cpp
 *Author:Avanty
 *Date:2014-3-18
 *Descriptions:
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 *
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

#include<iostream>
#include<vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


class Solution {
    public:
	    struct ratio_num
	    {
		double ratio;
		int num;
	    };
	    int find_pos(vector<ratio_num> &rlog, double ratio)
	    {
		int i;
		for(i = 0; i != rlog.size(); i++)
		{
		    if( ratio == rlog[i].ratio )
		    {
			return i;
		    }
		}
		return i;
	    }
	    int maxPoints(vector<Point> &points) {
		    int i,j,pos;
		    int samepoints;
		    int straight;
		    vector<ratio_num> rlog;
		    ratio_num temp;
		    double ratio;
		    int max_in;

		    if(points.size() <=1)
		    {
			return points.size();
		    }

		    int max_out=2;
		    for(i = 0; i < points.size(); i++)
		    {
			max_in = 0;
			straight = 0;
			samepoints = 0;
			for(j = i+1; j < points.size(); j++)
			{
			    if( points[i].x != points[j].x)
			    {
				ratio = 1.0 * (points[j].y - points[i].y)/(points[j].x - points[i].x);
				pos = find_pos(rlog,ratio);
				if(pos == rlog.size())
				{
				    temp.ratio = ratio;
				    temp.num = 2;
				    rlog.push_back(temp);
				}
				else
				{
				    rlog[pos].num++;
				}
			    }
			    else if(points[i].y == points[j].y)
			    {
				samepoints++;
			    }
			    else
			    {
				straight++;
			    }
			}
			for(j = 0; j < rlog.size(); j++)
			{
			    if(rlog[j].num > max_in)
			    {
				max_in = rlog[j].num;
			    }
			}
			if(straight + 1 > max_in)
			{
			    max_in = straight+1;
			}
			max_in = max_in + samepoints;
			if(max_in > max_out) max_out = max_in;
			rlog.clear();
		    }
		    return max_out;
		    }
};

int main()
{
    vector<Point> vp;
    Point temp(0,0);
    vp.push_back(temp);
    /*vp.push_back(temp);
    vp.push_back(temp);
    temp.x =1;
    temp.y =1;
    vp.push_back(temp);
    temp.x =2;
    temp.y =2;
    vp.push_back(temp);
    temp.x = 1;
    temp.y = 2;
    vp.push_back(temp);
    temp.x = 0;
    temp.y = 2;
    vp.push_back(temp);
    temp.x = 0;
    temp.y = 3;
    vp.push_back(temp);
    vp.push_back(temp);*/
    
    Solution sl;
    cout<<sl.maxPoints(vp)<<endl;

}

