#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2e5+5;
int a[MAXN],ans,n;

void dfs(int pos,int sum,bool flag,int pre0,int pre1){
	if(pos==n+1){
		ans=max(ans,sum);
		return;
	}
	if(pre0==a[pos])	dfs(pos+1,sum+a[pos],0,a[pos],pre1);
	else				dfs(pos+1,sum,0,a[pos],pre1);
	if(pre1==a[pos])	dfs(pos+1,sum+a[pos],1,pre0,a[pos]);
	else				dfs(pos+1,sum,1,pre0,a[pos]);
}

signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++)	cin>>a[j];
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
