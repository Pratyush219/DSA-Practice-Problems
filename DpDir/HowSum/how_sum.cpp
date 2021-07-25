#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
typedef unsigned long long ull;

bool howSumUtil(int sum, vector<int>& num, vector<int>& nums, vector<int>& memo){
    if(sum == 0){
        return true;
    }
    if(sum < 0) return false;
    if(memo[sum]!=-1) return memo[sum];
	
    bool result = false;
    for(size_t i{}; i < num.size() && !result; i++){
		memo[sum] = howSumUtil(sum - num[i], num,nums, memo);
        result = memo[sum];
        if(result){
            nums.push_back(num[i]);
            return result;
        }
    }
    return result;
}


void howSum(int sum, vector<int>& num){
    vector<int> sequence;
    vector<int> memo(sum+1,-1);
    if(howSumUtil(sum,num,sequence,memo)){
        for(int& n:sequence){
            cout<<n<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"[]"<<endl;
    }
}

int main(){
    vector<int> v1 = {2,3};
    howSum(7,v1);

    v1 = {5,3,4,7};
    howSum(7,v1);
    
    v1 = {2,4};
    howSum(7,v1);
    
    v1 = {2,3,5};
    howSum(8,v1);
    
    v1 = {7,14};
    howSum(300,v1);
    return 0;
}