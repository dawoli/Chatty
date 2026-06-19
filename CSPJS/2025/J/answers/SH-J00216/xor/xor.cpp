#include<bits/stdc++.h>
using namespace std;
long long a[500001];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int cnt=0;
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			long long sum=0;
			for(int l=i;l<=j;l++) sum^=a[l];
			if(sum==k)
			{
				cnt++;
				i=j+1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
