#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

const int MOD=998244353;
ll n,m;
string s;
ll c[600];
ll cun;
ll ans=1;
ll tmp=1;
ll tmp2=1;
ll pos[600];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		pos[i]=n;
	}
	sort(c,c+n);
	for(ll i=0;i<100;i++){
		if(c[i]==0)cun++;
	}
//	cout<<cun<<endl;
	for(ll i=0;i<n;i++){
		while(c[i]==0)i++;
//		cout<<c[i]-cun<<"\n";
		if(c[i]<=cun){
			pos[i]=n-(cun-c[i]+1);
//			cout<<pos[i]<<" "<<"manbo"<<"\n";
		}
	}
	
	for(ll i=0;i<n;i++){
//		pos[i]%=MOD;
		tmp*=pos[i];
		tmp%=MOD;
		ans*=tmp;
		ans%=MOD;
//		cout<<ans<<" ";
	}
	ans%=MOD;
	cout<<ans<<"\n";
	return 0;
}
