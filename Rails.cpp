#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/**Not part of the solution it's just a logger to help me debug quickly**/
class Logger{
    bool loggerIsWorking = 1;
public:
    void log(const char* msg, long double val = INT_MIN){
        if(loggerIsWorking){
            if(val != INT_MIN){
                cout<<msg<<" "<<val<<endl;
            }else{
                cout<<msg<<endl;
            }
        }
    }

    void log(char* msg, long double val = INT_MIN){
        if(loggerIsWorking){
            if(val != INT_MIN){
                cout<<msg<<" "<<val<<endl;
            }else{
                cout<<msg<<endl;
            }
        }
    }

    void log(string& msg, long double val = INT_MIN){
        if(loggerIsWorking){
            if(val != INT_MIN){
                cout<<msg<<" "<<val<<endl;
                cout<<msg<<endl;
            }
            }else{
        }
    }

    void log(string&& msg, long double val = INT_MIN){
        if(loggerIsWorking){
            if(val != INT_MIN){
                cout<<msg<<" "<<val<<endl;
            }else{
                cout<<msg<<endl;
            }
        }
    }

    void turnOf(){
        loggerIsWorking = 0;
    }

    void turnOn(){
        loggerIsWorking = 1;
    }

};

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

Logger screen;

int main(){

    fastInputOutput();
    screen.turnOf();

    int n;
    while(cin>>n, n){
        int* arr = new int[n];
        while(true){
            for(int i=0;i<n;i++){
                int val;cin>>val;
                arr[i] = val;
                if(i == 0 && arr[i] == 0){
                    break;
                }
            }
            if(arr[0] == 0){
                break;
            }
            int idx = 0;
            stack<int> stk;
            for(int i=1;i<=n;i++){
                stk.push(i);
                while((!stk.empty()) && arr[idx] == (int)stk.top() && idx < n){
                    idx++;
                    stk.pop();
                }
            }

            if(stk.empty()){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }

        }
        cout<<endl;
        delete[] arr;
    }

    return 0;
}
