#include<iostream>
using namespace std;
class Solution {
public:
    int search(int A[], int n, int target) {
        if(n == 0) return -1;
        int high,low,mid,k;
        high = n-1;
        low = 0;
        
        while(high > low+1){
            mid = (high+low)/2;
            if(A[mid] > A[0]){
               high  = mid;
            }
            else{
                low = mid;
            }
        }
        if(n >1 && A[low] > A[low+1]) low++;
	cout<<low<<endl;
        k = low;
        if(A[0] <= target){
             low = 0;
	     high = (n+k-1)%n;
        }
        else{
            high = n-1;
        }
	cout<<low<<" "<<high<<endl;
        
        while(low <= high){
            mid = (low + high) /2;
            if(A[mid] == target) return mid;
            if(A[mid] > target) high = mid -1;
            else low = mid + 1;
        }
        return -1;
    }
};
int main(){
    int a[] = {1,3,5};
    Solution sl;
    cout<<sl.search(a,3,3)<<endl;
}
