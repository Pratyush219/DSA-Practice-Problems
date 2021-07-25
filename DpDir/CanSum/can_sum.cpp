#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
typedef unsigned long long ull;

bool canSumUtil(int sum, vector<int>& num, vector<int>& memo){
    if(sum == 0){
        return true;
    }
    if(sum < 0) return false;
    if(memo[sum]!=-1) return memo[sum];
	
    bool result = false;
    for(size_t i{}; i < num.size() && !result; i++){
		memo[sum] = canSumUtil(sum - num[i], num, memo);
        result = memo[sum];
    }
    return result;
}


bool canSum(int sum, vector<int>& num){
    vector<int> memo(sum+1,-1);
    return canSumUtil(sum,num,memo);
}

int main(){
    vector<int> v1 = {2,3};
    cout<<boolalpha<<canSum(7,v1)<<endl;

    v1 = {5,3,4,7};
    cout<<canSum(7,v1)<<endl;
    
    v1 = {2,4};
    cout<<canSum(7,v1)<<endl;
    
    v1 = {2,3,5};
    cout<<canSum(8,v1)<<endl;
    
    v1 = {7,14};
    cout<<canSum(300,v1)<<endl;
    return 0;
}