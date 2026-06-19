#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],sum=0,ans=INT_MIN,l=0,ff;
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (l>m)
		{
			sum-=a[i-l+1];
			l--;
		}
        if (l==m)
        {
			ff=sum-a[i-l+1];
        }
		if (ff+a[i]>a[i])
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}