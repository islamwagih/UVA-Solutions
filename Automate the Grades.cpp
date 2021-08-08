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
    int i = 1;
    while(t--){
        int* arr = new int[4];
        int* bestOfTwo = new int[3];
        double grade = 0.0;
        for(int i=0;i<4;i++){
            cin>>arr[i];
            grade += arr[i];
        }
        for(int i=0;i<3;i++){
            cin>>bestOfTwo[i];
        }
        sort(bestOfTwo, bestOfTwo+3);
        double avg = (bestOfTwo[1]+bestOfTwo[2])/2.0;
        grade += avg;
        cout<<"Case "<<i++<<": ";
        if(grade >= 90){
            cout<<"A";
        }else if(grade >= 80){
            cout<<"B";
        }else if(grade >= 70){
            cout<<"C";
        }else if(grade >= 60){
            cout<<"D";
        }else{
            cout<<"F";
        }
        cout<<endl;
        delete[] arr;
        delete[] bestOfTwo;
    }
    return 0;
}
