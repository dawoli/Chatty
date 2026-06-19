#include<bits/stdc++.h>
using namespace std;
int n,r[100001],s=0,ans;
int main()
{	
	scanf("%d",&n);
	ans=n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&r[i]);
	}
	sort(r+1,r+n+1);
	for (int i=1;i<=n;i++)
	{
		int x=s;
		for (int j=s+1;;j++)
		{
			if (r[j]>r[i])
			{
				s=j;
				break;
			}
			if (s==n) break;
		}
		if (s!=x)
			ans--;
	}
	printf("%d",ans);
}
