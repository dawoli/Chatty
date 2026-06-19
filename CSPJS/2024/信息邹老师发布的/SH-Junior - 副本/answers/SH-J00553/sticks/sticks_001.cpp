#include<bits/stdc++.h>
using namespace std;
int t,n,l,ans;
int main()
{
    freopen ("sticks.in","r",stdin);
    freopen ("sticks.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		ans=0;
		scanf("%d",&n);
		l=n%7;
		if(n==1) printf("-1\n");
		else
		{
		
		if(l==0)
		{
			for(int j=1;j<=n/7;j++) ans=ans*10+8;
			printf("%d\n",ans);
		}
		else
		{
			if(l==1)
			{
				ans=10;
				for(int j=1;j<=n/7-1;j++) ans=ans*10+8;
				printf("%d\n",ans);
			}
			else
			{
				if(n==6) printf("6\n");
				else
				{
					if(l==2)
					{
						ans=1;
						for(int j=1;j<=n/7;j++) ans=ans*10+8;
						printf("%d\n",ans);
					}
					else
					{
						if(l==3 || l==4)
						{
							if(n/7*5>=5-l)
							{
								if(n/7>=5-l) 
								{
									ans=2;
									for(int j=1;j<=5-l;j++) ans=ans*10;
									for(int j=1;j<=n/7-5+l;j++) ans=ans*10+8;
									printf("%d\n",ans);
								}
								else
								{//3
									printf("22\n");
								}
							}
							else
							{
								if(l==3) printf("7\n");
								if(l==4) printf("4\n");
							}
						}
						else
						{
							if(l==5) 
							{
								ans=2;
								for(int j=1;j<=n/7;j++) ans=ans*10+8;
								printf("%d\n",ans);
							}
							else
							{
								if(l==6) 
								{
									ans=6;
									for(int j=1;j<=n/7;j++) ans=ans*10+8;
									printf("%d\n",ans);
							    }
							}
							
						}
					}
				}
			}
			
		}
	    }
	}
//	printf("%d",ans);
	return 0;
}
