#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200105],ans,xd1,xd2;
int main()
{
	cin>>t;
	while(t--)
	{
		ans=0;
		xd1=0;
		xd2=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i+2])
			{
				ans=ans+a[i];
				cout<<ans<<" "<<a[i]<<endl;
				xd2=i+2;
				for(int j=xd2;j<=n;j++)
				{
					a[j]=a[j+1];
				}
				for(int j=1;j<=n;j++)
				{
					cout<<a[j]<<" ";
				}
				cout<<endl;
			}
			if(a[i]==a[i+1])
			{
				ans=ans+a[i];
				xd2=i+1;
				for(int j=xd2;j<=n;j++)
				{
					a[j]=a[j+1];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
