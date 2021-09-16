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
    long long dp[n + 1][target + 1];
    dp[0][0] = 0;
    for(int i{}; i <= n; i++){
        for(int j{}; j <= target; j++){
            if((i == 0 && j == 0) || j == 0){
                dp[i][j] = 0;
            }
            else if(i == 0) dp[i][j] = LLONG_MAX - 1;
            else{
                dp[i][j] = dp[i - 1][j];
                if(coins[i - 1] <= j){
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                }
            }
        }
    }
    return dp[n][target];
}

int main(){
    int coins[] = {4,5,2, 1, 9};
    cout << coinChange(coins, 5, 25) << endl;
    return 0;
}