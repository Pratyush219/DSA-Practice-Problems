#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int unbounded_knapsack(int w[], int p[], int n, int capacity){
    // if(n == 0 || capacity == 0){
    //     return 0;
    // }
    // if(w[n - 1] <= capacity){
    //     return max(unbounded_knapsack(w, p, n - 1, capacity), p[n - 1] + unbounded_knapsack(w, p, n, capacity - w[n - 1]));
    // }
    // return unbounded_knapsack(w, p, n - 1, capacity);
    int dp[capacity + 1];
    dp[0] = 0;
    for(int i = 0; i <= capacity; i++){
        dp[i] = 0;
        for(int j{}; j < n; j++){
            if(w[j] <= i){
                dp[i] = max(dp[i], p[j] + dp[i - w[j]]);
            }
        }
    }
    return dp[capacity];
}

int main(){
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);
    cout << unbounded_knapsack(wt, val, n, W) << endl;
    return 0;
}