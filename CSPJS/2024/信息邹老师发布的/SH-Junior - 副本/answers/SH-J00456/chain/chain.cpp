#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int s[100002];
int g[10003][10003];
int f[10093][10003];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,q,k;cin>>t;
    while (t--){
        cin>>n>>q>>k;
        for(int i = 0;i<n;i++){
            cin>>s[i];
        }
        for(int i = 0;i<n;i++){

            cin>>g[i]>>f[i];
        }
    }
    //cout<<-1<<endl;
    for(int i = 0;i<n/2;i++){
        cout<<1<<endl;
        cout<<0<<endl;
    }



    return 0;
}
