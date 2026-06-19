#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int n,a[N],x[N],ans,s[N],dp[N],hd[N],nxt[N];
void check(){
	int lst[2]={0,0},tmp=0;
	for(int i=1;i<=n;i++){
		if(a[lst[x[i]]]==a[i]){
			tmp+=a[i];
		}
		lst[x[i]]=i;
	}
	ans=max(ans,tmp);
}
void dfs(int u){
	if(u==n+1){
		check();
		return;
	}
	x[u]=0;
	dfs(u+1);
	x[u]=1;
	dfs(u+1);
}
void solveBF(){
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans<<endl;
}
void solve(){
	memset(s,0,sizeof(s));
	memset(hd,0,sizeof(hd));
	memset(nxt,0,sizeof(nxt));
	memset(dp,0,sizeof(dp));
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=a[i];
		if(a[i]==a[i-1]){
			s[i]=s[i-1]+a[i];
		}else{
			s[i]=s[i-1];
		}
	}
	sort(x+1,x+n+1);
	int nUnq=unique(x+1,x+n+1)-x-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(x+1,x+nUnq+1,a[i])-x;
		nxt[i]=hd[a[i]];
		hd[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(!nxt[i]){
			dp[i]=dp[nxt[i]+1]+s[i-1]-s[nxt[i]+1];
		}else{
			dp[i]=dp[nxt[i]+1]+a[i]+s[i-1]-s[nxt[i]+1];
		}
		ans=max(ans,dp[i]+s[n]-s[i]);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=15){
			solveBF();
		}else{
			solve();
		}
	}
	return 0;
}
