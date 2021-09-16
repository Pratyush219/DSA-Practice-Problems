#include <iostream>
#include <vector>
using namespace std;

int solve(int arr[], int i, int j, vector<vector<int>>& memo){
    if(i >= j) return memo[i][j] = 0;
    if(memo[i][j] != -1) return memo[i][j];

    int minAns = INT_MAX;
    for(int k = i; k < j; k++){
        int temp = solve(arr, i, k, memo) + solve(arr, k + 1, j, memo) + arr[i - 1] * arr[k] * arr[j];
        minAns = min(minAns, temp);
    }
    return memo[i][j] = minAns;
}
int solve_dp(int arr[], int n){
    int dp[n][n];
    
}

int main(){
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> memo(n, vector<int>(n, -1));
    cout << solve(arr, 1, n - 1, memo) << endl;
    return 0;
}