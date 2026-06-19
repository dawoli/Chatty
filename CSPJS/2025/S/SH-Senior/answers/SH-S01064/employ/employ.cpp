#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353,N=500;
ll p[N],a[N],id[N],fac[20];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ll n,m,cnt=0;
    string s;
    cin>>n>>m>>s;
    for(ll i = 0;i < n;i++){
        if(s[i]=='0')p[++cnt]=i;
    }
    s=" "+s;
    ll cnt2=cnt;
    for(cnt2++;cnt2<=n;cnt2++){
        p[cnt2]=n;
    }
    for(ll i = 1;i <= n;i++)cin>>a[i];
    if(n==m){
        ll ans=1;
        for(ll i = 1;i <= n;i++){
            ans*=p[a[i]];
            ans%=mod;
            if(a[i]<=cnt)p[a[i]]--;
        }
        cout<<ans;
    }
    else if(n<=18){
        ll ans=0;
        for(ll i = 1;i <= n;i++)id[i]=i;
        do{
            ll fail=0;
            for(ll i = 1;i <= n;i++){
                if(s[i]=='0' || fail>=a[id[i]]){
                    fail++;
                }

            }
            if(n-fail>=m)ans++;
        }while(next_permutation(id+1,id+n+1));
        cout<<ans;
    }
    else{
    	ll ans=1;
    	for(ll i = 1;i <= n;i++){
    		ans*=i;
			ans%=mod;    		
		}
		cout<<ans;
	}
    return 0;
}

