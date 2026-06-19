#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+50;
int n,a[N],b[N],c[N],ma=-1,len,ans,o;
void dfs(int g,int j)
{
	if(g>=3) ans++;
	ans=ans%998244353;
	for(int i=j;i<=n;i++){
		len+=a[i];
		dfs(g+1,i+1);
		len-=a[i];
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1);
	ans=ans%998244353;
	cout<<ans;
	return 0;
}
