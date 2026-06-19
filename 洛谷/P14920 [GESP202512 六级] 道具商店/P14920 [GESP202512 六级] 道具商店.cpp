#include<bits/stdc++.h>
using namespace std;
int n,k,a,c,f[250001],sum=0,ans;
int main()
{
	memset(f,127,sizeof(f));
	f[0]=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a>>c;
		sum+=a;
		for (int j=sum;j>=a;j--)
			f[j]=min(f[j],f[j-a]+c);
	}
	for (int i=0;i<=sum;i--)
	{
		if (f[i]<=k)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}