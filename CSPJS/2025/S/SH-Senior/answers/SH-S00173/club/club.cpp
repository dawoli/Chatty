#include<bits/stdc++.h>
#define Maxn 100001
using namespace std;
int Maxnum(int a,int b,int c)
{
	if(a>b>c || a>c>b) return a;
	else if(b>a>c||b>c>a) return b;
	else if(c>a>b||c>b>a) return c; 
	 
}
int secondMaxJudge(int a,int b,int c)
{
	if(a>b>c||c>b>a) return b;
	else if(c>a>b||b>a>c) return a;
	else if(a>c>b||b>c>a) return c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	int n;
	int record[Maxn];
	int a[Maxn][4];
	int max[Maxn];
	int ans=0;
	int anum=0,bnum=0,cnum=0;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			max[i] = Maxnum(a[i][1],a[i][2],a[i][3]);	
		}
		for(int i=1;i<=n;i++)
		{
			if(max[i] == a[i][1])
			{
				anum++;	
			} 
			else if(max[i] == a[i][2]){
				bnum++;
			}
			else if(max[i] == a[i][3]){
				cnum++;
			}
		}
		if(anum<(n/2)&&bnum<(n/2)&&cnum<(n/2))
		{
			for(int i=1;i<=n;i++)
			{
				ans+=max[i];
			}	
		} 
		else{
			for(int i=1;i<=n-1;i++)
			{
				if(i=1){
					record[i] = i;
				}
				for(int j=i;j<=n;j++){
					if(max[j]>max[i])
					{
						int tmp=max[i];
						max[i] = max[j];
						max[j] = tmp;
							
					} 
				}
			}
			for(int i=1;i<=(n/2);i++)
			{
				ans+=max[i];
				record[i] = -1;
			} 
			for(int i=1;i<=n;i++)
			{
				if(record[i]>=0)
				{
					for(int j=n/2+1;j<=n;j++)
					{
						ans+=secondMaxJudge(a[record[j]][1],a[record[j]][2],a[record[j]][3]);	
					} 
				}	
			}
		}
		printf("%d",ans);
	}		
} 
