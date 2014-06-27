//File Name  : Simplify_Path.cpp 
//Author     : Avanty
//Date       : 2014/5/27  5:54PM
//Description:
//Simplify Path Total Accepted: 6852 Total Submissions: 35075 My Submissions
//Given an absolute path for a file (Unix-style), simplify it.
//
//For example,
//path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"
//click to show corner cases.
//
//Corner Cases:
//Did you consider the case where path = "/../"?
//In this case, you should return "/".
//Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//In this case, you should ignore redundant slashes and return "/home/foo".
//
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
       int i,j,k,len;
       string tmp,ret("/");
       j = 1;
       path.push_back('/');
       len = path.length();
       for(i = 1 ; i < len; i++){
	   if( path[i] == '/'){
	       tmp = path.substr(j,i-j+1);
	       if(0 == tmp.compare("/") || 0 == tmp.compare("./")){
	       }
	       else if(0 == tmp.compare("../")){
		   k = ret.length();
		   if(k > 1){
		       for(k = ret.length()-2; k >=0; k--){
			   if(ret[k] == '/') break;
		       }
		       ret.erase(k+1);
		   }
	       }
	       else{
		   ret = ret + tmp;
	       }
	       j = i+1;
	   }
       }
       if(i == j){
	   if( i != 1 && ret.length() != 1)  ret.erase(ret.length()-1);
       }
       return ret;
    }
};

int main(){
    Solution sl;
    // string path("/");
    //string path("/..///");
    //string path("/home/");
    //string path("/a/./b/../../c/");
    string path("/a/./b/../../c");
    cout<<sl.simplifyPath(path)<<endl;
    return 0;
}
