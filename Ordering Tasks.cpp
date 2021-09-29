#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int mod = 1e9+7;
const int N = 1e2+5;
const int inf = 1e9;

vector<int> graph[N];
bool visited[N];

vector<int> topSort;
void dfs(int node){
    visited[node] = 1;
    for(int child:graph[node]){
        if(!visited[child]) dfs(child);
    }
    topSort.push_back(node);
}

int main(){

    fastInputOutput();
    int n,m;
    while(cin>>n>>m, n){
        topSort.clear();
        for(int node=1;node<=101;node++){
            graph[node].clear();
            visited[node] = 0;
        }
        while(m--){
            int u, v;cin>>u>>v;
            graph[u].push_back(v);
        }
        for(int node=1;node<=n;node++){
            if(!visited[node]) dfs(node);
        }
        reverse(topSort.begin(), topSort.end());
        for(int node:topSort) cout<<node<<' ';
        cout<<endl;
    }
    return 0;
}
