#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(string a, string b, int n, int m){
    int dp[n + 1][m + 1];
    string result;

    int maxSoFar{};

    for(int i{}; i <= n; i++){
        for(int j{}; j <= m; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else{
                if(a[i - 1] == b[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i][j - 1], dp[i-1][j]);
                }
            }
        }
    }
    int i = n, j = m;
    while(i >0 && j > 0){
        if(a[i - 1] == b[j - 1]){
            result = result + a[i - 1];
            i--;
            j--;
        }
        else {
            if(dp[i - 1][j] > dp[i][j - 1]){
                result += a[i - 1];
                i--;
            }
            else{
                result += b[j - 1];
                j--;
            }
        }
    }
    while(i > 0) {
        result += a[i - 1];
        i--;
    }
    while(j > 0) {
        result += b[j - 1];
        j--;
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
}

int main(){
    string a = "aggtab";
    string b = "gxtxyab";
    solve(a, b, a.length(), b.length());
    return 0;
}