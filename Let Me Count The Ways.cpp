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

const int N = 1e3+5;
const int inf = 1e9+5;
const int M = 2*N;

int coins[5] = {1, 5, 10, 25, 50};
ll dp[5][30000+5];
ll ways(int i, int c){
    if(c == 0) return 1;
    if(i == 5) return 0;
    if(dp[i][c] != -1) return dp[i][c];
    ll op1 = (c >= coins[i]) ? ways(i, c-coins[i]) : 0;
    ll op2 = ways(i+1, c);
    return dp[i][c] = op1+op2;
}

int main(){
    fastInputOutput();
    memset(dp, -1, sizeof dp);
    int n;
    while(cin>>n){
        ll m = ways(0, n);
        if(m > 1) cout<<"There are "<<m<<" ways to produce "<<n<<" cents change."<<endl;
        else cout<<"There is only "<<m<<" way to produce "<<n<<" cents change."<<endl;
    }
    return 0;
}
