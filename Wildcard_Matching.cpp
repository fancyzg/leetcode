//File Name  : Wildcard_Matching.cpp 
//Author     : Avanty
//Date       : 2014/6/6  9:28AM
//Description:
//Wildcard Matching Total Accepted: 7760 Total Submissions: 59084 My Submissions
//Implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch("aa","a") ¡ú false
//isMatch("aa","aa") ¡ú true
//isMatch("aaa","aa") ¡ú false
//isMatch("aa", "*") ¡ú true
//isMatch("aa", "a*") ¡ú true
//isMatch("ab", "?*") ¡ú true
//isMatch("aab", "c*a*b") ¡ú false
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

//class Solution {
//public:
//    bool isMatch(const char *s, const char *p) {
//	bool ret = false;
//	if(*p == '\0' && *s !='\0') return false;
//	while( *p != '\0' && *p != '*'){
//	    if(*s != '\0' && (*s == *p || *p == '?' ) ) {
//		s++;
//		p++;
//	    }
//	    else return false;
//	}
//	if(*p == '\0' && *s !='\0') return false;
//	while(*p == '*') p++;
//	if( *p == '\0') return true;
//	while(*s != '\0'){
//	    if(*s != *p) s++;
//	    else{ 
//		ret = ret || isMatch(s,p);
//		s++;
//	    }
//	}
//	return ret;
//    }
//};

//128ms
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int slen = strlen(s);
        int plen = strlen(p);
       // vector<vector<bool> > matrix(2, vector<bool>(slen+1,false));
        const char* tmp = p;
        int cnt = 0;
        while (*tmp != '\0') if (*(tmp++) != '*') cnt++;
        if (cnt > slen) return false;
        bool matrix[2][500];
        memset(matrix,0,sizeof(matrix));
        matrix[0][0]  = true;
        if(slen == 0 && plen == 0) return true;
        for(int i = 1 ; i <= plen; i++){
            if(p[i-1] == '*') matrix[i%2][0] = matrix[(i-1)%2][0];
            else matrix[i%2][0] = false;
            for(int j = 1; j <= slen; j++){
                if(p[i-1] == '*') matrix[i%2][j] = matrix[i%2][j-1] || matrix[(i-1)%2][j];
                else if(p[i-1] == s[j-1] || p[i-1] == '?') matrix[i%2][j] = matrix[(i-1)%2][j-1];
                else matrix[i%2][j] = false;
            }
        }
        return matrix[plen%2][slen];
    }
};



int main(){
    const char *s = "aa";
    const char *p = "*a";
    Solution sl;
    cout<<sl.isMatch(s,p)<<endl;
    return 0;
}
