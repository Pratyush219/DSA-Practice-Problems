#include <iostream>
#include <vector>
using namespace std;

bool isValid(string s){
    int l = s.length();
    int open{};
    int close{};
    for(int i{}; i < l; i++){
        if(s[i] == '(') open++;
        else close++;
        
        if(open - close < 0) return false;
    }
    return (open - close == 0);
}
void generate(string cur, int p, int n, vector<string>& res){
    if(p == 2 * n){
        if(isValid(cur)){
            cout << cur << endl;
            res.push_back(cur);
        }
        return;
    }
    generate(cur + '(', p + 1, n, res);
    generate(cur + ')', p + 1, n, res);
}

int main(){
    int n;
    cin >> n;
    vector<string> res;
    string s;
    generate(s, 0, n, res);
    return 0;
}