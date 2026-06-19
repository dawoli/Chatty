#include<bits/stdc++.h>
using namespace std;

int n;
const int N=5005;
int a[N];
int ans=0;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	int j=0;
	while(j<n)
	{
		int maxn=0,sum=0,m=0;
		m=n-j+1;
		if(m<3)
		{
			j++;
			continue;			
		}
		for(int i=j;i<=n;i++)
		{
			sum+=a[i];
			maxn=max(maxn,a[i]);
			if(sum>maxn*2)
				ans++;
		}
		j++;
	}
	cout<<ans;
	return 0;
}
