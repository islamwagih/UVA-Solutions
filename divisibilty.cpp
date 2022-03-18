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

const int N = 1e6+9;
const int M = 2*N;
const int mod = 1e9+7;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;

vector<int> arr;
vector<vector<int>> dp;

int n, k;

int safeMod(int a){
    return ((a%k)+k)%k;
}

bool solve(int i, int sum){
    if(i == n){
        return (sum%k) == 0;
    }
    if(dp[i][sum] != -1) return dp[i][sum];
    dp[i][sum] = max(solve(i+1, safeMod(sum+arr[i])), solve(i+1, safeMod(sum-arr[i])));
    return dp[i][sum];
}

int main(){
    FIO();
    int t;cin>>t;
    while(t--){
        cin>>n>>k;
        arr = vector<int>(n);
        dp = vector<vector<int>>(n+9, vector<int>(k+9, -1));
        for(int& i:arr) cin>>i;
        bool ans = solve(1, arr[0]%k);
        if(ans) cout<<"Divisible\n";
        else cout<<"Not divisible\n";
    }
    return 0;
}
