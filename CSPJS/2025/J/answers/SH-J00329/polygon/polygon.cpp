#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=7;i<=(1<<n+1);i++){
        int m=0,sum=0,maxn=0,p=i,k=0;
        while(p){
            k++;
            p/=2;
        }
        for(int j=1;j<=k;j++){
            if(i&(1<<(j))){
                maxn=max(maxn,a[j]);
                sum+=a[j];
                m++;
            }
        }
        if(m>=3&&sum>2*maxn){
            ans=(ans+1)%mod;
        }
    }
    cout<<ans/2;
    return 0;
}
