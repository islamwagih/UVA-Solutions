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

const int N = 1e5+5;
const int inf = 2e9+1;

vector<int> adj[N];
int vis[N], vid;

int dfs(int node){
    vis[node] = vid;
    int ans = 1;
    for(int ch:adj[node]){
        if(vis[ch] != vid) ans+=dfs(ch);
    }
    return ans;
}

map<string, int> mp;

int main(){
    fastInputOutput();
    int c, r;
    while(cin>>c>>r, c){
         vid++;
         mp.clear();
         for(int i=0;i<c;i++){
            string animal;cin>>animal;
            mp[animal] = i;
            adj[i].clear();
         }
         for(int i=0;i<r;i++){
            string a, b;cin>>a>>b;
            adj[mp[a]].push_back(mp[b]);
            adj[mp[b]].push_back(mp[a]);
         }
         int ans = 0;
         for(int i=0;i<c;i++){
            if(vis[i] != vid){
                ans = max(ans, dfs(i));
            }
         }
         cout<<ans<<endl;
    }
    return 0;
}
