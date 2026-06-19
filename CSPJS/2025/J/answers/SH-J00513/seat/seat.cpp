#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


vector <ll> a;
ll f[1002][1002];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll n,m;cin>>n>>m;
    for(int i=0;i<n*m;i++){
        ll q;cin>>q;
        a.push_back(q);
    }
    ll r = a[0],newr = 0,x = 0,y = 0;
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<=n*m;i++){
        if(a[i] == r) newr = i+1;
    }



    if(newr%n == 0){
        y = n;
    }
    else y = newr%n;
    if(newr ==1){
        x = 1;y =1;
    }
    else x = ceil(newr%m)+1;
    cout<<x<<" "<<y;


    return 0;
}
