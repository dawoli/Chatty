#include<iostream>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				int maxx=max(max(i,j),k);
				if(maxx==i)
				{
					if(i<j+k)
					{
						cnt++;
					}
				}
				else if(maxx==j)
				{
					if(j<i+k)
					{
						cnt++;
					}
				}
				else
				{
					if(k<i+j)
					{
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
