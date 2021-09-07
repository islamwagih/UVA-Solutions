#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

char matrix[105][105];
bool visited[105][105];
int n;
void fillAllNotVisited(){
    for(int i=0;i<105;i++)
        for(int k=0;k<105;k++)
            visited[i][k] = 0;
}

bool valid(int i, int j){
    if(i < 0 || j < 0) return false;
    if(i >= n || j >= n) return false;
    return true;
}


int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
void dfs(int i, int j){
    visited[i][j] = 1;
    for(int k=0;k<4;k++){
        int newi = i+di[k], newj = j+dj[k];
        if(!valid(newi, newj)) continue;
        if(!visited[newi][newj] && (matrix[newi][newj] == 'x' || matrix[newi][newj] == '@')){
            dfs(newi, newj);
        }
    }
}

int main(){

    fastInputOutput();

    int t, i = 1;cin>>t;
    while(i <= t){
        fillAllNotVisited();
        cin>>n;
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                cin>>matrix[i][k];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                if((!visited[i][k]) && matrix[i][k] == 'x'){
                    dfs(i, k);
                    ans++;
                }
            }
        }
        cout<<"Case "<<i++<<": "<<ans<<endl;
    }

    return 0;

}
