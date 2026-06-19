#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
char ch;
int a[510],c[510],suma[510];
int vis[510],dig[510];
void dfs(int dep,int leaved){
	if(dep>=n+1){
		int leave=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0||leave>=c[dig[i]])leave++;
		}
		if(n-leave>=m)ans=(ans+1)%998244353;
		return;
	}
	int nl=leaved+(a[dep]==0||leaved>c[dig[dep]]);
	if(leaved>n-m)return;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dig[dep]=i;
		dfs(dep+1,nl);
		vis[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		a[i]=ch-'0';
		suma[i]=suma[i-1]+a[i];
	}
	if(n-suma[n]<m){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
