#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int price;cin>>price;
        unordered_set<int> oldPrices;
        pair<int, int> bestSolution;
        bestSolution.first = 0;bestSolution.second = 0;
        for(int i=0;i<n;i++){
            int currPrice = arr[i];
            int desiredPrice = abs(currPrice-price);
            auto it = oldPrices.find(desiredPrice);
            if(it != oldPrices.end()){
                if(bestSolution.first == 0 && bestSolution.second == 0){
                    bestSolution.first = currPrice;
                    bestSolution.second = desiredPrice;
                }else{
                    int currDiff = abs(currPrice-desiredPrice);
                    int oldDiff = abs(bestSolution.first - bestSolution.second);
                    if(currDiff < oldDiff){
                        bestSolution.first = currPrice;
                        bestSolution.second = desiredPrice;
                    }
                }
            }else{
                oldPrices.insert(currPrice);
            }
        }
        cout<<"Peter should buy books whose prices are "<<min(bestSolution.first, bestSolution.second)<<" and "<<max(bestSolution.first, bestSolution.second)<<'.'<<endl<<endl;
    }
    return 0;
}

