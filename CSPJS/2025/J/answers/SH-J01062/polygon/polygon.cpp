#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int ad(int a)
{
	long long i,all=0;
	for(i=1;i<=a-1;i++)
	{
		all+=i*(a-i);
		all%=998244353;
	}
	return all+1;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,x,y,z;
	long long len,len1,len2;
	long long ans=0;
	cin>>n;
	int a[n+1];
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n-2;i++)
	{
		len=a[i];
		for(x=i+1;x<=n-1;x++)
		{
			len1=len+a[x];
			for(y=x+1;y<=n;y++)
			{
				len2=len1+a[y];
				z=0;
				while(len2<=a[i]*2)
				{
					z++;
					if(y+z>n)break; 
					len2+=a[y+z];
			    }
			    if(y+z<=n)
				{
					ans+=ad(n-y-z)+1; 
					ans%=998244353;
				}
			}
		}
	}
	cout<<ans;
	return 0; 
}
