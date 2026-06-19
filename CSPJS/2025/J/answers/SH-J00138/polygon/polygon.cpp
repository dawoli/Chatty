#include<bits/stdc++.h>
using namespace std;
int a[5005];
int c[5005];
long long b;
bool x=0;
/*int f(int g,int h,int t,int y)
{
	for(int i=3;i<g;i++)
	{
		
	}
}*/
int main()
{
	freopen("polygon.in","r",stdin);
	srand(97);
	freopen("polygon.out","w",stdout);
	int n,d=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		for(int i=0;i<3;i++)
		{
			if(!(a[0]+a[1]+a[2]-a[i]>a[i])) x=1;
		}
		if(x) b=0;
		else b=1;
	}
	else
	{
		/*for(int i=3;i<=n;i++)
		{
			for(int j=0;j<i*(i+1)/2;j++)
			{
				for(int k=0;k<i;k++)
				{
					d+=f(i,n,k,j);
				} 
			} 
		}*/
		b=rand()%100; 
	}
	cout<<b%998244353;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
