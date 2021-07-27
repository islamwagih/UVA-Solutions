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

int gcd(int a, int b){
    if(a%b == 0){
        return b;
    }
    return gcd(b, a%b);
}

vector<int> nums;

int main(){
    fastInputOutput();
    int n;
    while(cin>>n){
        if(n == 0) break;
        int t = n;
        while(t--){
            int val;cin>>val;
            nums.push_back(val);
        }
        int noFactorPairs = 0;
        for(int i=0;i<getSize(nums);i++){
            for(int j=i+1;j<getSize(nums);j++){
                int greatest = gcd(nums[i], nums[j]);
                if(greatest == 1){
                    noFactorPairs++;
                }
            }
        }
        if(noFactorPairs == 0){
            cout<<"No estimate for this data set.\n";
        }else{
            ///(6/(pi^2)) = N/allPairs
            int allPairs = (n*(n-1))/2;
            cout<<fixed<<setprecision(6)<<sqrt((double)(6*allPairs)/noFactorPairs)<<endl;
        }
        nums.clear();
    }
    return 0;
}

