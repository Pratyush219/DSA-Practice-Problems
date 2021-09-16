#include <iostream>
#include <vector>
using namespace std;

int getLis(vector<int>& nums){
    int n = nums.size();
    vector<int> lis(n, 1);
    for(int i{}; i < n; i++){
        for(int j{}; j < i; j++){
            if(nums[j] < nums[i]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    return lis[n - 1];
}

int main(){
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    cout << getLis(nums) << endl;
    return 0;
}