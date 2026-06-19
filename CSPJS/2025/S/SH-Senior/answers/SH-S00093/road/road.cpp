#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,f[10005],cnt,c[15],a[15][10005],cnt1;
long long ans,num;
struct node{
	int u,v,w;
}e1[1000005],e2[10005],e3[1100005];
bool vis[15];
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	f[find(x)]=find(y);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void dfs(int step){
	if(step>k){
		num=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		for(int i=1;i<=m;i++){
			e3[++cnt]=e1[i];
		}
		for(int i=1;i<=k;i++){
			if(vis[i]){
				for(int j=1;j<=n;j++){
					if(i==j){
						num+=a[i][j];
					}
					else{
						e3[++cnt]={i,j,a[i][j]};
					}
				}
				num+=c[i];
				//printf("%d ",c[i]);
			}
		}
		sort(e3+1,e3+cnt+1,cmp);
		cnt1=0;
		for(int i=1;i<=cnt;i++){
			if(find(e3[i].u)!=find(e3[i].v)){
				num+=e3[i].w;
				merge(e3[i].u,e3[i].v);
				cnt1++;
				//printf("(%d,%d,%d)",e3[i].u,e3[i].v,e3[i].w);
			}
			if(cnt1==n-1){
				break;
			}
			
		}
		ans=min(ans,num);
		//printf("%d\n",num);
		return;
	}
	vis[step]=true;
	dfs(step+1);
	vis[step]=false;
	dfs(step+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e1[i].u,&e1[i].v,&e1[i].w);
	}
	sort(e1+1,e1+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(e1[i].u)!=find(e1[i].v)){
			ans+=e1[i].w;
			merge(e1[i].u,e1[i].v);
			e2[++cnt]=e1[i];
			//printf("(%d,%d,%d)",e2[cnt].u,e2[cnt].v,e2[cnt].w);
		}
		if(cnt==n-1){
			break;
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	//printf("%d\n",ans);
	dfs(1);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
