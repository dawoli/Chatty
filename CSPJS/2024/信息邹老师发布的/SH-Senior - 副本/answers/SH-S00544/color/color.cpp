#include <bits/stdc++.h>
using namespace std;
int T;
#define N 200001
int n,a[N],c[N],ans;
void dfs(int rd,int bl,int i,int res){
	if(i>n){
		ans=max(ans,res);
		return ;
	}
	if(a[i]==rd)
		dfs(a[i],bl,i+1,res+a[i]);
	if(a[i]==bl)
		dfs(rd,a[i],i+1,res+a[i]);
	dfs(a[i],bl,i+1,res);
	dfs(rd,a[i],i+1,res);
}
void solve(){
	dfs(0,0,1,0);
	cout<<ans<<endl; 
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		solve();
	}
	return 0;
} 
