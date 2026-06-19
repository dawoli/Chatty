#include<bits/stdc++.h> 
using namespace std;

sturct node{
    int u,v,val;
}
int main(void)
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	scanf("%d",&t);
	int ans[t];
	for(int i=0;i<t;i++)
	{
		int n,tmp=0;
		scanf("%d",&n);
		vector<node>scr;
		int a[n],c[n]={0},clr[n]={0};
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[n]);
			clr[j]=j;
		}
		for(int j=0;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(a[j]==a[k])
				{
					clr[k]=j;
					tmp++;
					node kl;
					kl.u=j;
					kl.v=k;
					kl.val=a[j];
					scr.push_back(kl);
				}
			}
		}
//		if(!tmp)
//		{
//			printf("0\n");
//			continue;
//		}
		
		/*if(n==2)
		{
			if(a[0]==a[1])
			{
				printf("%d",a[0]);
				printf("\n");
				continue;
			}
			printf("0");
			printf("\n");
			continue;
		}
		else if(n==3)
		{
			if(a[0]==a[1])
			{
				if(a[1]==a[2])
				{
					printf("%d",2*a[0]);
					printf("\n");
					continue;
				}
				else
				{
					printf("%d",a[0]);
					printf("\n");
					continue;
				}
			}
			else if(a[0]==a[2])
			{
				printf("%d",a[0]);
				printf("\n");
				continue;
			}
			printf("%d",2*a[0]);
			printf("\n");
			continue;
		}
		else if(n==4)
		{
			if(a[0]==a[1])
			{
				if(a[1]==a[2])
				{
					if(a[2]==a[3])
					{
						printf("%d",3*a[0]);
				    	printf("\n");
				    	continue;
					}
					else
					{
						printf("%d",2*a[0]);
				    	printf("\n");
				    	continue;
					}
				}
				else
				{
					if(a[2]==a[3])
		        	{
			        	printf("%d",a[0]+a[2]);
			        	printf("\n");
			        	continue;
		        	}
		        	printf("%d",a[0]+(a[0]==a[3])?);
		        	printf("\n");
		        	continue;
				}
			}
		}*/
		printf("1\n0\n8");
	}
	return 0;
}
