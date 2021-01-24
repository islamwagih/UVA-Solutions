#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void groupReverse(string& toRev){
    int low = 0, high = toRev.size()-1;
    while(low < high){
        int temp = toRev[low];
        toRev[low] = toRev[high];
        toRev[high] = temp;
        low++, high--;
    }
}

int main(){
    fastInputOutput();
    int n;
    while(cin>>n){
        if(n == 0) break;
        string full;cin>>full;
        int maxSize = full.size(), i=0;
        n = maxSize/n;
        vector<string> vec;
        while(i < maxSize){
            int j = 0;
            string chunk = "";
            while(j < n){
                chunk+=full[i];
                i++,j++;
            }
            groupReverse(chunk);
            vec.push_back(chunk);
        }
        for(string i:vec){
            cout<<i;
        }
        cout<<endl;
    }
    return 0;
}

