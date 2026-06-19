#include<bits/stdc++.h>
using namespace std;
int TTT,n,k,q;
int l[20005][305];
bool ans;
void dfs(int r,int c,int prev,int preid)
{
	if(ans)return;
	if(r<=0){
		if(prev==c)
			ans=true;
		return;
	}
	int i,j,w;
	for(i=1;i<=n;++i)
	{
		if(ans)return;
		if(i==preid)continue;
		for(j=1;j<=l[i][0];++j){
			if(ans)return;
			if(l[i][j]==prev){
				for(w=2;w<=k&&j+w-1<=l[i][0];w++){
					if(ans)return;
					dfs(r-1,c,l[i][j+w-1],i);
				}
				
			}	
		}	
	}
	return;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&TTT);
	while(TTT--){
		scanf("%d %d %d",&n,&k,&q);
		int i,j;
		for(i=1;i<=n;++i){
			scanf("%d",&l[i][0]);
			for(j=1;j<=l[i][0];++j)
				scanf("%d",&l[i][j]);
		}
		int r,c;
		for(i=1;i<=q;++i){
			ans=false;
			scanf("%d %d",&r,&c);
			dfs(r,c,1,-1);
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);		
	return 0;
}
