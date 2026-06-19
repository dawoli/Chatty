#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0;
const int mod=998244353;
void dfs(int s,int z,int h,int j,int nn)
{
	ans%=mod;
	if(s<nn)
	{
		if((h+a[s])>z&&(j+1)>=2) 
	    {
		ans++;
	    }
	dfs(s+1,z,h+a[s],j+1,nn);
	dfs(s+1,z,h,j,nn);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		dfs(1,a[i],0,0,i);
	}
	cout<<ans%mod<<endl;
	return 0;
}
