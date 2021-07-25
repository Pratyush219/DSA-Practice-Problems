#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
typedef unsigned long long ull;

unsigned long long fibUtil(int n, vector<ull>& memo){
    if(n<=2) return 1;
    if(memo[n]>0) return memo[n];
    memo[n] = fibUtil(n-1,memo)+fibUtil(n-2,memo);
    return memo[n];
}

ull fib(int n){
    vector<ull> track(n+1,0);
    return fibUtil(n,track);
}

int main(){
    cout<<fib(8)<<endl;
    cout<<fib(3)<<endl;
    cout<<fib(1)<<endl;
    cout<<fib(7)<<endl;
    cout<<fib(60)<<endl;
    return 0;
}