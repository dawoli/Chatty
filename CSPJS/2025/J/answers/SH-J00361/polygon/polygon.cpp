#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
int a[5009];
long long f[10009];
long long ans,x=0,maxc;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    f[0]=1;
    maxc=a[n]*2;
    for(int i=1;i<=n;i++){
        if(i>=3){
            ans=(ans+x)%mod;
            for(int j=a[i]+1;j<=maxc;j++)ans=(ans+f[j])%mod;
        }
        x=x*2%mod;
        for(int j=maxc;j>=maxc+1-a[i];j--)x=(x+f[j])%mod;
        for(int j=maxc;j>=a[i];j--){
            f[j]=(f[j]+f[j-a[i]])%mod;
        }
    }
    cout<<ans;
    return 0;
}
