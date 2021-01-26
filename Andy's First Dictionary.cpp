#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

bool isCharacter(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(){
    fastInputOutput();
    string word = "";
    char letter;
    set<string> dic;
    while(cin.get(letter)){
        if(isCharacter(letter)){
            word += tolower(letter);
        }else{
            if(word != ""){
                dic.insert(word);
            }
            word = "";
        }
    }
    set<string>::iterator it = dic.begin();
    while(it != dic.end()){
        cout<<*it<<endl;
        it++;
    }
    return 0;
}

