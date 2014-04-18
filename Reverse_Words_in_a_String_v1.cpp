#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:

	void swap(char &a,char &b)
	{
	    char tmp;
	    tmp = a;
	    a = b;
	    b = tmp;
	}
	void reverse(string &s,int i,int j)
	{
	    while(i < j)
	    {
		swap(s[i],s[j]);
		i++;
		j--;
	    }
	} 
	void reverseWords(string &s) 
	{
	    int i,j;
	    j = 0;
	    for(i = 0; i< s.size();i++)
	    {
		if(s[i] == ' ')
		{
		    if(i == j)
		    {
			s.erase(i,1);
			i--;
		    }
		    else
		    {
			reverse(s,j,i-1);
			j = i+1;
		    }
		}
	    }
	    if(i != j)
	    {
		reverse(s,j,i-1);
	    }

	    if(s[s.size()-1] == ' ')
	    {
		s.erase(s.size()-1,1);
	    }
	    reverse(s,0,s.size()-1);
	}
};

int main()
{
    Solution rev;
    string pre_str = "  fan zhi  guo";
    rev.reverseWords(pre_str);
    std::cout<<pre_str<<endl;
    return 0;
}
