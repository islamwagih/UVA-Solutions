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

int matrix[50][50];
bool visited[50][50];
int h;

bool valid(int i, int j){
    if(i < 0 || j < 0) return false;
    if(i >= h || j >= h) return false;
    return true;
}

int di[8] = {0, 0, 1, 1, 1, -1, -1, -1}, dj[8] = {1, -1, 0, -1, 1, 0, 1, -1};
void dfs(int i, int j){
    visited[i][j] = 1;
    for(int k=0;k<8;k++){
        int newI = i+di[k], newJ = j+dj[k];
        if(!valid(newI, newJ)) continue;
        if(matrix[newI][newJ] == 0) continue;
        if(!visited[newI][newJ]){
            dfs(newI, newJ);
        }
    }
}

int main(){

    fastInputOutput();
    int t = 1;
    while(cin>>h){
        for(int i=0;i<h;i++){
            for(int k=0;k<h;k++){
                char a;cin>>a;
                matrix[i][k] = a-'0';
            }
        }
        for(int i=0;i<50;i++){
            for(int k=0;k<50;k++){
                visited[i][k] = 0;
            }
        }
        int ans = 0;
        for(int i=0;i<h;i++){
            for(int k=0;k<h;k++){
                if(!visited[i][k] && matrix[i][k] == 1){
                    ans++;
                    dfs(i, k);
                }
            }
        }

        cout<<"Image number "<<t++<<" contains "<<ans<<" war eagles."<<endl;
    }

    return 0;

}
