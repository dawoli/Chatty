#include<bits/stdc++.h>
using namespace std;
int b[100005][3];
int t;
int n;
int cnt;
int a0,amax;
int max(int b[100005][3],int l)
{
	int big=b[0][l];
	for(int i=0;i<n;i++)
	{
		if(b[i][n]>big)
		{
			big=b[i][n];
			amax=i;
		}
	}
	return big;
}
int cancel(int b[100005][3],int l,int m)
{
	for(int i=m+1;i<n;i++)
	{
		b[i][l]=b[i-1][l];
	}
	b[n-1][l]=0;
}
int main()
{
	int a[100005][3];
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int s=0;s<t;s++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			if(a[i][1]==0&&a[i][2]==0)
			{
				for(int j=0;j<n/2;j++)
				{
					a0=max(a,0);
					cancel(a,0,amax);
					cnt+=a0;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

/*
3
4
4 0 0
3 0 0
5 0 0
3 0 0
*/
