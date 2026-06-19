#include<bits/stdc++.h>
using namespace std;
long long T,n=100000,maxx;
long long ansans[60];
int x[10]{6,2,5,5,4,5,6,3,7,6};
long long m(int nn)
{
	int t=1;
	long long a=0;
	for(int i=1;i<=(nn+1)/2;i++)
	{
		a+=t*1;
		t*=10;
	}
	return a;
}
long long f(long long nn)
{
	int t;
	long long a=0;
	while(nn>0)
	{
		t=nn%10;
		nn/=10;
		a+=x[t];
	}
	return a;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T; 
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		maxx=m(n);
		for(long long j=1;j<=maxx;j++)
		{
			if(f(j)==n)
			{
				ansans[i]=j;
				break;
			}
		}
		if(ansans[i]==0)
		{
			ansans[i]=-1;
		}
	}
	for(int i=1;i<=T;i++)
	{
		cout<<ansans[i]<<endl;
	}
	return 0;
}
