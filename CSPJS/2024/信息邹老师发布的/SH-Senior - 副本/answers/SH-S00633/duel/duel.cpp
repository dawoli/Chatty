#include<bits/stdc++.h>
using namespace std;
int a[100001],n,sum;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				if(a[i]>a[j])
				{
					sum++;
					break;
				}
			}
		}
	}
	cout<<n-sum;
	return 0;
}
