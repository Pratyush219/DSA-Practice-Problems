#include <iostream>
#include <vector>
using namespace std;

int wiggleLength(vector<int>& nums, int i, int j, bool findGreater){
    if(j == nums.size()) return 0;
    
    int ans{};
    if(findGreater && nums[j] > nums[i]){
        ans = 1 + wiggleLength(nums, j, j + 1, false);
    }
    else if(!findGreater && nums[j] < nums[i]){
        ans = 1 + wiggleLength(nums, j, j + 1, true);
    }
    else
        ans = wiggleLength(nums, j, j + 1, findGreater);
    return ans;
}

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return 1;
    
    return 1 + max(wiggleLength(nums, 0, 1, true), wiggleLength(nums, 0, 1, false));
}

int main(){
    vector<int> v = {2,4,5,7,5,5,7,1,3};
    cout << wiggleMaxLength(v) << endl;
    return 0;
}