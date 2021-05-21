#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

ll fastPow(int a, int b, int mod){
    if(b == 0) return 1;
    if(b == 1) return a;
    ll ans = fastPow(a, b/2, mod);
    ans = ((ans%mod) * (ans%mod))%mod;
    if(b%2 == 1) ans = ((ans%mod) * (a%mod))%mod;
    return ans;
}

int main(){
    fastInputOutput();
    int b, p, m;
    while(cin>>b>>p>>m){
        cout<<fastPow(b, p, m)<<endl;
    }
    return 0;
}

