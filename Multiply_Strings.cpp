//File Name  : Multiply Strings .cpp
//Author     : Avanty
//Date       : 2014/6/6 5:40PM
//Decription :

//Multiply Strings Total Accepted: 8081 Total Submissions: 40429 My Submissions
//Given two numbers represented as strings, return multiplication of the numbers as a string.
//
//Note: The numbers can be arbitrarily large and are non-negative.
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    void plus(string &result, string &num){
        int len1,len2,tmp_plus,tmp;
        len1 = result.size();
        len2 = num.size();
        tmp_plus = 0;
        while(len1 >0 && len2>0){
            len1--;
            len2--;
            tmp = (result[len1] - '0' + num[len2] - '0' + tmp_plus)%10 + '0';
            tmp_plus  = (result[len1] - '0' + num[len2] - '0' + tmp_plus)/10;
	    num[len2] = tmp;
        }
        while(len2 > 0){
            len2--;
            tmp = (num[len2] - '0' + tmp_plus)%10 + '0';
            tmp_plus  = (num[len2] - '0' + tmp_plus)/10;
	    num[len2] = tmp;
        } 
        result.clear();
        if(tmp_plus != 0) result.push_back(tmp_plus + '0');
        result.append(num);
    }
    string multiply(string num1, string num2) {
        string result, mul_temp;
        int step;
        int k;
        result.push_back('0');
	
	if(num2.size() == 1 && num2[0] == '0') return result;
        
	for(int i = 1; i <= num1.size(); i++){
            k = 0;
            if(num1[num1.size()-i] != '0') {
                for(int j = 1; j <= num2.size(); j++){
                    step = (num1[num1.size()-i] - '0') * (num2[num2.size()-j] - '0');
                    mul_temp.push_back((step+k)%10+'0');
                    k = (step + k) /10;
                }
                if(k != 0) mul_temp.push_back(k+'0');
                reverse(mul_temp.begin(),mul_temp.end());
                for(int w = 1; w < i; w++){
                    mul_temp.push_back('0');
                }
                plus(result,mul_temp);
            }
            mul_temp.clear();
        }
        return result;
    }
};
int main(){
    //string a("111111111111111111111111111111");
   // string b("111111111111111");
    string a("140");
    string b("721");
    Solution sl;
    string c = sl.multiply(a,b);
    cout<<c<<endl;
    return 0;
}
