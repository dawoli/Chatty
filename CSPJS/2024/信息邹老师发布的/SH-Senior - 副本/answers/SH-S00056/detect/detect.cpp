#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,tot,ans,temp,osnum;
int p[100005],overspeed[100005],used[100005],head[10000005];
struct node1{
	int to,nxt,w;
}edge[10000005];
struct node2{
	int d,v,a;
}car[100005];
bool comp(int x,int y){
	return x<y;
}
void add(int u,int v){
	edge[++tot].to=v;edge[tot].nxt=head[u];head[u]=tot;
}
void dfs(int num,int plan,int now){
	if(num==0){
		if(temp==osnum) ans=plan;
		return;
	}
	for(int i=now;i<=m;i++){
		for(int j=head[i];j;j=edge[j].nxt){
			int y=edge[j].to;
			if(used[y]==0){
				temp++;
				used[y]=1;
				edge[j].w=num;
			}
		}
		dfs(num-1,plan,now+1);
		for(int j=head[i];j;j=edge[j].nxt){
			int y=edge[j].to;
			if(used[y]==1&&edge[j].w==num){
				temp--;
				used[y]=0;
				edge[j].w=0;
			}
		}
	}
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		osnum=0;tot=0;ans=0;
		memset(overspeed,0,sizeof(overspeed));
		memset(head,0,sizeof(head));
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&car[i].d,&car[i].v,&car[i].a);
		for(int i=1;i<=m;i++) scanf("%d",&p[i]);
		sort(p+1,p+m+1,comp);
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(car[i].d>p[j]) continue;
				int vv;
				vv=car[i].v*car[i].v+2*car[i].a*(p[j]-car[i].d);
				double vvv;
				vvv=sqrt(vv);
				if(vvv>V*1.0){
					overspeed[i]=1;
					add(j,i);	
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(overspeed[i]==1) osnum++;
		}
		printf("%d ",osnum);
		for(int i=1;i<=m;i++){
	    	memset(used,0,sizeof(used));
	    	temp=0;
	    	dfs(i,i,1);
	    	if(ans>0) break;
        }
		printf("%d\n",m-ans);
	}
	return 0;
}
