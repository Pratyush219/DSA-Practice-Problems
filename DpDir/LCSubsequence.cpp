#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int lcs(string a, string b, int n, int m){
    // if(n == 0 || m == 0) return 0;

    // if(a[n - 1] == b[m - 1]){
    //     return 1 + lcs(a, b, n - 1, m - 1);
    // }
    // return max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));

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
        else (dp[i - 1][j] > dp[i][j - 1])?(i--):(j--);
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
    return dp[n][m];
}

int main(){
    string a = "abcdgeh";
    string b = "abedfhr";
    cout << lcs(b, a, b.length(), a.length()) << endl;
    return 0;
}