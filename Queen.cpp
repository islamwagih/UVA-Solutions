#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

struct Point{
    int x, y;
    bool isZero(){
        return (x == 0) && (y == 0);
    }
    bool samePoint(Point& anotherPoint){
        return (x == anotherPoint.x) && (y  == anotherPoint.y);
    }
    bool sameRow(Point& anotherPoint){
        return x == anotherPoint.x;
    }
    bool sameCol(Point& anotherPoint){
        return y == anotherPoint.y;
    }
    bool sameDiagonal(Point& anotherPoint){
        return abs(x - anotherPoint.x) == abs(y - anotherPoint.y);
    }
};

int main(){
    fastInputOutput();
    Point source, dest;
    while(cin>>source.x>>source.y>>dest.x>>dest.y){
        if(source.isZero() && dest.isZero()){ break; }
        if(source.samePoint(dest)){
            cout<<0<<endl;
        }
        else if(source.sameCol(dest) || source.sameRow(dest) || source.sameDiagonal(dest)){
            cout<<1<<endl;
        }else{
            cout<<2<<endl;
        }
    }
    return 0;
}

