#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int N=0;
int a[100000];
int b[100000];
int c[100000];



int dfs(int x,int c1,int c2,int c3)
{
	if(c1+c2+c3==N+1)	return 0;
	if(c1>N/2||c2>N/2||c3>N/2)	return -100;
	//cout<<c1<<c2<<c3;
	return max(a[x]+dfs(x+1,c1+1,c2,c3),max(b[x]+dfs(x+1,c1,c2+1,c3),c[x]+dfs(x+1,c1,c2,c3+1)));
}




int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		N=n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		int r=dfs(0,0,0,0);
		cout<<r;
		for(int j=0;j<n;j++)
		{
			a[j]=b[j]=c[j]=0;
		}
	}
	fclose(stdin);
	return 0;
}







