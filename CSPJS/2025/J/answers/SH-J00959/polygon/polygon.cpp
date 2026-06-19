#include<iostream>
#include<algorithm>
using namespace std;

int a[5010];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		for(int j=0;j<=n-i;j++)
		{
			int sum=0;
			for(int k=1;k<=i;k++)
			{
				sum=sum+a[j+k];
			}
			if(sum>2*a[j+i])++ans;
		}
	}
	cout<<ans;
	return 0;
}
