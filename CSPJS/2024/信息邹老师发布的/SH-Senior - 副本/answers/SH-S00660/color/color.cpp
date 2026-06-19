#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2e5+5,MAXA=1e6+5;
int T;

int n,a[MAXN],ans;

void dfs(int i,int red,int blue,int sum){
	if(i>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(a[i]==red)
		dfs(i+1,a[i],blue,sum+a[i]);
	else
		dfs(i+1,a[i],blue,sum);
	if(a[i]==blue)
		dfs(i+1,red,a[i],sum+a[i]);
	else
		dfs(i+1,red,a[i],sum);
}

signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
