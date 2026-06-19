#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int n,m;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum=n*m;
	int h,l;
	
	for(int i=1;i<=sum;i++)
	{
		cin>>a[i];
	}
	
	int c=a[1];
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++)
	{
		if(a[i]==c)
		{
			if(i%n==0)
			{
				h=i/n;
			}
			else
			{
				h=i/n+1;
			}
			l=i%n;
			if(l==0)
			{
				l=n;
			}
			if(h%2==0)
			{
				l=n-l+1;
			}
			cout<<h<<' '<<l;
		}
	}
	return 0;
}

