#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isScramb(string s1, string s2, unordered_map<string, unordered_map<string, bool> >&state_map) {
        if(state_map.find(s1) != state_map.end() && state_map[s1].find(s2) != state_map[s1].end() ) return state_map[s1][s2];
        if(s1.length() != s2.length()){
            return false;
        }
        if(s1.length() == 1){
            if(s1[0] == s2[0]) return true;
            else return false;
        }
        if(s1.length() == 2){
            if(s1.compare(s2)==0 || s1[0] == s2[1] && s1[1] == s2[0]) return true;
            return false;
        }
        int i = 0;
        bool bl1,bl2,bl;
        unordered_map<string,bool> tmp;
        for(i == 1; i < s1.length(); i++){
            bl1 = isScramb(s1.substr(0,i), s2.substr(0,i),state_map) && isScramb(s1.substr(i),s2.substr(i),state_map);
            bl2 = isScramb(s1.substr(0,i), s2.substr(s2.length()-i),state_map) && isScramb(s1.substr(i),s2.substr(0,s2.length()-i),state_map);
            bl =  bl1 || bl2;
            if(bl == true) {
                if(state_map.find(s1) == state_map.end()) state_map[s1] = tmp;
                state_map[s1][s2]=true;
                return true;
            }
        }
        if(state_map.find(s1) == state_map.end()) state_map[s1] = tmp;
         state_map[s1][s2]=false;
        return false;
    }
    
      bool isScramble(string s1, string s2){
        unordered_map<string, unordered_map<string, bool> >state_map;
        return isScramb(s1,s2,state_map);
    }
};

int main(){
    string s1="abb";
    string s2="bba";
    Solution sl;
    cout<<sl.isScramble(s1,s2)<<endl;
    return 0;
}
