#include<bits/stdc++.h>
using namespace std;
const int N=30,inf=1e9,MOD=998244353;
int c[N];
int n,m;
string s;
int vis[N];
int ans=0;
void dfs(int u,int unemploy){
	if(u==n+1){
		if(n-unemploy>=m){
			(ans+=1)%=MOD;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])	continue;
		vis[i]=1;
		if(unemploy>=c[i])	dfs(u+1,unemploy+1);
		else{
			if(s[u-1]=='0')	dfs(u+1,unemploy+1);
			else	dfs(u+1,unemploy);
		};
		vis[i]=0;
		
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(1,0);
	cout<<ans;
	return 0;
} 
