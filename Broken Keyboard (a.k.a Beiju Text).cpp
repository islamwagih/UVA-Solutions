#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

///O(n) where n is the number of characters in the string
int main(){
    fastInputOutput();
    string broken;
    while(cin>>broken){
        list<char> corrStr;
        auto cursor = corrStr.begin();
        int i = 0, j = 0, len = broken.size();
        while(i < len){
            if(broken[i] == '['){
                ///home key
                auto newCursor = corrStr.begin();
                while(i < len){
                    if(broken[i] == '['){
                        newCursor = corrStr.begin();
                    }else if(broken[i] == ']'){
                        break;
                    }else{
                        newCursor = corrStr.insert(newCursor, broken[i]);
                        newCursor++;
                    }
                    i++;
                }
            }else{
                ///normal character or end curr
                if(broken[i] != ']'){
                    cursor = corrStr.insert(cursor, broken[i]);
                    cursor++;
                }
            }
            i++;
        }
        for(cursor = corrStr.begin(); cursor != corrStr.end();cursor++){
            cout<<*cursor;
        }
        cout<<endl;
    }
    return 0;
}

