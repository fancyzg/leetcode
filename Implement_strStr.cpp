//File Name  : Implement strStr.cpp
//Author     : Avanty
//Date       : 2014/6/24/ 12:25AM
//Decription :
//Implement strStr() Total Accepted: 12851 Total Submissions: 60035 My Submissions
//Implement strStr().
//
//Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
	int i, j;
	int slen = strlen(haystack);
	int dlen = strlen(needle);
	if(slen < dlen) return NULL;
	for(i = 0; i < slen - dlen + 1; i++){
	    for( j = 0; j < dlen; j++){
		if(haystack[i+j] != needle[j])
		    break;
	    }
	    if(j == dlen) return haystack+i;
	}
	return NULL;
    }
};

int main(){
    Solution sl;
    char haystack[] = "fanzhiguo you will be better!";
    char needle[] = "zhiguo ";
    char *res = sl.strStr(haystack, needle);
    if(res == NULL) cout<<" NULL"<<endl;
    cout<<res<<endl;
    return 0;
}
