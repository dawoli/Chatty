#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<ll> v;
    for(auto i:s){
        if(i>='0'&&i<='9'){
            v.push_back(i-'0');
        }
    }
    sort(v.begin(),v.end(),cmp);
    if(v[0]==0){
        cout<<0<<endl;
        return 0;
    }
    for(auto i:v){
        cout<<i;
    }
}
