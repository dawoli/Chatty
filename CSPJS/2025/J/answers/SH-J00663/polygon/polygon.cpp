#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[200005];
const ll MOD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		sort(a+1,a+n+1);
		ll ans=0;
		for(ll i=1;i<(1<<n);i++){
			int x=0,y,cnt=0,t=i;
			while(t!=0){
				cnt++;
				if(t%2){
					x+=a[cnt];
					y=cnt;
				}
				t/=2;
			}
			if(x>a[y]*2)ans++;
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
	else if(a[1]==1){
		ll p=1;
		for(int i=1;i<=n;i++){
			p=p*2%MOD;
		}
		
		cout<<(p-1-n-(n*(n-1))/2)%MOD<<endl;
	}
	return 0;
}
