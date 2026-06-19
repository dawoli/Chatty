#include<bits/stdc++.h>
using namespace std;

int n,m,p[530],d[530],sum,ans,f,vis[530];
char sd[530];

void dfs(int x){
	if(sum==m){
		ans++;
		return ;
	}
	for(int i=1; i<=n; i++){
		if(!d[x]&&!vis[i]){
			f++;
			vis[i]=1;
			dfs(x+1);
			f--;
			vis[i]=0;
		}else if(f<p[i]&&!vis[i]){
			vis[i]=1;
			sum++;
			dfs(x+1);
			vis[i]=0;
			sum--;
		}
	}
	return ;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> sd[i];
		d[i]=sd[i]-48;
	}
	for(int i=1; i<=n; i++){
		cin >> p[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}
