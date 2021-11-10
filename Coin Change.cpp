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
const int inf = 1e9+5;
const int M = 2*N;

int coins[5] = {1, 5, 10, 25, 50};

int dp[5][7500];
int n;
int solve(int i, int c){
    if(c == 0) return 1;
    if(i == 5) return 0;
    if(dp[i][c] != -1) return dp[i][c];
    int op1 = (c >= coins[i]) ? solve(i, c-coins[i]) : 0;
    int op2 = solve(i+1, c);
    return dp[i][c] = op1+op2;
}

int main(){
    fastInputOutput();
    memset(dp, -1, sizeof dp);
    while(cin>>n){
        cout<<solve(0, n)<<endl;
    }
    return 0;
}
