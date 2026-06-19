#include<bits/stdc++.h>
using namespace std;
long long t,n,a[1000005],sum,minn=9999999999999; //0:6 1:2 2:5 4:4 7:3 8:7
void dp(int x)
{
	if(n==0)
	{
		minn=min(sum,minn);
	}
	if (n>=6)
	{
		if (x!=0)
		{
			sum*=10;
			n-=6;
			dp(x+1);
			n+=6;
			sum/=10;
		}
		else
		{
			sum*=10;
			n-=6;
			sum+=6;
			dp(x+1);
			n+=6;
			sum/=10;
		}
	}
	if (n>=7)
	{
		sum*=10;
		sum+=8;
		n-=7;
		dp(x+1);
		n+=7;
		sum/=10;
	}
	if (n>=5)
	{
		sum*=10;
		n-=5;
		sum+=2;
		dp(x+1);
		sum/=10;
		n+=5;
	}
	if (n>=4)
	{
		sum*=10;
		n-=4;
		sum+=4;
		dp(x+1);
		sum/=10;
		n+=4;
	}
	if (n>=3)
	{
		sum*=10;
		n-=3;
		sum+=7;
		dp(x+1);
		sum/=10;
		n+=3;
	}
	if (n>=2)
	{
		sum*=10;
		n-=2;
		sum+=1;
		dp(x+1);
		sum/=10;
		n+=2;
	}
} 
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for (int k=1;k<=t;k++)
	{
		minn=9999999999999;
		cin>>n;
		if (n<2)
		{
			cout<<-1<<endl;
			continue;
		}
		if (n%7==0)
		{
			while (n>0)
			{
				cout<<8;
				n-=7;
			}
			cout<<endl;
			continue;
		}
		if ((n-1)%7==0)
		{
			cout<<1;
			n--;
			while (n>0)
			{
				cout<<8;
				n-=7;
			}
			cout<<endl;
			continue;
		}
		dp(0);
		if(minn!=9999999999999)
			cout<<minn<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
