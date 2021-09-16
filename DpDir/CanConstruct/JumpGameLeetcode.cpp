/**
 * @link {https://leetcode.com/problems/jump-game-ii/}
*/
#include <iostream>
#include <vector>
using namespace std;

int minJumps(vector<int>& a, int i){
    if(i == a.size() - 1){
        return 0;
    }
    int temp{};
    int ans = INT_MAX - 1;
    for(int j = 1; j <= a[i]; j++){
        if(j >= a.size() - i) break;
        temp = 1 + minJumps(a, i + j);
        ans = min(ans, temp);
    }
    return ans;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << minJumps(nums, 0) << endl;
    return 0;
}