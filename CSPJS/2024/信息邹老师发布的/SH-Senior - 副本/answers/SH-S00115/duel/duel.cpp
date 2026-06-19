#include<bits/stdc++.h>
using namespace std;
long long c[200000];
long long c1[200000];
int main()
{
	freopen("dule.in","r",stdin);
	freopen("dule.out","w",stdout);
	long long a,a1;
	cin>>a;
	a1=a;
	for(long long b=1;b<=a;b++)
	{
		cin>>c[b];
	}
	sort(c+1,c+1+a);
	for(long long b=2;b<=a;b++)
	{
		for(long long b1=b-1;b1>0;b1--)
		{
			if(c1[b1]==0&&c[b1]<c[b])
			{
				c1[b1]=1;
				a1--;
				break;
			}
		}
	}
	cout<<a1;
	return 0;
}
