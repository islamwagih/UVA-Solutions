#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    string line;
    map<string, string> dic;
    while(getline(cin, line)){
        if(line == ""){
            break;
        }
        string a, b;
        int endIdx = line.find(" ");
        for(int i=0;i<endIdx;i++){
            a += line[i];
        }
        for(int i=endIdx+1;i<line.size();i++){
            b += line[i];
        }
        dic[b] = a;
    }

    string word;
    while(cin>>word){
        if(dic.find(word) == dic.end()){
            cout<<"eh\n";
        }else{
            cout<<dic[word]<<endl;
        }
    }

    return 0;
}
