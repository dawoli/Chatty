#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],c[N];
int n;
int ans=0;
void dfs(int now,int r,int b,int sum){
	if(now>n){
		ans=max(ans,sum);
		return;
	}
	if(a[now]==a[r]){
		c[now]=a[r];
	}else{
		c[now]=0;
	}
	dfs(now+1,now,b,sum+c[now]);
	if(a[now]==a[b]){
		c[now]=a[b];
	}else{
		c[now]=0;
	}
	dfs(now+1,r,now,sum+c[now]);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}

