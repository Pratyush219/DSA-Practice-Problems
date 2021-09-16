#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string,int> umap;

bool solve(string a, string b){
    if(umap.find(a + " " + b) != umap.end()) return umap[a + " " + b];
    if(a.compare(b) == 0) return true;
    if(a.length() <= 1) return false;
    int s1Arr[26] = {0};
    int s2Arr[26] = {0};
    for(int i{}; i < a.length(); i++){
        s1Arr[a[i] - 'a']++;
        s2Arr[b[i] - 'a']++;
    }
    for(int i{}; i < 26; i++){
        if(s1Arr[i] != s2Arr[i]) return false;
    }
    
    int n = a.length();
    int i = 1;
    bool flag = false;
    while(i < n && !flag){
        flag = (
            (solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0, n-i)))
            || (solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i, n-i)))
        );
        i++;
    }
    return flag;
}

int main(){
    string a, b;
    cin >> a >> b;
    cout << boolalpha << solve(a, b) << endl;
    return 0;
}