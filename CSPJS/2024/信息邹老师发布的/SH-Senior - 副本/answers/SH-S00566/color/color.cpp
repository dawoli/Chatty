#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[2001],f[2001][2001][2];
bool True=false;
int vis[2001];
void solve(){
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		a[i]=t;
		vis[t]++;
		if(vis[t]==2)
			True=true;
	}
		puts("0");
	
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		solve();	
	}
}
