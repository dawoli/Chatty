#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int z[5005];
	for(int i=1;i<=n;i++)
	{
		cin>>z[i];
	}
	int cnt=0;
	int sum=0;
	int lon=0;
	if(n<3)
	{
		cout<<0;
	}
	if(n==3)
	{
		if(z[1]+z[2]>z[3])
		{
			cout<<1;
			return 0;
		}
	}
	if(n==4)
	{
		for(int a=1;a<=2;a++)
		{
			for(int b=1;b<=2;b++)
			{
				for(int c=1;c<=2;c++)
				{
					for(int d=1;d<=2;d++)
					{
						cnt=0;
						lon=0;
						if(a==1)
						{
							lon++;
						}
						if(b==1)
						{
							lon++;
						}
						if(c==1)
						{
							lon++;
						}
						if(d==1)
						{
							lon++;
						}
						if(lon<3)
						{
							continue;
						}
						if(a==1)
						{
							cnt+=z[1];
						} 
						if(b==1)
						{
							cnt+=z[2];
						} 
						if(c==1)
						{
							cnt+=z[3];
						} 
						if(d==1)
						{
							cnt+=z[4];
						}
						if(cnt>(max(z[1],max(z[2],max(z[3],z[4])))))
						{
							sum++;
						}
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
