#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e3+9;
ll a[N*300],xors[N][N],p[N],n,k;
void solveBF(){
    for(ll i = 1;i <= n;i++){
        ll ans=0;
        for(ll j = i;j <= n;j++){
            ans^=a[j];
            xors[i][j]=ans;
        }
    }
    for(ll i = 1;i <= n;i++){
        for(ll j = i;j <= n;j++){
            if(xors[i][j]==k){
                p[i]=j;
                break;
            }
        }
    }
    ll l=1,cnt=0;
    while(l<=n){
        l=*min_element(p+l,p+n+1)+1;
        if(l>=n*2)break;
        cnt++;
    }
    cout<<cnt;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(p,0x3f,sizeof(p));
    cin>>n>>k;
    for(ll i = 1;i <= n;i++){
        cin>>a[i];
    }
    if(n<=1000)solveBF();
    else if(k<=1){
        ll ans=0;
        if(k==0){
            ll continious=0;
            for(ll i = 1;i <= n;i++){
                if(a[i]==a[i-1] || i==1)continious++;
                else{
                    if(a[i-1]==0)ans+=continious;
                    else ans+=continious/2;
                }
                continious=1;
            }
            if(a[n]==0)ans+=continious;
            else ans+=continious/2;
        }
        else{
            for(ll i = 1;i <= n;i++){
                if(a[i]==1)ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
