#include<bits/stdc++.h>
using namespace std;
long long c[200000];
long long c1[200000];
long long c2[200000];
int f(long long x)
{
	for(long long a=x-1;a>=1;a--)
	{
		if(c1[a]==c1[x])
		{
			return a;
		}
	}
	return -1;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	long long a,a1,a2,a3,a4,a5,a6=0;
	cin>>a;
	for(long long b=1;b<=a;b++)
	{
		a6=0;
		cin>>a1;
		for(long long b1=1;b1<=a1;b1++)
		{
			cin>>c[b1];
			c1[b1]=0;
			c2[b1]=0;
		}
		for(long long b1=2;b1<=a1;b1++)
		{
			for(long long b2=b1-1;b2>=1;b2--)
			{
				a5=0;
				if(c[b2]==c[b1])
				{
					a4=0;
					a5=1;
					a2=f(b1);
					if(a2!=b2)
					{
						a3=c1[b2];
						c1[b2]=c1[b1];
						a2=f(b1);
						if(a2!=b2)
						{
							c1[b1]=a3;
							c1[b2]=a3;
							a2=f(b1);
							if(a2!=b2)
							{
								a4=0;
								for(long long b3=b2+1;b3<b1;b3++)
								{
									a4=a4+c2[b3];
								}
								if(a4<c[b1])
								{
									for(long long b3=b2+1;b3<b1;b3++)
									{
										if(c1[b1]==0)
										{
											c1[b3]=1;
										}
										else
										{
											c1[b3]=0;
										}
									}
								}
								else
								{
									a5=0;
								}
							}
						}
					}
				}
				if(a5)
				{
					a6=a6+c[b1]-a4;
					if(b1-b2!=1)
					{
						c2[b1]=c[b1]-a4;
					}
					break;
				}
			}
		}
		cout<<a6<<endl;
	}
	return 0;
}
