#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

long long st[N],cf[N];

string num1,num2;

long long tt(long long x)
{
	int j=1;
	bool t[N];
	t[0]=0;
	long long k=0;
	while(x!=0)
	{
		t[j]=x%2;
		x/=2;
		j++;
	}
	j--;
	while(j!=0)
	{
		k+=t[j];
		j--;
		if(j!=0) 
		{
			k*=10;
		}
	}
	return k;
}

long long ton(long long x,long long y)
{
	int tmp1[N],tmp2[N],tmp[N];
	int j=1,k=1,ti=0;
	long long ans=0;
	while(x!=0)
	{
		tmp1[j]=x%10;
		j++;
		x/=10;
	}
	j--;
	while(y!=0)
	{
		tmp2[k]=y%10;
		k++;
		y/=10;
	}
	k--;
	for(int i=1;i<=min(j,k);i++)
	{
		if(tmp1[i]!=tmp2[i])
		{
			tmp[i]=1;
		}
		else
		{
			tmp[i]=0;
		}
		ti=i;
	}
	ti--;
	for(ti ;ti<=max(j,k);ti++)
	{
		if(j>k)
		{
			tmp[ti]=tmp1[ti];
		}
		else
		{
			tmp[ti]=tmp2[ti];			
		}
	}
	while(ti!=0)
	{
		ans+=tmp[ti];
		ti--;
		if(ti!=0) 
		{
			ans*=10;
		}
	}
	
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m,tmp,ans=0;
	cin>>n>>m;
	m=tt(m);
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		st[i]=tt(tmp);
		if(st[i]==m)
		{
			ans++;
		}
	}
	cf[1]=st[1];
	for(int i=2;i<=n;i++)
	{
		cf[i]=ton(st[i-1],st[i]);
		if(cf[i]==m)
		{
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);		
	return 0;
}
/*
2 2
99 100 97 98
*/
