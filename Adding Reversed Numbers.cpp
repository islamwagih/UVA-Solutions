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

int getSpaceInd(string& toSearch){
    int notFound = -1;
    for(int i=0;i<getSize(toSearch);i++){
        if(toSearch[i] == ' '){
            return i;
        }
    }
    return notFound;
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    cin.ignore();
    while(t--)
    {
        int* bigNum1 = new int[200];
        int* bigNum2 = new int[200];
        int* bigSum = new int[201];
        string line = "";
        getline(cin, line);
        for(int i=0;i<200;i++)
        {
            bigNum1[i] = 0;
            bigNum2[i] = 0;
            bigSum[i] = 0;
        }
        bigSum[200] = 0;
        int separate = getSpaceInd(line);
        int sz1 = separate, sz2 = getSize(line) - (separate + 1);
        for(int i=0;i<sz1;i++){
            bigNum1[i] = line[i] - '0';
        }
        for(int i=0;i<sz2;i++){
            bigNum2[i] = line[separate+1] - '0';
            separate++;
        }
        for(int i=0;i<min(sz1, sz2);i++){
            bigSum[i] = bigNum1[i]+bigNum2[i];
        }
        if(sz1 > sz2){
            for(int i=sz2;i<sz1;i++){
                bigSum[i] = bigNum1[i];
            }
        }else{
            for(int i=sz1;i<sz2;i++){
                bigSum[i] = bigNum2[i];
            }
        }
        for(int i=0;i<200;i++){
            if(bigSum[i] >= 10){
                bigSum[i] -= 10;
                bigSum[i+1]++;
            }
        }
        int bigSz = 0;
        for(int i=200;i>-1;i--){
            if(bigSum[i] != 0){
                bigSz = i+1;
                break;
            }
        }
        int start = 0;
        for(int i=0;i<201;i++){
            if(bigSum[i] == 0){
                start++;
            }else{
                break;
            }
        }
        for(int i=start;i<bigSz;i++){
            cout<<bigSum[i];
        }
        cout<<endl;
        delete[] bigNum1, bigNum2, bigSum;
    }
    return 0;
}

