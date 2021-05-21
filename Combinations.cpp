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

///Note this program can handle inputs much larger than 100 for example 10000 C 5 which is
///10000!/((10000-5)!*5!) takes no time
int main(){
    fastInputOutput();
    int n, m;cin>>n>>m;
    while(n != 0){
        int mFromInput = m;
        if(n == m){
            cout<<n<<" things taken "<<mFromInput<<" at a time is 1 exactly.\n";
            cin>>n>>m;
            continue;
        }
        m = max(m, n-m);
        int* N = new int[n];
        int* M = new int[m];
        int diff = n-m;
        int* NoM = new int[diff];
        for(int i=0;i<n;i++){
            N[i] = i+1;
        }
        for(int i=0;i<m;i++){
            M[i] = i+1;
        }
        for(int i=0;i<diff;i++){
            NoM[i] = i+1;
        }
        for(int i=0;i<m;i++){
            M[i] = 1;
            N[i] = 1;
        }
        for(int i=0;i<diff;i++){
            if(N[i] != 1){
                N[i] = 1;
                NoM[i] = 1;
            }
        }
        for(int i=0;i<n;i++){
            if(N[i] != 1){
                for(int k=0;k<diff;k++){
                    if(NoM[k] != 1 && N[i]%NoM[k] == 0){
                        N[i]/=NoM[k];
                        NoM[k] = 1;
                    }
                }
            }
        }
        long double numerator = 1;
        for(int i=0;i<n;i++){
            numerator *= N[i];
        }
        long double denominator = 1;
        for(int i=0;i<diff;i++){
            denominator *= NoM[i];
        }
        cout<<fixed<<setprecision(0)<<n<<" things taken "<<mFromInput<<" at a time is "<<numerator/denominator<<" exactly.\n";
        delete[] N, M, NoM;
        cin>>n>>m;
    }
    return 0;
}


