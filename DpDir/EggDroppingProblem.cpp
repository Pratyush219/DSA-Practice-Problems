#include <iostream>
#include <vector>
using namespace std;
#define vvi vector<vector<int>>

int min_attempts(int f, int e){
    if(e == 1 || f <= 1) return f;

    int ans = INT_MAX;
    for(int k{1}; k <= f; k++){
        int temp = 1 + max(
            min_attempts(k-1, e-1),
            min_attempts(f-k, e)
        );
        ans = min(ans, temp);
    }
    return ans;
}

int main(){
    cout << min_attempts(10000, 4) << endl;
    return 0;
}