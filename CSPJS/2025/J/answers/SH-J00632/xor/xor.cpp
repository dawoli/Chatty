#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,a[500001]={0},h[500001]={0},x[500001]={0};
int dp[500001]={0};
int c(int l)
{
//	printf("%d %d\n",l,as);
    if(l==n+1)
    {
    	return 0;
	}
	if(dp[l]!=-1) return dp[l];
	int as=-1;
		if(x[l]!=0)
	    {
	    	as=c(x[l]+1)+1;
	    }
		as=max(as,c(l+1));
		dp[l]=as;
	return as;
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//printf("%d\n",(3|1)-(3&1));
	for(int i=1;i<=500001;i++)
	{
		h[i]=-1;
		dp[i]=-1;
	}
	scanf("%d %d",&n,&k);
//	printf("llllll\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	//	printf("%d\n",i);
		for(int j=1;j<=i;j++)
		{
			if(h[j]!=k) 
			{
				if(i!=j) h[j]=(h[j]|a[i])-(h[j]&a[i]);
				else
				{
					h[j]=a[i];
				}
				//printf("%d %d = %d\n",j,i,h[j]);
				if(h[j]==k) 
				{
					x[j]=i;
				//	printf("%d %d\n",j,i);
				}
			}
		}
	}
//	printf("llllll\n");
	ans=c(1);
	printf("%d",ans);
	
	
	return 0;
}
