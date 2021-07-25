#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;

ull gridTravellerUtil(int m,int n, vector<vector<ull>>& memo){
    if(m==0 || n==0) return 0;
    if(m==1 || n==1) return 1;
    if(memo[m][n]>0) return memo[m][n];

    memo[m][n] = gridTravellerUtil(m-1,n,memo)+gridTravellerUtil(m,n-1,memo);
    return memo[m][n];
}

ull gridTraveller(int m, int n){
    vector<vector<ull>> memo(m+1,vector<ull>(n+1,0));
    return gridTravellerUtil(m,n,memo);
}

int main(){
    cout<<gridTraveller(2,3)<<endl;
    cout<<gridTraveller(30,0)<<endl;
    cout<<gridTraveller(5,4)<<endl;
    cout<<gridTraveller(13,25)<<endl;
    cout<<gridTraveller(6,12)<<endl;
    return 0;
}