#include <iostream>
#include <vector>
using namespace std;

int countSubsets(int a[], int n, int tgt){
    int dp[n + 1][tgt + 1];
    for(int i{}; i <= n; i++){
        for(int j{}; j <= tgt; j++){
            if(i == 0 && j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = 0;
            else if(j == 0) dp[i][j] = 1;
            else{
                dp[i][j] = dp[i - 1][j];
                if(a[i - 1] <= j){
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
                }
            }
        }
    }
    return dp[n][tgt];
}

int countSubsetsResursive(int a[], int n, int tgt){
    if(tgt == 0) return 1;
    if(n == 0) return 0;
    if(a[n - 1] <= tgt){
        return countSubsetsResursive(a, n - 1, tgt - a[n - 1]) + 
                    countSubsetsResursive(a, n - 1, tgt);
    }
    return countSubsetsResursive(a, n - 1, tgt);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i{}; i < n; i++){
        cin >> a[i];
    }
    int c;
    cin >> c;
    cout << countSubsetsResursive(a, n, c) << endl;
    return 0;
}