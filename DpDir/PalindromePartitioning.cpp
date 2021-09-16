#include <iostream>
#include <vector>
using namespace std;

bool is_palindrome(string& str, int lo, int hi){
    for(int i = lo; i < lo + hi - i; i++){
        if(str[i] != str[lo + hi - i])
            return false;
    }
    return true;
}

int partitions(string& s, int i, int j, vector<vector<int>>& memo){
    if(i >= j){
        return memo[i][j] = 0;
    }
    if(memo[i][j] != -1) return memo[i][j];

    if(is_palindrome(s, i, j)) return memo[i][j] = 0;

    int minAns = INT_MAX;
    for(int k{i}; k < j; k++){
        int temp = 1 + partitions(s, i, k, memo) + partitions(s, k + 1, j, memo);
        minAns = min(minAns, temp);
    }
    return memo[i][j] = minAns;
}

int main(){
    string str = "ababbbabbababa";
    vector<vector<int>> memo(str.length(), vector<int>(str.length(), -1));
    cout << partitions(str, 0, str.length() - 1, memo) << endl;
    return 0;
}