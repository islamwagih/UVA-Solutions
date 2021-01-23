#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int n;
    while(cin>>n){
        if(n == 0) break;
        queue<int> cards;
        for(int i=1;i<=n;i++){
            cards.push(i);
        }
        cout<<"Discarded cards:";
        while(!cards.empty()){
            int curr = cards.front();
            cards.pop();
            if(!cards.empty()){
                cout<<' '<<curr;
                int top = cards.front();
                cards.pop();
                if(!cards.empty()){
                    cout<<',';
                }
                cards.push(top);
            }else{
                cout<<"\nRemaining card: "<<curr<<endl;
            }
        }
    }
    return 0;
}
