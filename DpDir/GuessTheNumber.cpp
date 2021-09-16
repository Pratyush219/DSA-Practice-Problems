#include <iostream>
#include <vector>
using namespace std;

int price(int i, int j){
    if(i >= j) return 0;
    
    int ans{INT_MAX};
    for(int k{i + 1}; k <= j; k++){
        int r1 = price(i, k - 1);
        int r2 = price(k + 1, j);
        int temp = max(r1, r2) + k;
        ans = min(ans, temp);
    }
    return ans;
}

int getMoneyAmount(int n) {
    if(n == 1) return 1;
    return price(1, n);
}

int main(){
    cout << getMoneyAmount(2) << endl;
    return 0;
}