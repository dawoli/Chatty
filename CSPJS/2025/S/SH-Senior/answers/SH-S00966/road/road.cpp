#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c,cost;
int f[10020];
struct node{
	int u,v,w;
}a[2000010],chs[10010];
bool cmp(node x,node y){
	return x.w<y.w;
}
int get(int x){
	if(f[x]==x)return x;
	return f[x]=get(f[x]);
}
void merge(int x,int y){
	f[get(x)]=get(y);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n;i++)f[i]=i;
	int cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c;
		cost+=c;
		for(int j=1;j<=n;j++){
			cin>>w;
			a[++cnt]={n+i,j,w};
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(get(a[i].u)==get(a[i].v))continue;
		merge(a[i].u,a[i].v);
		cost+=a[i].w;
	}
	cout<<cost;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
