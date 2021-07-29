#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool subsetSumUtil(int i, int num[], int n, int target,vector<int>& soln,vector<int>& memo){
    if(i > n || target < 0) return false;
    if(target == 0) return true;
    if(memo[target] != -1) return memo[target];


    if(subsetSumUtil(i+1,num,n,target-num[i],soln,memo)){
        soln.push_back(num[i]);
        memo[target] = 1;
        return true;
    }
    else if(subsetSumUtil(i+1,num,n,target,soln,memo)){
        memo[target] = true;
        return true;
    }
    memo[target] = 0;
    return false;

}
void subsetSum(int sum, int num[], int n){
    vector<int> soln;
    soln.clear();
    vector<int> memo(sum+1,-1);
    if(subsetSumUtil(0,num,n,sum,soln,memo)){
        for(int i = soln.size()-1; i >= 0; i--){
            cout<<soln[i]<<" ";
        }
        cout << soln.size()<<endl;
        cout << endl;
    }
    else cout<<"No subset found"<<endl;
    
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i; i < n; i++){
        cin>>a[i];
    }
    int sum;
    cin>>sum;
    vector<int> soln;
    subsetSum(sum,a,n);
    return 0;
}