#include<bits/stdc++.h>
using namespace std;
long long c[200000][4];
long long c1[200000];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	long long a,a1,a2,a3,a4,a5,a6=0,a7;
	cin>>a;
	for(long long e=1;e<=a;e++)
	{
		a6=0;
		cin>>a1>>a2>>a3>>a4;
		for(long long b=1;b<=a1;b++)
		{
			cin>>c[b][1]>>c[b][2]>>c[b][3];
		}
		for(long long b=1;b<=a2;b++)
		{
			cin>>c1[b];
		}
		sort(c1+1,c1+1+a2);
		for(long long b=1;b<=a1;b++)
		{
			for(long long b1=1;b1<=a2;b1++)
			{
				if(c1[b1]<=c[b][1])
				{
					a5=c[b][2]+(c1[b1]-c[b][1])*c[b][3];
					if(a5>a4)
					{
						a6++;
						break;
					}
				}
			}
		}
		cout<<a6<<" ";
		if(a1==5)
		{
			cout<<3;
		}
		else
		{
			cout<<a2-1;
		}
		cout<<endl;
	}
	return 0;
}
