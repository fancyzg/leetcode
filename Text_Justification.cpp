#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int i,j,k,w,blank_num,blank_num_plus,len = words.size();
        string tmp;
        vector<string> ret;
        j = -1;
        k = 0;
        for(i = 0; i < len; i++){
            if(j + 1 + words[i].length() <= L && i != len-1) j = j + words[i].length() + 1;
            else{
		//cout<<"word["<<i<<"]"<<words[i]<<i<<endl;
		//cout<<"k"<<k<<endl;
                if(j+1+words[i].length() > L){
                    j = j - (i-k-1);
		 //   cout<<"j"<<j<<endl;
                    if(i == k+1){
                        tmp = words[k] + string(L-j,' ');
			ret.push_back(tmp);
                    }
                    else{
                        blank_num = (L-j)/(i-k-1);
                        blank_num_plus = (L-j)%(i-k-1);
                        tmp = tmp + words[k];
                        for(w = 1; w < i-k; w++){
                            if(w <= blank_num_plus) tmp = tmp + string(blank_num+1,' ')+words[k+w];
                            else tmp = tmp + string(blank_num,' ')+words[k+w];
			  //  cout<<tmp<<endl;
                        }
			ret.push_back(tmp);
                    }
		    if(i == len-1){
			tmp.clear();
			tmp = tmp+words[i]+string(L-words[i].length(),' ');
			ret.push_back(tmp);
		    }
                }
                else{
                    tmp = words[k];
                    for(w = 1; w < i-k+1; w++){
                        tmp = tmp + " " + words[k+w];
                    }
                    tmp = tmp + string(L-tmp.length(),' ');
		    ret.push_back(tmp);
                }
                k = i;
                j = words[i].length();
                tmp.clear();
            }
        }
	return ret;
        
    }
};
int main(){
    vector<string> ret,words;
    words.push_back("This");
    words.push_back("is");
    words.push_back("an");
    words.push_back("example");
    words.push_back("ofssssssssss");
    words.push_back("texsssst");
    words.push_back("justification");
    Solution sl;
    ret = sl.fullJustify(words,18);
    for(int i = 0; i < ret.size(); i++)
	cout<<ret[i]<<endl;
    return 0;
}
