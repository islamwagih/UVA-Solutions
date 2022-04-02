#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (ll)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void FIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e7+8;
const int M = 2*N;
const int mod = 1e9+7;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;

bool isPrime[N];

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(ll i=2;i*i<N;i++){
        if(isPrime[i]){
            for(ll j=i*i;j<N;j+=i){
                isPrime[j] = 0;
            }
        }
    }
}


vector<pair<int, int>> tp;

void getTP(){
    for(int i=3;i<N-2;i+=2){
        if(isPrime[i] && isPrime[i+2]){
            tp.push_back({i, i+2});
        }
    }
}

int main(){
    FIO();
    for(int i=0;i<N;i++) isPrime[i] = 1;
    sieve();
    getTP();
    int n;
    while(cin>>n){
        cout<<'('<<tp[n-1].F<<", "<<tp[n-1].S<<')'<<endl;
    }
    return 0;
}
