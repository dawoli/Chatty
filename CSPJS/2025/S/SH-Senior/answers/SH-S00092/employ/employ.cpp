#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n,m,c[505],c1;
char s[505];
bool f[505];
ll ans;
void dfs(int d,int cr,int e){
	if(d==n+1){
		if(e>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	else{
		for(int i=1;i<=n;++i){
			if(!f[i]){
				f[i]=1;
				if(s[d]=='0'||c[i]<=cr)
					dfs(d+1,cr+1,e);
				else dfs(d+1,cr,e+1);
				f[i]=0;
			}
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		if(s[i]=='1') c1++;
	}
	for(int i=1;i<=n;++i) cin>>c[i];
	sort(c+1,c+1+n);
	if(c1==n){
		ans=1;
		for(int i=n;i>=1;--i){
			ans*=i;
			ans%=mod;
		}
		
	}
	else dfs(1,0,0);
	cout<<ans<<"\n";
	return 0;
}
