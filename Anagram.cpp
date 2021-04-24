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

///An upper case letter goes before the corresponding lower case letter
bool comp(char s, char t)
{
    return (tolower(s) == tolower(t)) ? s < t : tolower(s) < tolower(t);
}

int main(){
    fastInputOutput();

    int n;cin>>n;
    while(n--){
        string str;cin>>str;
        sort(str.begin(), str.end(), comp);
        do{
            cout<<str<<endl;
        }while(next_permutation(str.begin(), str.end(), comp));
    }

    return 0;
}
