#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

unordered_set<int> cds;
int main(){
    fastInputOutput();
    int n,m;
    while(cin>>n>>m){
        if(n == 0 && m == 0){
            break;
        }

        int forSell = 0;
        for(int i=0;i<n;i++){
            int value;cin>>value;
            cds.insert(value);
        }

        for(int i=0;i<m;i++){
            int value;cin>>value;
            if(cds.find(value) != cds.end()){
                forSell++;
            }
        }

        cout<<forSell<<endl;
        cds.clear();
    }
    return 0;
}

