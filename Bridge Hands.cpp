#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int transfer(char curr){
    if(curr >= 49 && curr <= 57){
        ///input -> 1-9
        return curr-48;
    }else if(curr == 'C' || curr == 'D' || curr == 'S' || curr == 'H'){
        ///C<D<S<H
        ///1<2<3<4
        if(curr == 'C'){
            return 1;
        }else if(curr == 'D'){
            return 2;
        }else if(curr == 'S'){
            return 3;
        }else{
            return 4;
        }
    }else{
        ///T<J<Q<K<A
        ///10<11<12<13<14
        if(curr == 'T'){
            return 10;
        }else if(curr == 'J'){
            return 11;
        }else if(curr == 'Q'){
            return 12;
        }else if(curr == 'K'){
            return 13;
        }else{
            return 14;
        }
    }
}

bool comp(pair<char, char> card1, pair<char, char> card2){
    if(card1.first == card2.first){
        ///sort by rank -> (1-9)<T<J<K<A
        return ((transfer(card1.second) > transfer(card2.second)) ? false:true);
    }else{
        ///sort by suite -> C<D<S<H
        char first = card1.first, second = card2.first;
        return ((transfer(first) > transfer(second)) ? false:true);
    }
}

char getNext(char curr){
    /// N -> E -> S -> W
    if(curr == 'N'){
        return 'E';
    }else if(curr == 'E'){
        return 'S';
    }else if(curr == 'S'){
        return 'W';
    }else{
        return 'N';
    }
}

int main(){
    fastInputOutput();
    char c;
    while((cin>>c) && c != '#'){
        string line, cards = "";
        for(int i=0;i<2;i++){
            cin>>line;
            cards += line;
        }
        vector<pair<char, char>> N,E,S,W;
        for(int i=0;i<getSize(cards)-1;i+=2){
            pair<char, char> temp = make_pair(cards[i], cards[i+1]);
            char currPlayer = getNext(c);
            if(currPlayer == 'N'){
                N.push_back(temp);
                c = 'N';
            }else if(currPlayer == 'E'){
                E.push_back(temp);
                c = 'E';
            }else if(currPlayer == 'S'){
                S.push_back(temp);
                c = 'S';
            }else{
                W.push_back(temp);
                c = 'W';
            }
        }

        sort(N.begin(), N.end(), comp);
        sort(E.begin(), E.end(), comp);
        sort(S.begin(), S.end(), comp);
        sort(W.begin(), W.end(), comp);

        cout<<"S: ";
        for(int i=0;i<getSize(S)-1;i++){
            cout<<S[i].first<<S[i].second<<" ";
        }
        cout<<S[getSize(S)-1].first<<S[getSize(S)-1].second<<endl;
        cout<<"W: ";
        for(int i=0;i<getSize(W)-1;i++){
            cout<<W[i].first<<W[i].second<<" ";
        }
        cout<<W[getSize(W)-1].first<<W[getSize(W)-1].second<<endl;
        cout<<"N: ";
        for(int i=0;i<getSize(N)-1;i++){
            cout<<N[i].first<<N[i].second<<" ";
        }
        cout<<N[getSize(N)-1].first<<N[getSize(N)-1].second<<endl;
        cout<<"E: ";
        for(int i=0;i<getSize(E)-1;i++){
            cout<<E[i].first<<E[i].second<<" ";
        }
        cout<<E[getSize(E)-1].first<<E[getSize(E)-1].second<<endl;
    }
    return 0;
}

