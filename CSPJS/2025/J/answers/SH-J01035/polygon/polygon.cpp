#include <bits/stdc++.h>
using namespace std;

int n,a[100000010],ans;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		int k=1;
		for(int p=k+i;p<=n;p++,k++)
		{
			
			int num=0,l=0;
			for (int j=k,m=1;j<=n,m<=i;j++,m++)
			{
				num+=a[j];
				l=a[j];
			}
			cout<<num<<" "<<l*2<<"\n"<<"---------------"<<"\n";
			if (num>l*2)
			{
				ans++;
				
			}
		}
			
	}
	cout<<ans;
	return 0;
}
