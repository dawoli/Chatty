#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int t,n,maxn;
int a[N],c[N];

void dfs(int pos,int color,int ans){
	if (pos>n){
		maxn=max(maxn,ans);
		return;
	}
	c[pos]=color;
	for (int i=pos-1;i>=1;i--){
		if (c[i]==c[pos]&&a[i]==a[pos]){
			ans+=a[pos];
			break;
		}
	}
	dfs(pos+1,0,ans);
	dfs(pos+1,1,ans);
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		maxn=-1;
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		dfs(1,0,0);
		dfs(1,1,0);
		cout<<maxn<<endl;
	}
	return 0;
}

