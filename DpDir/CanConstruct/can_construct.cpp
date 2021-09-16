#include <iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

bool canConstructUtil(string target, vector<string>& wordBank,unordered_map<string,bool>& isPossible){
    if(target == "") return true;
    if(isPossible.count(target)>0) return isPossible[target];

    for(size_t i{}; i < wordBank.size(); i++){
        if(target.find(wordBank.at(i)) == 0){
            string nextTarget;
            nextTarget = target.substr(wordBank.at(i).length());
            if(canConstructUtil(nextTarget, wordBank,isPossible)) {
                isPossible[target] = true;
                return true;
            }
        }
    }
    isPossible[target] = false;
    return false;
}
bool canConstruct(string tgt, vector<string>& bank){
    unordered_map<string,bool> isPossible;
    isPossible[""] = true;
    canConstructUtil(tgt,bank,isPossible);
    return isPossible[tgt];
}


int main(){
    vector<string> bank;
    bank = {"a","p","ent","enter","ot","o","t"};
    cout<<canConstruct("enterapotentpot",bank)<<endl;
    return 0;
}