#include <bits/stdc++.h>
using namespace std;
const long long P = 998244353;
int n,m,num; 
long long f[501][501][501],ans; 
int a[501];
string s;
void dfs(int i,int k,int j)
{
	if(i==n)
	{
		if(k>=m) ans++;
		return ;
	}
	dfs(i+1,k,j);
	if(j<num) if(i==1||i-k-1<=a[i]) dfs(i+1,k+1,j+1);
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
 	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) if(s[i]=='1') num++;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(num==0||num<m) 
	{
		if(m==0)
		{
			ans=1;
			for(int i=1;i<=n;i++) ans=(ans*i)%P;
			cout<<ans<<endl;
		}
		else cout<<0<<endl;
		return 0;
	}
	if(num==n)
	{
		ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%P;
		cout<<ans<<endl;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
} 

