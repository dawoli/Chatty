#include<bits/stdc++.h>
using namespace std;
int a[200005],c[200005];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(i!=j)
				{
					if(a[i]==a[j])
					{
						sum+=a[i];
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
