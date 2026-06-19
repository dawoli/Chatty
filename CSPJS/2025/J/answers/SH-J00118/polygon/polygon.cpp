#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,u1,u2,u3=0;
long long l1[505];
long long l2[50005];
long long l3[50005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygen.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	else if(n==3)
	{
		cin>>l1[1]>>l1[2]>>l1[3];
		if(2*max(max(l1[1],l1[2]),l1[3])<l1[1]+l1[2]+l1[3])
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		for(long long i=1;i<=n;i++)
		{
			cin>>l1[i];
			u3=max(u3,l1[i]);
		}
		sort(l1+1,l1+n+1);
		l2[0]++;
		l2[l1[1]]++;
		for(long long i=3;i<=n;i++)
		{
			u2=1;
			u1=1;
			for(long long j=1;j<i;j++)
			{
				u1*=i-j;
				u1/=j;
				u2+=u1;
			}
			for(long long j=0;j<=u3;j++)
			{
				l3[j]=l2[j];
			}
			for(long long j=0;j<=u3;j++)
			{
				l2[j+l1[i-1]]+=l3[j];
			}
			u1=0;
			for(long long j=0;j<=l1[i];j++)
			{
				u1+=l2[j];
			}
			ans+=u2-u1;
		}
		cout<<ans;
	}
}
