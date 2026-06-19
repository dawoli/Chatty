#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int ma(int n,int m)
{
	if(n>m) return n;
	else return m;
}
int yh(int a,int b)
{
	int za=a,zb=b,ca=1,cb=1;
	int ea[110]={},eb[110]={};
	int ba[110]={},bb[110]={};
	if(za==0) ea[1]=0;
	else
	{
	
		for(int i=1;za>=1;i++)
		{
			if(za==1) 
			{
				ca=i;
				ba[i]=1;
				break;
			}
			if(za%2==1)
			{
				ba[i]=1;
				za-=1;
			}
			else if(za%2==0)
			{
				ba[i]=0;
			}
			za/=2;
		}
	}
	

	if(zb==0) eb[1]=0;
	else
	{
		for(int i=1;zb>=1;i++)
		{
			if(zb==1) 
			{
				cb=i;
				bb[i]=1;
				break;
			}
			if(zb%2==1)
			{
				bb[i]=1;
				zb-=1;
			}
			else if(zb%2==0)
			{
				bb[i]=0;
			}
			zb/=2;
		}
	}


	int zc=ma(ca,cb);
	for(int i=1;i<=zc;i++)
	{
		if(za!=0 and i>zc-ca)
		{
			ea[i]=ba[zc-i+1];
		}
		else ea[i]=0;
		
		if(zb!=0 and i>zc-cb)
		{
			eb[i]=bb[zc-i+1];
		}
		else eb[i]=0;
	}

	
	int jg[110]={},flag=0,jgc=zc;
	for(int i=1;i<=zc;i++)
	{
		if(ea[i]!=eb[i])
		{
			flag=1;
			jg[i]=1;
		}
		else
		{
			if(flag==0) jgc-=1;
			jg[i]=0;
		}
	}
	int sum=0,num=1;
	for(int i=zc;i>zc-jgc;i--)
	{
		sum+=jg[i]*num;
		num*=2;
	}
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	int a[500010],cc[500010]={};
	int dp[500010];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cc[i]=a[i]; 
		if(a[i]==k) 
		{
			sum++;
			dp[i]=1;
		}
	}
	int mac=0;
	int ls=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]==0) 
		{
			ls++;
		}
		if(dp[i]==1 or i==n) 
		{
			mac=ma(mac,ls);
			ls=0; 
		}
	}
	int flag=0;if(dp[1]) flag++;
	for(int j=2;j<=mac;j++)
	{
		for(int i=1+flag;i+j-1<=n;i++)
		{
			for(int z=i;z<i+j;z++)
			{
				if(dp[z]==1) 
				{
					i++;
					continue; 
				} 
			}
			if(i+j-i<=n) cc[i]=yh(cc[i],a[i+j-1]);
			if(cc[i]==k and dp[i]==0)
			{
				for(int l=i;l<i+j;l++) dp[l]=1;
				sum++;
				i+=j-1;
			}
		}
	}
	cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

