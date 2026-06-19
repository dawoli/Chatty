#include<bits/stdc++.h>
#define Maxn 100000
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int n,m,k;
	bool flag2[Maxn][Maxn];
	bool flag[Maxn][Maxn];
	int ans=1000001;
	int start[Maxn],end[Maxn],cost[Maxn];
	int towncost[Maxn][Maxn];
	int mincosttown[Maxn];
	int mincosttown_total[Maxn];
	int record[Maxn][Maxn];
	bool flag_t=false;
	int mincost[Maxn];
	memset(mincosttown_total,1000001,sizeof(mincosttown));
	memset(flag,false,sizeof(flag));
	memset(flag2,false,sizeof(flag2));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&start[i],end[i],cost[i]);
	}

	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=1+n;j++)
		{
			
			scanf("%d",&towncost[i][j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		flag[start[i]][end[i]] = true;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
		{
			if((flag[i][j] ||flag[j][i])== false){
				flag_t=true;
			}	
		} 
	}
	 
	if(flag_t==false)
	{
		for(int i=1;i<=m;i++)
		{
			mincost[0]+=cost[i];
		}
		printf("%d",&mincost[0]);
	}
	for(int i=1;i<=m;i++)
	{
		
			for(int l=1;l<=k;l++){
				for(int j=1;j<=n-1;j++){
					for(int z=j;z<=j+1;z++)
					{
						if(towncost[l][z]<towncost[l][j]) {
							int tmp=towncost[l][z];
							towncost[l][z] = towncost[l][j];
							towncost[l][j] = tmp;
						}
					}
				}
			}
		
			for(int j=1;j<=k;j++)
			{
				for(int z=1;z<=i;z++)
				{
					mincosttown[j]+=towncost[j][z]+towncost[j][1];
				}
				if(mincosttown[j]<mincosttown_total[j]){
					mincosttown_total[j]=mincosttown[j];
				}
				for(int z=1;z<=i;z++)
				{
					record[j][z]=towncost[j][z];
					flag[j][z]=true;
				}
			}
			for(int l=1;l<=m;l++)
			{
				for(int j=1;j<=k;j++)
				{
					for(int z=1;z<=i;z++){
						if(flag[j][z] == false){
							mincost[i] = mincosttown_total[j]+cost[l]; 
						}
					}
				}
			}
		
	for(int i=1;i<=m;i++)
	{
		if(mincost[i]<ans)
		{
			ans=mincost[i];
		}	
	} 
	printf("%d",ans);
	return 0;
	}
}
