#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n, 0);
        vector<pair<int,int>> arr; 

        for (int i=0; i<n; i++) {
            arr.push_back({nums[i],i});
        }

        mergeSort(arr,0,n-1, ans);
        return ans;
    }

private:
    void mergeSort(vector<pair<int, int>>& arr, int left, int right, vector<int>& ans) {
        if (left>=right) return;

        int mid = left+(right-left) / 2;

        mergeSort(arr, left, mid, ans);
        mergeSort(arr, mid + 1, right, ans);
        merge(arr, left, mid, right, ans);
    }

    void merge(vector<pair<int, int>>& arr, int left, int mid, int right,vector<int>& ans) {
        vector<pair<int, int>> temp;
        int i=left;
        int j=mid+1;
        int rightCount=0;

        while (i<=mid && j<=right) {
            if (arr[j].first < arr[i].first) {
                temp.push_back(arr[j]);
                rightCount++;
                j++;
            } else {
                ans[arr[i].second]+=rightCount;
                temp.push_back(arr[i]);
                i++;
            }
        }

        while (i<=mid) {
            ans[arr[i].second]+=rightCount;
            temp.push_back(arr[i]);
            i++;
        }

        while (j<=right) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k=left; k<= right; k++) {
            arr[k] = temp[k-left];
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums={5, 2, 6, 1};
    vector<int> result= sol.countSmaller(nums);

    cout<<"Output: ";
    for (int x : result) {
        cout<<x<< " ";
    }
    cout<<endl;

    return 0;
}