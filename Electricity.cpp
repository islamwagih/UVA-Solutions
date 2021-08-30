#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}


bool isLeapYear(int year){
    if(year%4 == 0 && year%100 != 0){
        return true;
    }
    return year%400 == 0;
}


map<int, int> date;

void fillDate(int year){
    for(int month = 8;month <= 12;month++){
        if(month%2 == 0){
            date[month] = 31;
        }else{
            date[month] = 30;
        }
    }
    for(int month = 1;month < 8;month++){
        if(month == 2){
            date[month] = 28;
            if(isLeapYear(year)) date[month]++;
        }else if(month%2 == 1){
            date[month] = 31;
        }else{
            date[month] = 30;
        }
    }
}

bool sameDate(int ld, int lm, int ly, int cd, int cm, int cy){
    if(ld != cd)
        return false;
    if(lm != cm)
        return false;
    if(ly != cy)
        return false;
    return true;
}

int diffDates(int ld, int lm, int ly, int cd, int cm, int cy){
    int days = 0;
    while(!sameDate(ld, lm, ly, cd, cm, cy)){
        ld++, days++;
        if(ld > date[lm]){
            ld = 1;
            lm++;
        }
        if(lm > 12){
            lm = 1;
            ly++;
        }
    }
    return days;
}

int main(){

    fastInputOutput();

    int n;
    while(cin>>n, n){
        int ld = -1, lm = -1, ly = -1, lp = -1, ans = 0, cnt = 0;
        while(n--){
            int cd, cm, cy, cp;
            cin>>cd>>cm>>cy>>cp;
            fillDate(cy);
            if(ld != -1){
                if(diffDates(ld, lm, ly, cd, cm, cy) == 1){
                    ans += cp-lp;
                    cnt++;
                }
            }
            ld = cd, lm = cm, ly = cy, lp = cp;
        }
        cout<<cnt<<' '<<ans<<endl;
    }


    return 0;
}

