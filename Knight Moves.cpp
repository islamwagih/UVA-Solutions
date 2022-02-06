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

const int N = 2e5+10;
const int inf = 1e9+5;
const int M = 2*N;
const int mod = 1e9+7;

int dx[8] = {-2, -2, +2, +2, +1, -1, +1, -1};
int dy[8] = {-1, +1, +1, -1, -2, -2, +2, +2};

bool valid(int x, int y){
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int bfs(int x1, int y1, int x2, int y2){
    queue<int> xs, ys;
    xs.push(x1), ys.push(y1);
    int steps = 0;
    set<pair<int, int>> vis;
    vis.insert({x1, y1});
    while(xs.size()){
        int sz = xs.size();
        while(sz--){
            int currX = xs.front();xs.pop();
            int currY = ys.front();ys.pop();
            if(currX == x2 && currY == y2) return steps;
            for(int k=0;k<8;k++){
                int newX = currX+dx[k];
                int newY = currY+dy[k];
                if(valid(newX, newY) && vis.find({newX, newY}) == vis.end()){
                    xs.push(newX);
                    ys.push(newY);
                    vis.insert({newX, newY});
                }
            }
        }
        steps++;
    }
    return -1;
}

int main(){

    fastInputOutput();
    char r1, c1, r2, c2;
    while(cin>>r1){
        cin>>c1>>r2>>c2;
        cout<<"To get from "<<r1<<c1<<" to "<<r2<<c2<<" takes "<<bfs(c1-'1', r1-'a', c2-'1', r2-'a')<<" knight moves."<<endl;
    }

    return 0;
}
