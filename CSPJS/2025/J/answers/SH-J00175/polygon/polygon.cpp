#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","r",stdout);
	int n;
	int lens=0;
	int max,num=0;
	int a[5001];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
	}	
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			for(int z=j;z<=j+i-1;z++)
			{
				if(a[z]<a[z+1])
				{
					max=a[z+1];
				}				
				else{
					max=a[z];		
				}	
				lens+=a[z];
			} 
		if(lens>2*max) num++;
		}
	}
	printf("%d",num%998244353);
	return 0;
} 
