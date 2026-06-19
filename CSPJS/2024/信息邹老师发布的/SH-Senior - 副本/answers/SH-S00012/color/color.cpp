#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n,a[N],c[N],t,col[N],last0,last1,temp0,temp1,ans=0;

void dfs(int x) {
	if(x==n+1) {
		int res=0;
		last0=last1=0;
		for(int i=1;i<=n;i++) {
			if(col[i]==0) if(a[i]==a[last0]) res+=a[i];
			if(col[i]==0) last0=i;
			if(col[i]==1) if(a[i]==a[last1]) res+=a[i];
			if(col[i]==1) last1=i;
		}
		ans=max(res,ans);
		return; 
	}
	col[x]=0;dfs(x+1);
	col[x]=1;dfs(x+1);
}

int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		temp0=temp1=last0=last1=ans=0;
		dfs(1);
		cout<<ans<<'\n'; 
	}
	return 0;
}
