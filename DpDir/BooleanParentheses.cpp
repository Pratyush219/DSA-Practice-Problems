#include <iostream>
#include <vector>
using namespace std;
#define vvvi vector<vector<vector<int>>>
#define vvi vector<vector<int>>
vvvi memo;
int ways(string s, int i, int j, bool isTrue){
    if(i > j) return 0;

    if(memo[i][j][isTrue] != -1){
        return memo[i][j][isTrue];
    }
    if(i == j){
        if(isTrue) return s[i] == 'T';
        else return s[i] == 'F';
    }

    int ans{};
    for(int k{i+1}; k <= j; k+=2){
        int lt = ways(s, i, k-1, true);
        int lf = ways(s, i, k-1, false);
        int rt = ways(s, k+1, j, true);
        int rf = ways(s, k+1, j, false);

        if(s[k] == '&'){
            ans += (isTrue) ? (lt*rt) : (lt*rf + lf*rt + lf*rf);
        }
        else if(s[k] == '|'){
            ans += (isTrue) ? (lt*rf + lf*rt + lt*rt) : (lf*rf);
        }
        else{
            ans += (isTrue) ? (lt*rf + lf*rt) : (lt*rt + lf*rf);
        }
    }
    return memo[i][j][isTrue] = ans;
}

int main(){
    string input = "T|T&F^T";
    int l = input.length();
    memo.resize(l, vvi(l, vector<int>(2, -1)));

    cout << ways(input, 0, l - 1, true) << endl;
    return 0;
}