#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5 + 5;

ll fastPow(ll b, ll p, ll m){
    b%=m;
    ll ans = 1;
    while(p){
        if(p&1) ans = (ans*b)%m;
        b = (b*b)%m;
        p>>=1;
    }
    return ans;
}

int main(){
    fastInputOutput();
    int t;
    while(cin>>t, t){
        while(t--){
           ll x, y, mod;
           cin>>x>>y>>mod;
           cout<<fastPow(x, y, mod)<<endl;
        }
    }

    return 0;
}
