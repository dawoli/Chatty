#include<bits/stdc++.h>
using namespace std;
int n,a[500005],fa=0,k,cnt,findc;
bool vis[500005];
int check(int q,int e)
{
	int sum=1,ans=0;
	while(q||e)
	{
		if((q%2)!=(e%2)) ans+=sum;
		q/=2,e/=2,sum*=2;
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int s;
		cin>>s;
		a[i]=check(s,a[i-1]);
		if(a[i]==0) findc++;
	}
	for(int i=1;i<=n;i++)
	{
		int flag=true;
		for(int j=i;j>0;j--)
		{
			if(vis[j]) break;
			if(flag)
			{
				if(check(a[i],a[j-1])==k) 
				{
					cnt++;
					vis[j-1]=true,vis[i]=true;
					break;
				}
			}
		} 
	}
	cout<<cnt;
	return 0;
}
