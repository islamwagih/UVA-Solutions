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

bool prime(int x){
    if(x == 2) return true;
    if(x < 2 || x%2 == 0) return false;
    for(int i=3;i*i<=x;i+=2){
        if(x%i == 0) return false;
    }
    return true;
}

bool specialPrime(int x){
    if(!prime(x)) return false;
    int temp = x;
    if(temp > 2) while(temp){
        if(temp%10 == 2) return false;
        temp/=10;
    }
    string toPerm = to_string(x);
    sort(toPerm.begin(), toPerm.end());
    do{
        if(!prime(stoi(toPerm))) return false;
    }while(next_permutation(toPerm.begin(), toPerm.end()));

    return true;
}

int main(){

    fastInputOutput();
    set<int> sPrimes;
    for(int i=1;i<=1e6;i++)
        if(specialPrime(i))
            sPrimes.insert(i);

    int n;
    while(cin>>n, n){
        auto it = sPrimes.upper_bound(n);
        if(it == sPrimes.end()){
            cout<<0<<endl;
        }else{
            ll nearstPow = 10;
            while(nearstPow <= n){
                nearstPow*=10;
            }
            if(*it < nearstPow ){
                cout<<*it<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
    return 0;

}
