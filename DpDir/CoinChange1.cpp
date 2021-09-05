#include <iostream>
#include <vector>
using namespace std;

int coinChange(int coins[], int n, int target){
    // if((n == 0 && target == 0) || target == 0){
    //     return 1;
    // }
    // if(n == 0) return 0;
    // if(coins[n - 1] <= target){
    //     return (coinChange(coins, n - 1, target) + coinChange(coins, n, target - coins[n - 1]));
    // }
    // return coinChange(coins, n - 1, target);
    int dp[target + 1];
    dp[0] = 1;
    for(int i = 1; i <= target; i++) dp[i] = 0;
    for(int i{0}; i < n; i++){
        for(int j{1}; j <= target; j++){
            if(coins[i] <= j && dp[j - coins[i]]){
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    return dp[target];
}

int main(){
    int coins[] = {1,2,3};
    cout << coinChange(coins, 3, 5) << endl;
    return 0;
}