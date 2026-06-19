#include<bits/stdc++.h>
#define N 509
#define MOD 998244353
using namespace std;
typedef long long ll;
ll n,m,c[N],s[N],ans,a[N];
string S;
bool iss0=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>S;
	for(ll i=1;i<=n;i++) cin>>c[i];
	S=' '+S;
	for(ll i=1;i<=n;i++){
		s[i]=S[i]-'0';
		if(s[i]!=0) iss0=0;
	}
	//for(ll i=1;i<=n;i++) cout<<"s["<<i<<"]="<<s[i]<<endl;
	if(iss0) cout<<0<<endl;
	else{
		for(ll i=1;i<=n;i++) a[i]=i;
		//sort(c+1,c+1+n);
		do{
			/*for(ll i=1;i<=n;i++) cout<<c[i]<<" ";
			cout<<endl;*/
			ll skip=0,cnt=0;
			for(ll i=1;i<=n;i++){
				if(s[i]==1 and skip<c[a[i]]) cnt++;
				else skip++;
			}
			if(cnt>=m) ans=(ans+1)%MOD;
		}while(next_permutation(a+1,a+1+n));
		cout<<ans;
	}
	return 0;
}
