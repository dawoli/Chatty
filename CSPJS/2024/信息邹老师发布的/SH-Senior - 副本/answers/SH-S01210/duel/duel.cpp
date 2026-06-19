#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,r[200000],add[200000];
	cin>>n;
	memset(add,0,sizeof 0);
	for(int i=1;i<=n;i++)
		cin>>r[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(r[i]>r[j])
				swap(r[i],r[j]);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(r[i]>r[j]&&add[i]==0&&add[j]!=-2)
			{
				add[i]=-1;
				add[j]=-2;
				break;
			}
		}

	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(add[i]!=-2)
			ans++;
	cout<<ans;
	return 0;
}
