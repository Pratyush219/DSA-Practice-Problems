#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
typedef unsigned long long ull;

bool bestSumUtil(int sum, vector<int>& num, vector<vector<int>>& memo, vector<int>& nums){
    if(sum == 0){
        return true;
    }
    if(sum < 0) return false;
	if(memo[sum].size()>0){
		if(memo[sum].at(0) != -1){
			nums = memo[sum];
			return true;
		}
		else return false;
	}
    int curmin = INT_MAX;
    bool result = false;
    bool finalResult = false;
    for(size_t i{}; i < num.size(); i++){
		vector<int> aux;
		if(sum- num[i] > 0 && memo[sum - num[i]].size()>0 && memo[sum - num[i]].at(0)!=-1) {
			aux = memo[sum - num[i]];
			result = true;
		}
        else result = bestSumUtil(sum - num[i], num, memo,aux);
        if(result){
            finalResult = true;
            aux.push_back(num[i]);
			if(memo[sum].size() < curmin){
				nums.clear();
				nums = aux;
			}
            
        }
        // cout<<"For loop executed"<<endl;
    }
	if(!finalResult) memo[sum] = vector<int>(1,-1);
	else memo[sum] = nums;
    return finalResult;
}


void bestSum(int sum, vector<int>& num){
    vector<vector<int>> memo(sum+1,vector<int>());
    vector<int> sequence;
    if(bestSumUtil(sum,num,memo,sequence)){
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
    bestSum(7,v1);

    v1 = {5,3,4,7};
    bestSum(7,v1);
    
    v1 = {2,4};
    bestSum(7,v1);
    
    v1 = {2,3,5};
    bestSum(8,v1);
    
    v1 = {7,14};
    bestSum(280,v1);
    return 0;
}