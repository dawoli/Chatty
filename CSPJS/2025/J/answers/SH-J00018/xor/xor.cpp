#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005]={0},ans=0;
bool b[1000005]={0};
int xo(int i,int j)
{
	if(b[j])
	{
		return -1;
	}
	int m=a[j];
	for(int l=j+1;l<j+i;l++)
	{
		if(b[l])
		{
			return -1;
		}
		m=m xor a[l];
	}
	return m;
}
void se(int i,int j)
{
	for(int l=j;l<j+i;l++)
	{
		b[l]=1;
	}
}
int main()
{
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n-i+1;j++)
		{
			if(xo(i,j)==k)
			{
				ans++;
				se(i,j);
				
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
