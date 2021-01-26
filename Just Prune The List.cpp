#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

unordered_map<int, int> firstList, secondList;
int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;

        for(int i=0;i<n;i++){
            int val;cin>>val;
            if(firstList.find(val) == firstList.end()){
                firstList[val] = 1;
            }else{
                firstList[val]++;
            }
        }

        for(int i=0;i<m;i++){
            int val;cin>>val;
            if(secondList.find(val) == secondList.end()){
                secondList[val] = 1;
            }else{
                secondList[val]++;
            }
        }

        int minMoves = 0;
        for(auto& it:firstList){
            ///check if this element in second list or not
            if(secondList.find(it.first) == secondList.end()){
                ///this element not in the second list then we need to remove it
                minMoves += it.second;
                it.second = 0;
            }else{
                ///this element is in both so we can take abs minus
                int& sec = secondList[it.first];
                minMoves += abs(it.second - sec);
                sec = 0;
                it.second = 0;
            }
        }

        for(auto& it:secondList){
            ///check if this element in first list or not
            if(firstList.find(it.first) == firstList.end()){
                ///this element not in the first list then we need to remove it
                minMoves += it.second;
                it.second = 0;
            }
        }

        cout<<minMoves<<endl;
        firstList.clear(), secondList.clear();
    }
    return 0;
}

