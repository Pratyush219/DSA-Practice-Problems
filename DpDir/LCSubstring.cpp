#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int lc_substring(string a, string b, int m, int n, int len, vector<vector<int>>& memo){
    if(!m || !n) return len;
    if(memo[m][n] != -1) return memo[m][n];
    if(a[m - 1] == b[n - 1]) return memo[m][n] = lc_substring(a, b, m - 1, n - 1, len + 1, memo);
    else{
        return memo[m][n] = max(
            len,
            max(lc_substring(a, b, m - 1, n, 0, memo),
            lc_substring(a, b, m, n - 1, 0, memo))
        );
    }
}

int main(){
    string a, b;
    cin >> a >> b;
    vector<vector<int>> memo(a.length() + 1, vector<int>(b.length() + 1, -1));
    cout << lc_substring(a, b, a.length(), b.length(), 0, memo) << endl;
    return 0;
}