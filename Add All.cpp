#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

priority_queue<int, vector<int>, greater<int>> pq;
int main(){

    fastInputOutput();
    int n;
    while(cin>>n, n){
        while(!pq.empty()) pq.pop();
        for(int i=0;i<n;i++){
            int val;cin>>val;
            pq.push(val);
        }
        ll cost = 0;
        while(pq.size() > 1){
            int a = pq.top();pq.pop();
            int b = pq.top();pq.pop();
            pq.push(a+b);
            cost += (a+b);
        }
        cout<<cost<<endl;
    }

    return 0;

}
