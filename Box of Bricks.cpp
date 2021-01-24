#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int n, t = 1;
    while(cin>>n){
        if(n == 0) break;
        int* arr = new int[n];
        int moves = 0, sum = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
        }
        int avg = sum/n;
        for(int i=0;i<n;i++){
            if(arr[i] > avg){
                moves += (arr[i] - avg);
            }
        }
        cout<<"Set #"<<t<<endl;
        cout<<"The minimum number of moves is "<<moves<<".\n\n";
        t++;
    }
    return 0;
}

