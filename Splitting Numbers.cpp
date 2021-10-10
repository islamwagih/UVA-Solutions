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


int main(){

    fastInputOutput();
    int n;
    while(cin>>n, n){
        bitset<32> a, b;
        bool turn = 1;
        int ith = 0;
        while(n){
            if(n & 1){
                if(turn) a.set(ith);
                else b.set(ith);
                turn ^= 1;
            }
            ith++;
            n>>=1;
        }
        cout<<a.to_ulong()<<' '<<b.to_ulong()<<endl;
    }

    return 0;

}
