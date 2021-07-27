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

    int t;cin>>t;
    while(t--){

        bool currSide = 0; ///0 -> left & 1 -> right
        queue<double> rightBank, leftBank;
        double l, m;
        int ans = 0;
        cin>>l>>m;

        while(m--){
            double cargo;string side;
            cin>>cargo>>side;
            cargo/=100; ///convert from cm to m
            if(side == "left"){
                leftBank.push(cargo);
            }else{
                rightBank.push(cargo);
            }
        }

        while(rightBank.size() > 0 || leftBank.size() > 0){
            double lineTall = l;
            if(currSide == 0){
                ///load from left bank
                double currCarTall = 0.0;
                while(!leftBank.empty()){
                    currCarTall = leftBank.front();
                    if(currCarTall > lineTall){
                        break;
                    }else{
                        lineTall -= currCarTall;
                        leftBank.pop();
                    }
                }
                ans++, currSide = 1;
            }else{
                ///load from right bank
                double currCarTall = 0.0;
                while(!rightBank.empty()){
                    currCarTall = rightBank.front();
                    if(currCarTall > lineTall){
                        break;
                    }else{
                        lineTall -= currCarTall;
                        rightBank.pop();
                    }
                }
                ans++, currSide = 0;
            }
        }

        cout<<ans<<endl;

    }

    return 0;
}
