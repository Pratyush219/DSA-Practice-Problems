#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void lc_substring(string a, string b, int n, int m){
    int dp[n+1][m+1];
    int rid = 0, cid = 0, len = 0;
    for(int i{}; i <= n; i++){
        for(int j{}; j <= m; j++){
            if(i == 0 || j == 0 || a[i-1] != b[j-1]) dp[i][j] = 0;
            else{
                dp[i][j] = 1 + dp[i-1][j-1];
                if(dp[i][j] > len && i - dp[i][j] == n - j){
                    len = dp[i][j];
                    rid = i;
                    cid = j;
                }
            }
        }
    }
    string res;
    while(rid > 0 && cid > 0 && dp[rid][cid] != 0){
        res += a[rid-1];
        rid--;
        cid--;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}
int main(){
    string a, b;
    cin >>a;
    b = a;
    reverse(b.begin(), b.end());
    lc_substring(a, b, a.length(), b.length());
    return 0;
}