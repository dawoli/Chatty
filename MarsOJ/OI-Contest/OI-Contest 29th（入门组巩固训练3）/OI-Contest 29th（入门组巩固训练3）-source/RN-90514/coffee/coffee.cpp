#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n,m;
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        int a[7];
        ll ans=0,wek=0;
        string t;
        memset(a,0,sizeof(a));
        for(int i=0;i<5;i++){
            int cnt=0;
            for(int j=0;j<8;j++){
                cin>>t;
                if(t=="math") cnt++;
            }
            a[i]=cnt;
            wek+=cnt;
        }
        cin>>n>>m;
        m--;
        ans+=n/7*wek;
        for(int i=0;i<n%7;i++){
            int td=(m+i)%7;
            ans+=a[td];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
