#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,a[N],c[N],ans;
void solve1(){
	int cnt=0;
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>=1;j--)
			if(c[i]==c[j]&&a[i]==a[j])
				cnt+=a[i];
	ans=max(cnt,ans);
}
void dfs(int dep){
	if(dep==n+1){
		solve1();
		return;
	}
	c[dep]=1;
	dfs(dep+1);
	c[dep]=0;
	dfs(dep+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){	
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
			ans=0;
			dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
