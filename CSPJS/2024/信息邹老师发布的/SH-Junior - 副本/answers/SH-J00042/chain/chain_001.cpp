#include<bits/stdc++.h>
using namespace std;
int dis[200003];
vector<int> nums[200003],mp[200003];
bool vis[200003];
void dfs(int c){
	if(dis[c]!=0)return;
	for(int i=0;i<mp[c].size();i++){
		int nxt=mp[c][i];
		if(vis[nxt]){
			dis[c]=-1;
			return;
		}
		if(dis[nxt]==-1){
			dis[c]=-1;
			return;
		}else{
			vis[nxt]=true;
			dfs(nxt);
			if(dis[nxt]==-1){
				dis[c]=-1;
				return;
			}else dis[c]=max(dis[c],dis[nxt]+1);
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(vis,false,sizeof(vis));
		memset(dis,0,sizeof(dis));
		int n,k,q;
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			int many;
			scanf("%d",&many);
			for(int j=1;j<=many;j++){
				int tmp;
				scanf("%d",&tmp);
				for(int a=max(0,j-k+1);a<nums[i].size();a++){
					mp[tmp].push_back(nums[i][a]);
				}
				nums[i].push_back(tmp);
			}
		}
		while(q--){
			int r,c;
			scanf("%d%d",&r,&c);
			vis[c]=true;
			if(dis[c]==0)dfs(c);
			if(dis[c]==-1 || dis[c]>=r){
				printf("1\n");
			}else{
				printf("0\n");
			}
		}
	}
	return 0;
}
/*
1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 2
1 4
2 4
3 4
6 6
1 1
7 7
*/
