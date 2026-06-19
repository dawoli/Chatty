#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];int num;int k;
void paixu()
{
	int k;
	for(int i=1;i<=num-1;i++)
	{
		for(int j=1;j<=num-i;j++)
		{
			if(a[j]<a[j+1])
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			}
		}
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
int erfen()
{
	for(int i=1;i<=num;i++)
	{
		if(a[i]==k)
		{
			return i;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	k=a[1];	
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	num=m*n;
	paixu();
	int b=erfen();
	cout<<(b-1)/n+1<<" ";
	if(((b-1)/n+1)%2==1)
	{
		cout<<(b-1)%n+1;
	}
	else
	{
		cout<<n-(b-1)%n;
	}
	return 0;	
}
