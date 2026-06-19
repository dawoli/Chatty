#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,a[200001];
ll dfs(ll k,ll r,ll b)
{
	ll g1=0,g2=0;
	if(k==n) return 0;
	g1=0;
	g2=0;
	if(a[k]==r) g1=r;
	if(a[k]==b) g2=b;
	return max(dfs(k+1,a[k],b)+g1,dfs(k+1,r,a[k])+g2);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++) cin>>a[j];
		cout<<dfs(0,-1,-1)<<endl;
	}
	return 0; 
}
//Ã¶¾Ù¶ÔÅÄ´úÂë
