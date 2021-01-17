#include <iostream>
using namespace std;
int main(){
    int n,m,c;
    while(cin>>n>>m>>c){
        if(n == 0 && m == 0 && c == 0){
            break;
        }
        int rows = n-7, cols = m-7;
        long long total = (rows*cols%2 != 0 && c == 1) ? ((rows*cols)/2)+1:rows*cols/2;
        cout<<total<<endl;
    }
    return 0;
}

