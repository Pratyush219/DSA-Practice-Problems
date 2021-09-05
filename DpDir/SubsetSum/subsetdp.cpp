#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(int nums[], int target, int n){
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));
    for(int i{}; i <= n; i++){
        for(int j{}; j <= target; j++){
            if(i == 0 && j == 0) dp[i][j] = true;
            else if(i == 0) dp[i][j] = false;
            else if(j == 0) dp[i][j] = true;
            else{
                dp[i][j] = dp[i - 1][j];
                if(nums[i - 1] <= j){
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
    }
    return dp[n][target];


    // if(target == 0) return true;
    // if(n == 0) return false;
    // if(nums[n - 1] <= target){
    //     return (subsetSum(nums, target - nums[n - 1], n - 1) || subsetSum(nums, target, n - 1));
    // }
    // return subsetSum(nums, target, n - 1);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i{}; i < n; i++){
        cin >> arr[i];
    }
    int c;
    cin >> c;
    cout << boolalpha << subsetSum(arr, c, n) << endl;
    return 0;
}