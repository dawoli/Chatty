#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool a1a[500010][22],a2a[22],yu[22];
int sd[500010];
long long a,s,d,cnt=0,f;
void xxx(int d,int j)
{
	for(int i=0;d;i++)
	{
		a1a[j][i]=d%2;
		if(a2a[i]==0&&a1a[j][i])
		{
			a1a[j][22]=1;
			return;
		}
		d/=2;
	}
}
bool che()
{
	for(int k=0;k<f;f++)
	if(yu[k]!=a2a[k])
	return 0;
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>s;
	for(int i=0;s;i++)
	{
		a2a[i]=s%2;
		s/=2;
		f=i;
	}
	for(int i=0;i<a;i++)
	{
		cin>>sd[i];
		xxx(sd[i],i);
	}
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<22;j++)
		{
			yu[j]=0;
		}
		for(int j=i;j<a;j++)
		{
			if(a1a[j][22])
			{
				i=j;
				break;
			}
			for(int k=0;k<f;f++)
			{
			yu[k]+=a1a[j][k];
			}
			if(che())
			{
				do{
					if(j==a)
					break;
					j++;
					cnt++;
				}while(a1a[j][22]==0);
				if(j<a)
				i=j;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
