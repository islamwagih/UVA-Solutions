#include <iostream>
#include <deque>
using namespace std;
typedef long long ll;

bool PriorityTest(deque<pair<int, int>>& que){
    int top = que[0].first, queSize = que.size();
    for(int i=1;i<queSize;i++){
        if(que[i].first > top){
            return 0;
        }
    }
    return 1;
}

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        deque<pair<int, int>> que(n);
        for(int i=0;i<n;i++){
            cin>>que[i].first;
            if(i == m){
                que[i].second = 1;
            }else{
                que[i].second = 0;
            }
        }
        int totalMins = 1;
        while(true){
            while(!PriorityTest(que)){
                pair<int, int> top = que[0];
                que.pop_front();
                que.push_back(top);
            }
            pair<int, int> curr = que.front();
            que.pop_front();
            if(curr.second == 1){
                ///found M
                break;
            }else{
                totalMins++;
            }
        }
        cout<<totalMins<<endl;
    }
    return 0;
}

