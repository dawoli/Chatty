#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509;
const ll MOD=998244353;
ll n,m,s[N],c[N],p[N];
ll ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string op;
	cin>>op;
	for(ll i=1;i<=n;i++) s[i]=(int)(op[i-1]-'0');
	for(ll i=1;i<=n;i++) cin>>c[i];
	for(ll i=1;i<=n;i++) p[i]=i;
	do{
		ll cnt=0;
		ll cnt2=0;
		for(int i=1;i<=n;i++){
			if(c[p[i]]<=cnt){
				cnt++;
				continue;
			}
			//cout<<s[i]<<" ";
			if(s[i]==0) cnt++;
			if(s[i]==1) cnt2++;
		}
		//out<<cnt2<<endl;
		if(cnt2>=m) ans=(ans+1)%MOD;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans<<endl; 
	return 0;
}

