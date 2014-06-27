#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int i,j,start,end,len;
        len = strlen(s);
        int end_real = 0;
        if(len == 0) return 0;
	//cout<<len<<endl;
        end = len;
        start = 0;
        i = len-1;
        while(i>=0){
            if(end_real == 0 && s[i] != ' '){
                end_real = 1;
                end = i;
		cout<<"i: "<<i<<endl;
            }
            if(end_real == 1 && s[i] == ' ')
            {
                end_real = 2;
                start = i+1;
            }
            i--;
        }
        if(end_real == 0) return 0;
        else return end-start+1;
    }
    
};

int main(){
    Solution sl;
    const char *cptr = "a";
    cout<<sl.lengthOfLastWord(cptr)<<endl;
    return 0;
}
