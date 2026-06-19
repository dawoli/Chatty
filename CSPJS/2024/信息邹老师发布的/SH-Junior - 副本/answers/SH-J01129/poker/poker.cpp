#include<bits/stdc++.h>
using namespace std;
int n,k=0,sum=0,suma=0,sumb=0,ans;
string Sh[55],Sha[55],Shb[55];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>Sh[i];
		Sha[i]=Sh[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(Sh[i]!=Sha[j]) sum++;
		if(sum==n-1) suma++;
		else
		{
			for(int t=1;t<=n;t++)
		    {
				if(Sh[i]!=Shb[t]) sumb++;
		    }
		    if(sumb==n) Shb[++k]=Sh[i];
		}
		sum=0;
	}
	suma+=k;
	ans=52-suma;
	cout<<ans<<endl;
	return 0;
}
