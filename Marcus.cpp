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

char matrix[10][10];
bool visited[10][10];
int n, m;
queue<string> path;
void fillAllNotVisited(){
    for(int i=0;i<10;i++)
        for(int k=0;k<10;k++)
            visited[i][k] = 0;
}

bool valid(int i, int j){
    if(i < 0 || j < 0) return false;
    if(i >= n || j >= m) return false;
    return true;
}

bool desiredChar(char a){
    return a == 'I' || a == 'E' || a == 'H' || a == 'O' || a == 'V' || a == 'A' || a == '#';
}

string moveDirection(int i, int j, int newI, int newJ){
    if(i-newI == 1){
        return "forth";
    }else if(newJ-j == 1){
        return "right";
    }else{
        return "left";
    }
}

int di[3] = {-1, 0, 0}, dj[3] = {0, 1, -1};
void dfs(int i, int j){
    visited[i][j] = 1;
    for(int k=0;k<3;k++){
        int newi = i+di[k], newj = j+dj[k];
        if(!valid(newi, newj)) continue;
        if(!desiredChar(matrix[newi][newj])) continue;
        if(!visited[newi][newj]){
            path.push(moveDirection(i, j, newi, newj));
            dfs(newi, newj);
        }
    }
}

int main(){

    fastInputOutput();

    int t;cin>>t;
    while(t--){
        fillAllNotVisited();
        cin>>n>>m;
        int x, y;
        for(int i=0;i<n;i++){
            for(int k=0;k<m;k++){
                cin>>matrix[i][k];
                if(matrix[i][k] == '@'){
                    x = i, y = k;
                }
            }
        }
        dfs(x, y);
        while(!path.empty()){
            cout<<path.front();
            path.pop();
            if(path.size() > 0) cout<<' ';
        }
        cout<<endl;
    }

    return 0;

}
