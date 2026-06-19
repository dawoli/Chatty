#include<bits/stdc++.h>
using namespace std;
long long n,m,k,s[10005],fa[10005],idx=1,ans,i;
struct node{
	long long from,to,w;
}edge[5000005];
bool cmp(node x,node y){
	return x.w<y.w;	
}
long long find(long long x){
	if(fa[x]==x){
		return x;
	}else{
		return fa[x]=find(fa[x]);
	}
}
bool check(long long x,long long y){
	if(fa[x]==fa[y]||find(x)==find(y)){
		return false;
	}else return true;
}
void merge(long long x,long long y){
	if(find(x)!=find(y)) fa[find(y)]=find(x);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long maxw=-1;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		if(u>v) swap(u,v);
		edge[idx].to=v;
		edge[idx].from=u;
		edge[idx++].w=w;
		maxw=max(maxw,w);
	}
	sort(edge+1,edge+idx,cmp);
	for(long long i=1;i<=n;i++) fa[i]=i;
	long long cnt=1;
	ans=edge[1].w;
	merge(edge[1].to,edge[1].from);
	long long i;
	for(i=2;cnt<n-1;i++){
		if(check(edge[i].to,edge[i].from)){
			ans+=edge[i].w;
			cnt++;
			merge(edge[i].to,edge[i].from);
		}
	}
	idx=i;
	for(long long i=1;i<=k;i++){
		long long c;
		cin>>c;
		for(long long j=1;j<=n;j++){
			cin>>s[j];
			if(c>=maxw) continue;
			for(long long l=1;l<j;l++){
				if(s[l]+s[j]+c>maxw) continue;
				edge[idx].to=j;
				edge[idx].from=l;
				edge[idx++].w=s[l]+s[j]+c;
			}
		}
		sort(edge+1,edge+idx,cmp);
		for(long long j=1;j<=n;j++) fa[j]=j;
		long long cnt=1;
		ans=edge[1].w;
		merge(edge[1].to,edge[1].from);
		long long j;
		for(j=2;cnt<n-1;j++){
			if(check(edge[j].to,edge[j].from)){
				ans+=edge[j].w;
				maxw=max(maxw,edge[j].w);
				cnt++;
				merge(edge[j].to,edge[j].from);
			}
		}
		idx=j;
	}
	cout<<ans<<endl;
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

