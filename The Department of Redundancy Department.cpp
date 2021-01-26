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
    queue<int> order;
    unordered_map<int, int> numbers;
    int value;
    while(cin>>value){
        if(numbers.find(value) == numbers.end()){
            ///first time to see that number
            order.push(value);
            numbers[value] = 1;
        }else{
            numbers[value]++;
        }
    }

    while(!order.empty()){
        int currTop = order.front();
        order.pop();
        cout<<currTop<<' '<<numbers[currTop]<<endl;
    }

    return 0;
}

