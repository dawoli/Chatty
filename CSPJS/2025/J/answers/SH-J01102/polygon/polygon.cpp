#include <bits/stdc++.h>
using namespace std;

int n,a[5005],ans;

void dfs(int i,int maxn,int cnt){
	if(i>n){
		if(maxn*2<cnt)
			ans++;
		return;
	}
	dfs(i+1,max(maxn,a[i]),cnt+a[i]);
	dfs(i+1,maxn,cnt);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w".stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
