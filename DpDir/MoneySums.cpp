#include <iostream>
#include <vector>
using namespace std;

void money_sums(int coins[], int n){
    int sum{};
    for(int i{}; i < n; i++) sum += coins[i];
    bool dp[n + 1][sum + 1];
    vector<int> sums;
    for(int i{};  i<= n; i++){
        for(int j{}; j <= sum; j++){
            if((i == 0 && j == 0) || j == 0) dp[i][j] = true;
            else if(i == 0) dp[i][j] = false;
            else{
                dp[i][j] = dp[i - 1][j];
                if(coins[i - 1] <= j){
                    dp[i][j] |= dp[i - 1][j - coins[i - 1]];
                }
            }
            if(i == n && j >0 && dp[i][j]) sums.push_back(j);
        }
    }
    cout << sums.size() << endl;
    for(int& s: sums){
        cout << s << " ";
    }
    cout << endl;

}

int main(){
    int n;
    cin >> n;
    int coins[n];
    for(int i{}; i < n; i++){
        cin >> coins[i];
    }
    money_sums(coins, n);
    return 0;
}