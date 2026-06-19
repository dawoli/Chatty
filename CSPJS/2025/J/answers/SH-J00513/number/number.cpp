#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
vector <ll> v;

bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(char c:s){
        if(isdigit(c)){
            v.push_back(int(c-'0'));
        }
    }
    //maxx();
    sort(v.begin(),v.end(),cmp);


    for(ll i:v){
        cout<<i;
    }


    return 0;
}
