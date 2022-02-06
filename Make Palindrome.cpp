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
const int inf = 1e5+5;
const int M = 2*N;
const int mod = 1e9+7;

int dp[N][N];
string str;
int solve(int i, int j){
    if(j <= i) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(str[i]==str[j]) return dp[i][j] = solve(i+1, j-1);
    int op1 = 1+solve(i+1, j);
    int op2 = 1+solve(i, j-1);
    return dp[i][j] = min(op1, op2);
}

void print(int i, int j){
    if(j < i) return;
    if(j == i){
        cout<<str[i];
        return;
    }
    if(str[i]==str[j]){
        cout<<str[i];
        print(i+1, j-1);
        cout<<str[i];
    }else{
        int opt = solve(i, j);
        int op1 = 1+solve(i+1, j);
        int op2 = 1+solve(i, j-1);
        if(opt == op1){
            cout<<str[i];
            print(i+1, j);
            cout<<str[i];
        }else{
            cout<<str[j];
            print(i, j-1);
            cout<<str[j];
        }
    }
}

int main(){
    fastInputOutput();
    while(cin>>str){
        memset(dp, -1, sizeof dp);
        int opt = solve(0, str.size()-1);
        cout<<opt<<' ';
        print(0, str.size()-1);
        cout<<endl;
    }
    return 0;
}
