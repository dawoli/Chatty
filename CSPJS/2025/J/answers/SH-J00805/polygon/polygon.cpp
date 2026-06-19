#include<bits/stdc++.h>
using namespace std;
int n,l[5005],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>l[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+2;j<n;j++)
		{
			int sum=0,maxx=-1;
			for(int k=i;k<=j;k++)
			{
				sum+=l[k];
				if(l[k]>maxx)
				{
					maxx=l[k];
				}
			}
			if(sum>maxx*2)
			{
				ans++;
			//	cout<<"sum:"<<sum<<" maxx:"<<maxx<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}

