#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
ll n,a[N],c[N],ans; //0-Red 1-Blue
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    for(int b=1;b<=T;b++){
        ans=0;
        cin>>n;
        for(ll i=1;i<=n;i++)cin>>a[i];
        for(ll i=1;i<=n;i++)
            for(ll j=i+1;j<=n;j++)
                if(a[i]==a[j]){
                    c[j]=c[i];
                    for(ll k=i+1;k<=j-1;k++)c[k]=1-c[i];
                    break;
                }
        for(ll i=2;i<=n;i++)
            for(ll j=i-1;j>=1;j--)
                if(a[i]==a[j]&&c[i]==c[j])ans+=a[i];
        cout<<ans<<endl;
    }
    return 0;
}