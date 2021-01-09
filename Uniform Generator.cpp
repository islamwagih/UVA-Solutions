#include <bits/stdc++.h>
using namespace std;
int seed(int x, int step, int mod){
    if(x == 0){
        return 0;
    }
    return (seed(x-1, step, mod)+step)%mod;
}
int main(){
    int step, mod;
    while(cin>>step>>mod){
        unordered_map<int, int> prevSeeds;
        unordered_set<int> prevInserted;
        int value;
        bool isPrinted = false;
        for(int i=0;i<mod;i++){
            auto result = prevSeeds.find(i-1);
            if(result != prevSeeds.end()){
                int prevValue = result->second;
                value = (prevValue+step)%mod;
                prevSeeds.insert({i, value});
            }else{
                value = seed(i, step, mod);
                prevSeeds.insert({i, value});
            }
            auto setResult = prevInserted.find(value);
            if(setResult != prevInserted.end()){
                cout<<setw(10)<<step<<setw(10)<<mod<<"    "<<"Bad Choice\n\n";
                isPrinted = true;
                break;
            }else{
                prevInserted.insert(value);
            }
        }
        if(!isPrinted){
            cout<<setw(10)<<step<<setw(10)<<mod<<"    "<<"Good Choice\n\n";
        }
    }
    return 0;
}
