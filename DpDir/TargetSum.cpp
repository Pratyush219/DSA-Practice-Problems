#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int targetSum(int a[], int n, int tgt){
    bool used[n];
    memset(used, false, n);
    int sum{};

    for(int i{}; i < n; i++) sum += a[i];

    int dp[n + 1][sum + 1];
    for(int i{}; i <= n; i++){
        for(int j{}; j <= sum; j++){
            if(i == 0 && j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = 0;
            else if(j == 0) dp[i][j] = 1;
            else{
                dp[i][j] = dp[i - 1][j];
                if(a[i - 1] <= j){
                    dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
                }
            }
        }
    }

    int diff = sum + 1;
    int ways{};
    int k = sum/2;
    for(; k >= 0 && diff != tgt; k--){
        if(dp[n][k]) {
            diff = sum - 2*k;
            if(diff == tgt) ways = dp[n][k];
        }
    }
    k++;
    vector<int> vi;
    if(ways){
        int i = n, j = k;
        while(i > 0 && j > 0){
            if(dp[i][j] > dp[i - 1][j]){
                vi.push_back(a[i - 1]);
                j -= a[i - 1];
                used[i - 1] = true;
                i--;
            }
            else{
                i--;
            }
        }

        cout << "Subset 1: ";
        for(i = vi.size() - 1; i >= 0; i--){
            cout << vi[i] << " ";
        } cout << endl;
        cout << "Subset 2: "; 
        for(i = 0; i < n; i++){
            if(!used[i]) cout << -a[i] << " ";
        } cout << endl;
    }
    
    return ways;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i{}; i < n; i++){
        cin >> a[i];
    }
    int t;
    cin >> t;
    int ways = targetSum(a, n, t);
    cout << "Number of ways is " << ways << endl;
    return 0;
}