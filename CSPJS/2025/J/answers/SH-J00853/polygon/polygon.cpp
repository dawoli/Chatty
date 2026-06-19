#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int t[5005],p[23],n,res=0;
int a[5005][5005];
void solve(){
	int sum=0,maxn=-1,m=0;
	for(int i=1;i<=n;i++){
		if(!p[i]) continue;
		maxn=max(maxn,t[i]);
		sum+=t[i];
		m++;
	}if(m<3) return;
	if(sum>maxn*2) res++;
}
int fC(int g,int m){
	return a[g+1-m][m+1];
}
void dfs(int x){
	if(x==n+1){
		solve();
		return;
	}
	p[x]=1;
	dfs(x+1);
	p[x]=0;
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",st6dout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i];
	if(n<=20){
		dfs(1);
		cout<<res<<endl;
	}
	for(int i=1;i<=n+1;i++) a[1][i]=1;
	for(int i=1;i<=n+1;i++) a[i][1]=1;
	for(int i=2;i<=n+1;i++)
		for(int j=2;j<=n+1;j++)
			a[i][j]=(a[i-1][j]+a[i][j-1])%MOD;
	for(int k=3;k<=n;k++)
		res=(res+fC(n,k))%MOD;
	cout<<res<<endl;
	return 0;
}
