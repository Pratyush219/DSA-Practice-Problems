#include <iostream>
#include <vector>
using namespace std;

int countSubstrings(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ans{};
    for(int i{}; i < n; i++){
        dp[i][i] = 1;
        ans++;
        if(i < n - 1) dp[i][i + 1] = (s[i] == s[i + 1]);
        
        ans += dp[i][i] + dp[i][i + 1];
    }
    int k = 2;
    for(int k{2}; k < n; k++){
        for(int i{}; i < n - k; i++){
            int j = i + k;
            dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1] == 1);
            ans += dp[i][j];
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << countSubstrings(s) << endl;
    return 0;
}