#include <iostream>
using namespace std;
int main(){
    int n,m,c;
    while(cin>>n>>m>>c){
        if(n == 0 && m == 0 && c == 0){
            break;
        }
        int i = 1, j = 1;
        int rows = 0, cols = 0;
        while(n-i >= 7){
            rows++;
            i++;
        }
        while(m-j >= 7){
            cols++;
            j++;
        }
        long long total = (rows*cols%2 != 0 && c == 1) ? ((rows*cols)/2)+1:rows*cols/2;
        cout<<total<<endl;
    }
    return 0;
}

