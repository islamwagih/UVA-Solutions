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

int binSearch(int arr[], int n, int k){
    int low = -1, high = n;
    while(low < high-1){
        int mid = (low+high)/2;
        if(arr[mid] > k){
            high = mid;
        }else{
            low = mid;
        }
    }
    return low;
}


pair<int, int> trimRange(string& str){
    int startIdx = 0, sz = str.size();
    while(startIdx < sz && str[startIdx] == ' '){
        startIdx++;
    }
    int endIdx = sz-1;
    while(endIdx > -1 && str[endIdx] == ' '){
        endIdx--;
    }
    return {startIdx, endIdx-startIdx+1};
}

void trimStr(string& str){
    pair<int, int> range = trimRange(str);
    str = str.substr(range.first, range.second);
}

ll getMedian(vector<ll> nums){
    int sz = nums.size();
    if(sz%2 == 0){
        ///even
        int half = sz/2;
        ll first = nums[half];
        ll sec = nums[--half];
        return (first+sec)/2;
    }else{
        ///odd
        return nums[sz/2];
    }
}

int main(){

    fastInputOutput();
    screen.turnOf();

    vector<ll> numbers;
    ll num;
    while(cin>>num){
        numbers.push_back(num);
        sort(numbers.begin(), numbers.end());
        cout<<getMedian(numbers)<<endl;
    }

    return 0;
}
