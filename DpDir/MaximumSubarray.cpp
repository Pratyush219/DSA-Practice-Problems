#include <iostream>
#include <vector>
using namespace std;

int crossSum(vector<int>& nums, int l, int mid, int r){
    int left = INT_MIN;
    int sum{};
    for(int i{mid}; i >= l; i--){
        sum += nums[i];
        left = max(left, sum);
    }

    sum = 0;
    int right = INT_MIN;
    for(int i{mid+1}; i <= r; i++){
        sum += nums[i];
        right = max(right, sum);
    }
    return left + right;
}

int findMaxSum(vector<int>&nums, int l, int r){
    if(l == r){
        return nums[l];
    }
    int mid = (l+r)/2;
    int ls = findMaxSum(nums, l, mid);
    int rs = findMaxSum(nums, mid+1, r);
    int cross = crossSum(nums, l, mid, r);
    
    return max(max(ls, rs), cross);
}

int main(){
    vector<int> nums;
    int n;
    int d;
    cin >> n;
    for(int i{}; i < n; i++){
        cin >> d;
        nums.push_back(d);
    }
    cout << findMaxSum(nums, 0, nums.size() - 1);
    return 0;
}