#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l[2000010];
vector<int>v[2000010];
int r,c,flag=0;
struct node{
	int nn,mm;
};
vector<node>vv[2000010];
void find(int x,int cnt,int num){
	//cout<<x<<" "<<cnt<<" "<<num<<endl;
	if(num>=r){
		for(int i=cnt+1;i<=min(cnt+k-1,n);i++){
			if(v[x][i]==c){
				flag=1;
				return;
			}
		}
		return;
	}
	for(int i=cnt+1;i<=min(cnt+k-1,n);i++){
		int now=v[x][i];
		for(int j=0;j<vv[now].size();j++){
			if(vv[now][j].nn==x)continue;
			find(vv[now][j].nn,vv[now][j].mm,num+1);
			if(flag)return;
		}
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=200000;i++)vv[i].clear();
		for(int i=1;i<=n;i++){
			v[i].clear();
			scanf("%d",&l[i]);
			for(int j=1;j<=l[i];j++){
				int x;
				scanf("%d",&x);
				v[i].push_back(x);
				vv[x].push_back({i,j-1});
			}
		}
		while(q--){
			
			scanf("%d%d",&r,&c);
			if(r==1){
				int st=0,minn=1e9;
				for(int i=1;i<=n;i++){
					st=0;
					for(int j=0;j<v[i].size();j++){
						if(v[i][j]==1)st=j;
						if(v[i][j]==c&&v[i][j]!=1)minn=min(minn,j-st+1);
					}
				}
				if(minn<=k)printf("1\n");
				else printf("0\n");
			}else{
				flag=0;
				for(int i=1;i<=n;i++){
					for(int j=0;j<v[i].size();j++){
						if(v[i][j]==1)find(i,j,1);
						if(flag)break;
					}
					if(flag)break;
				}
				printf("%d\n",flag);
			}
		}
	}
	return 0;
}
