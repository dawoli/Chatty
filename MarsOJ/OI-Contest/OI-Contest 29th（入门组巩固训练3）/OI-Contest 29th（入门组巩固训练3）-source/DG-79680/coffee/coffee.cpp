#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,m,ans;
ll cnt[10];
string a[10][10];
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        memset(cnt,0,sizeof(cnt));
        for(ll i=0;i<5;i++){
            for(ll j=1;j<=8;j++){
                cin>>a[i][j];
                if(a[i][j]=="math") cnt[5]++,cnt[i]++;
            }
        }
        cin>>n>>m;
        m--;
        while(n&&m%7){
            if(m%7<5) ans+=cnt[m%7];
            n--;
            m++;
        }
        ans+=cnt[5]*(n/7);
        n%=7;
        while(n){
            if(m%7<5) ans+=cnt[m%7];
            n--;
            m++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
