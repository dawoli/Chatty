#include<bits/stdc++.h>
using namespace std;
int num[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(auto i:s){
        if(isdigit(i)){
            num[i-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=num[i];j++){
            cout<<i;
        }
    }
    cout<<"\n";
    return 0;
}
//g++ -O2 -std=c++14 -static -Wall number.cpp -o number && ./number