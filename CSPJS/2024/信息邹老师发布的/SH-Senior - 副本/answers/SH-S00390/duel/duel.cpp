#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll x[100009];
ll u[100009];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i];
    sort(x+1,x+n+1);
    ll ans=0;
    for(int i=1,j=1;i<=n&&j<=n;) {
        if(u[i]==1) i++;
        else if(u[j]==1||u[j]==2) j++;
        else if(i==j) j++;
        else if(x[j]>x[i]) ans++,u[i]=1,u[j]=2;
        else j++;
    }
    cout<<n-ans;
    return 0;
}
