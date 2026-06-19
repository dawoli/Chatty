#include<bits/stdc++.h>
using namespace std;
int n,num,ans,a[102];
int main()
{
	freopen("drink.in","r",stdin);
	freopen("drink.out","w",stdout);	
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int j=1;j<=n;j++)
	{
		for (int i=1;i<=n;i++)
		{
			if(a[i]!=i)
			{
				swap(a[i],a[a[i]]);
				ans++;
			}
		}	
	}
	cout<<ans<<endl;
	return 0;
}
