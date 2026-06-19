#include<iostream>
using namespace std;
bool a[20][500005]={{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}},k[25];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,c=20,g[25]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288},cnt=0;
	cin>>n>>m;
	if(m==0)
	{
		while(n)
		{
			if(n>=g[c])
			{
				cnt+=g[c];
			}
			c--;
		}
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
		}
		cout<<cnt;
		return 0;
	}
	if(m==1)
	{
		int m1;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if(x==0)
			{
				m1++;
			}
		}
		m-=m1;
		while(m)
		{
			if(m>=g[c])
			{
				cnt+=g[c];
			}
			c--;
		}
		c=20;
		while(m)
		{
			if(m1>=g[c])
			{
				cnt+=g[c];
			}
			c--;
		}
		cout<<cnt;
		return 0;
	}
	while(m)
	{
		if(m>=g[c])
		{
			k[c]=1;
			m-=g[c--];
		}
		else
		{
			k[c]=0;
			c--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x,j=20;
		cin>>x;
		while(x)
		{
			if(x>=g[j])
			{
				a[j][i]=!a[j][i-1];
				x-=g[j--];
			}
			else
			{
				a[j][i]=a[j][i-1];
				j--;
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			bool b=1;
			for(int p=1;p<21;p++)
			{
				if(a[p][i]!=a[p][j])
				{
					if(k[p]!=1)
					{
						b=0;
						break;
					}
				}
				else
				{
					if(k[p]!=0)
					{
						b=0;
						break;
					}
				}
			}
			if(b)
			{
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
