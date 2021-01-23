#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int p,c,t = 1;
    while(cin>>p>>c){
        if(p == 0 && c == 0) break;
        deque<int> population;
        cout<<"Case "<<t<<":\n";
        int limit = (p>1000)?1000:p;
        for(int i=1;i<=limit;i++){
            population.push_back(i);
        }
        for(int i=1;i<=c;i++){
            char command;cin>>command;
            if(command == 'N'){
                int top = population.front();
                cout<<top<<endl;
                population.pop_front();
                population.push_back(top);
            }else{
                int value;cin>>value;
                auto cursor = population.begin();
                while(cursor!=population.end()){
                    if(*cursor == value){
                        population.erase(cursor);
                        break;
                    }
                    cursor++;
                }
                population.push_front(value);
            }
        }
        t++;
    }
    return 0;
}
