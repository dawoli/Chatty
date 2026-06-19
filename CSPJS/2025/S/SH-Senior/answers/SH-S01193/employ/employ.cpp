#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,arr[505],a[505],c[505],ans;
char t;
void dfs(ll l,ll k)
{
	if(l>n||k>n)return;
	if(l==n) ans++;//
	for(ll i = 1;c[l]>arr[i]&&i<=n;i++)
	{
		if(a[i]==INT_MAX)continue;
		a[i]=INT_MAX;
		dfs(l+1,k);
		a[i]=arr[i];
	}
	//²»Ñ¡
	dfs(l+1,k+1); 
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);//
	cin>>n>>m;
	for(ll i = 1;i<=n;i++)
	{
		cin>>t;
		if(t=='0')a[i]=a[i-1]+1;
		else a[i]=a[i-1];
		arr[i]=a[i];
	}
	for(ll i = 1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+n+1);//
	dfs(1,m);
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
