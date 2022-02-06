#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 4e5+5;
const int inf = 1e8+5;
const int M = 2*N;
const int mod = 1e9+7;

vector<ll> arr;
vector<vector<ll>> blocks;

ll get(ll l, ll r, ll c){
    ll ans = 0, sqr = blocks.size();
    for(ll i=l;i<=r;){
        if(i%sqr == 0 && i+sqr-1 <= r){
            ans += lower_bound(blocks[i/sqr].begin(), blocks[i/sqr].end(), c) - blocks[i/sqr].begin();
            i+=sqr;
        }else{
            if(arr[i] < c) ans++;
            i++;
        }
    }
    return ans;
}

void update(ll index, ll newVal){
    ll sqr = blocks.size(), blockIdx = index/sqr;
    auto it = lower_bound(blocks[blockIdx].begin(), blocks[blockIdx].end(), arr[index]);
    if(it != blocks[blockIdx].end()){
        *it = newVal;
    }
    arr[index] = newVal;
    sort(blocks[blockIdx].begin(), blocks[blockIdx].end());
}

int main(){
    fastInputOutput();
    ll n, m , u;cin>>n>>m>>u;
    arr = vector<ll>(n);
    ll sqr = (ll)ceil(sqrt(n));
    blocks = vector<vector<ll>>(sqr);
    for(ll i=0;i<n;i++) cin>>arr[i];
    for(ll i=0;i<n;i++) blocks[i/sqr].push_back(arr[i]);
    for(ll i=0;i<sqr;i++) sort(blocks[i].begin(), blocks[i].end());
    while(m--){
        ll l, r, v, p;cin>>l>>r>>v>>p;
        ll k = get(l-1, r-1, v);
        ll newVal = (u*k)/((r-l)+1);
        update(p-1, newVal);
    }
    for(ll i=0;i<n;i++) cout<<arr[i]<<'\n';

    return 0;
}
