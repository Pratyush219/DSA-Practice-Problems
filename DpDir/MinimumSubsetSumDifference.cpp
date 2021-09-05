#include <iostream>
#include <vector>
using namespace std;

int minimumDifference(int a[], int n){
    long long sum{};
    for(int i{}; i < n; i++){
        sum += static_cast<long long>(a[i]);
    }
    bool dp[n + 1][sum + 1];
    for(int i{}; i <= n; i++){
        for(int j{}; j <= sum; j++){
            if(i == 0 && j == 0) dp[i][j] = true;
            else if(i == 0) dp[i][j] = false;
            else if(j == 0) dp[i][j] = true;
            else{
                dp[i][j] = dp[i - 1][j];
                if(a[i - 1] <= j){
                    dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                }
            }
        }
    }
    for(long long i = sum/2; i >= 0; i--){
        if(dp[n][i]) return sum - 2*i;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i{}; i < n; i++){
        cin >> a[i];
    }
    cout << minimumDifference(a, n) << endl;
    return 0;
}