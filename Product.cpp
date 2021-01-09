#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    string a, b;
    while(cin>>a){
        cin>>b;
        int arr[600] = {0};
        set<int> length;
        ///handshake multiplication
        int aIdx = a.size()-1, bIdx = b.size()-1;
        for(int i=aIdx;i>-1;i--){
            for(int j=bIdx;j>-1;j--){
                arr[i+j] += (a[i]-48)*(b[j]-48);
                length.insert(i+j);
            }
        }
        ///dealing with the carry
        for(int i=599;i>-1;i--){
            if(arr[i] != -1 && arr[i] >= 10 && i != 0){
                int current = arr[i]%10;
                arr[i]/=10;
                int carry = arr[i];
                arr[i] = current;
                arr[i-1] += carry;
            }
        }
        int setLength = length.size();
        for(int i=0;i<setLength;i++){
            if(arr[0] == 0){
                cout<<0;
                break;
            }
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}
