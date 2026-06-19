#include<bits/stdc++.h>
using namespace std;
int a[60],n,cnt;
int main()
{
	freopen("poker.in","w",stdin);
	freopen("poker.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x,y;
		cin>>x>>y;
		if(x=='C')
		{
			if(y=='A')
			{a[1]=1;continue;}
			if(y=='T')
			{a[10]=1;continue;}
			if(y=='J')
			{a[11]=1;continue;}
			if(y=='Q')
			{a[12]=1;continue;}
			if(y=='K')
			{a[13]=1;continue;}
			a[y-48]=1;
			continue;
		}
		if(x=='S')
		{
			if(y=='A')
			{a[14]=1;continue;}
			if(y=='T')
			{a[23]=1;continue;}
			if(y=='J')
			{a[24]=1;continue;}
			if(y=='Q')
			{a[25]=1;continue;}
			if(y=='K')
			{a[26]=1;continue;}
			a[y+13-48]=1;
			continue;
		}
		if(x=='H')
		{
			if(y=='A')
			{a[27]=1;continue;}
			if(y=='T')
			{a[36]=1;continue;}
			if(y=='J')
			{a[37]=1;continue;}
			if(y=='Q')
			{a[38]=1;continue;}
			if(y=='K')
			{a[39]=1;continue;}
			a[y+26-48]=1;
			continue;
		}
		if(x=='D')
		{
			if(y=='A')
			{a[40]=1;continue;}
			if(y=='T')
			{a[49]=1;continue;}
			if(y=='J')
			{a[50]=1;continue;}
			if(y=='Q')
			{a[51]=1;continue;}
			if(y=='K')
			{a[52]=1;continue;}
			a[y+39-48]=1;
			continue;
		}
	}
	for(int i=1;i<=52;i++)
		if(a[i]!=1)
			cnt++;
	cout<<cnt;
	return 0;
}

