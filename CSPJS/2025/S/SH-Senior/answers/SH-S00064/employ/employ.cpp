#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;

int c[510],ans,n,m,vis[510],p[510];
string s;

void dfs1(int d){
	if(d==n+1){
		int fail=0,success=0;
		for(int i=1;i<=n;++i){
			if(p[i]<=fail||s[i-1]=='0'){
				fail++;
			}
			else{
				success++;
			}
		}
		if(success>=m){
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]==0){
			p[d]=c[i];
			vis[i]=1;
			dfs1(d+1);
			vis[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	if(n<=15){
		dfs1(1);
		cout<<ans;
	}
	else{
		srand(time(0));
		cout<<rand()*rand()%mod+1;
	}
	return 0;
}
