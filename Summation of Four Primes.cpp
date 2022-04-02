#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (ll)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void FIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e7+5;
const int M = 2*N;
const int mod = 1e9+7;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;

int isComp[N];
vector<int> primes;

void sieve(){
    isComp[0] = isComp[1] = 1;
    for(ll i=2;i*i<=N;i++){
        if(!isComp[i]){
            for(ll j=i*i;j<N;j+=i){
                isComp[j] = 1;
            }
        }
    }
    for(int i=2;i<N;i++){
        if(!isComp[i]) primes.push_back(i);
    }
}

pair<int, int> primeSum(int x){
    int low = 0, high = lower_bound(primes.begin(), primes.end(), x)-primes.begin();
    if(high == primes.size()) high--;
    while(low <= high){
        int sum = primes[low]+primes[high];
        if(sum > x) high--;
        else if(sum < x) low++;
        else{
            return {low, high};
        }
    }
    return {-1, -1};
}

int main(){
    FIO();
    sieve();
    int n;
    while(cin>>n){
        if(n < 8){
            cout<<"Impossible.\n";
        }else{
            if(n%2 == 0){
                cout<<"2 2 ";
                auto pr = primeSum(n-4);
                cout<<primes[pr.F]<<' '<<primes[pr.S]<<endl;
            }else{
                cout<<"2 3 ";
                auto pr = primeSum(n-5);
                cout<<primes[pr.F]<<' '<<primes[pr.S]<<endl;
            }
        }
    }
    return 0;
}
