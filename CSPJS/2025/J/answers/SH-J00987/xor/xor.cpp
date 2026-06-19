#include<bits/stdc++.h> 
using namespace std;
int xor1(int d,int u,int q[])
{
	int s=q[d];
	for(int i=d+1;i<=u;i++)
	{
		s=(s^(q[i]));
	}
	return s;
}
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int newj=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(xor1(i,j,a)==k&&newj<i)
			{
				s++;
				newj=j;
			}
		}
	}
	cout<<s;
	return 0;
}
