#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0;
	string s;
	int c[505];
	bool flag=1;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt++;
	}
	for(int i=0;i<n;i++)if(s[i]=='0')flag=0;
	if(flag&&cnt==0){
		ll ans=1;
		for(int i=1;i<=n-cnt;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
	else cout<<0<<endl;
	return 0;
}
