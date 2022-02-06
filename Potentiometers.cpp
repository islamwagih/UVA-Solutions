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

const int N = 1e4+5;
const int inf = 1e8+5;
const int M = 2*N;
const int mod = 1e9+7;

void update(int bitIdx, ll bitOldVal, ll bitNewVal, vector<ll>& bit){
    for(int i=bitIdx;i<bit.size();i+=(i&-i)){
        bit[i] -= bitOldVal;
        bit[i] += bitNewVal;
    }
}

ll getPrefix(int bitIdx, vector<ll>& bit){
    ll sum = 0;
    for(int i=bitIdx;i>=1;i-=(i&-i)){
        sum += bit[i];
    }
    return sum;
}

ll get(int l, int r, vector<ll>& bit){
  return getPrefix(r,bit) - getPrefix(l-1, bit);
}

vector<ll> buildBitTree(vector<ll>& arr){
    int n = arr.size();
    vector<ll> bit(n+1, 0);
    for(int i=0;i<n;i++){
        update(i+1, 0, arr[i], bit);
    }
    return bit;
}

int main(){
    fastInputOutput();
    int n, cases = 0;
    while(cin>>n, n){
        vector<ll> arr(n);
        for(ll& i:arr) cin>>i;
        vector<ll> bit = buildBitTree(arr);
        string stat;cin>>stat;
        char c = stat[0];
        if(cases) cout<<endl;
        cout<<"Case "<<++cases<<":\n";
        while(c != 'E'){
            if(c == 'M'){
                int l, r;cin>>l>>r;
                cout<<get(l, r, bit)<<endl;
            }else{
                ll bitIdx, newVal;cin>>bitIdx>>newVal;
                update(bitIdx, arr[bitIdx-1], newVal, bit);
                arr[bitIdx-1] = newVal;
            }
            cin>>stat;
            c = stat[0];
        }
    }

    return 0;
}
