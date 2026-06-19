#include<bits/stdc++.h>
using namespace std;
int long long t,n,a[200005],y[200005];
int long long mj(int long long s)
{
	int long long maxx=0;
	if(s==n+1)
	{
		for(int i=2;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(y[i]==y[j])
				{
					if(a[i]==a[j])
					{
						maxx+=a[i]; 
					}
					break;
				}
			}
		}
		return maxx;
	}
	y[s]=1;
	maxx=max(mj(s+1),maxx);
	if(s!=1)
	{
		y[s]=2;
		maxx=max(mj(s+1),maxx);
	}
	return maxx;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			y[i]=0;
		} 
		cout<<mj(1)<<endl;
	}
	return 0;
}
