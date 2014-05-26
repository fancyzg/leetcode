//File Name  : Construct Binary Tree from Inorder and Postorder Traversal.cpp 
//Author     : Avanty
//Date       : 2014/5/20  10:12PM
//Description:
//Interleaving String Total Accepted: 8375 Total Submissions: 44903 My Submissions
//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//For example,
//Given:
//s1 = "aabcc",
//s2 = "dbbca",
//
//When s3 = "aadbbcbcac", return true.
//When s3 = "aadbbbaccc", return false.
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
	int i,j,len;
        if(s1.length()+s2.length() != s3.length()) return false;
	vector<vector<bool> > matrix(s1.length()+1,vector<bool>(s2.length()+1,false));
	matrix[0][0] = true;
	for(i = 0; i <= s1.length(); i++){
	    for(j = 0; j <= s2.length(); j++){
		if(matrix[i][j] == true) continue;
		len = i+j;
		if(i > 0 && s1[i-1] == s3[len-1] && matrix[i-1][j] == true || 
			j > 0 && s2[j-1] == s3[len-1] && matrix[i][j-1]) matrix[i][j] = true;
	    }
	}
	return matrix[s1.length()][s2.length()];
    }
};

int main(){
    string s1("aabcc");
    string s2("dbbca");
 //   string s3("aadbbcbcac");
    string s3 = "aadbbbaccc";
    Solution sl;
    cout<<sl.isInterleave(s1,s2,s3)<<endl;
    return 0;
}
