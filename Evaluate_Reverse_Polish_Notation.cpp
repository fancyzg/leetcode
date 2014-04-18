#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cstdlib>
using namespace std;
class Solution {
    public:

	    void int_to_str(int num, string &s)
	    {
		stringstream ss;
		ss<<num;
		ss>>s;
	    }
	    void str_to_int(string &s, int &n)
	    {
		n = atoi(s.c_str());
	    }
	    int evalRPN(vector<string> &tokens) {
		vector<string> stk;
		vector<string>::iterator iter;
		string a,b;
		int n1,n2;
		for(iter = tokens.begin(); iter!= tokens.end(); iter++)
		{
		    if((*iter).compare("+")&&(*iter).compare("-")&&(*iter).compare("*")&&(*iter).compare("/"))
		    {
			stk.push_back(*iter);
		    }
		    else
		    {
			b = *(stk.end()-1);
			stk.pop_back();
			a = *(stk.end()-1);
			stk.pop_back();
			str_to_int(b, n2);
			str_to_int(a, n1);
			if(!(*iter).compare("+"))
			{
			    n1  = n1+n2;
			    int_to_str(n1,a);
			    stk.push_back(a);
			}
			if(!(*iter).compare("-"))
			{
			    n1  = n1-n2;
			    int_to_str(n1,a);
			    stk.push_back(a);
			}
			if(!(*iter).compare("*"))
			{
			    n1  = n1*n2;
			    int_to_str(n1,a);
			    stk.push_back(a);
			}
			if(!(*iter).compare("/"))
			{
			    n1  = n1/n2;
			    int_to_str(n1,a);
			    stk.push_back(a);
			}

		    }
		}
	            a = *(stk.end()-1);
	            str_to_int(a, n1);
		    return n1;
		        
		    }
};

int main()
{
    Solution rev;
    vector<string> vec;
    vec.push_back("2");
    vec.push_back("1");
    vec.push_back("+");
    vec.push_back("3");
    vec.push_back("*");
//*/    
//    vec.push_back("4");
/*    vec.push_back("13");
    vec.push_back("5");
    vec.push_back("/");
    vec.push_back("+");
    */
    cout<<rev.evalRPN(vec)<<endl;
    return 0;
}
