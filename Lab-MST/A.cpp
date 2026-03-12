#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int maxOps){
    int l=1, r= *max_element(nums.begin(), nums.end());
    int ans=0;
    while(l<=r){
        int mid= (l+r)/2;
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+= ((nums[i]-1)/mid);

            if(count <= maxOps){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<< ans;
    }
}

int main(){
    vector<int> nums1={9};   int maxOps1=2;
    vector<int> nums2{2,4,8,2}; int maxOps2=4;
    solve(nums1, maxOps1);
    solve(nums2, maxOps2);
    
}