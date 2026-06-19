#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int fa[1000009];
struct node{
	int u,v,w;
}a[1000009];
bool cmp(node x,node y){
	if(x.w<y.w) return true;
	return false;
}
int ffa(int x){
	if(fa[x]==x) return x;
	else return fa[x]=ffa(fa[x]);
}
void mrg(int x,int y){
	int o=ffa(x);
	int p=ffa(y);
	fa[ffa(x)]=ffa(y);
	fa[ffa(y)]=ffa(x);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=m+1;i<=m+k;i++){
		int x;cin>>x;
		for(int j=1;j<=n;j++){
			cin>>a[i].w;
			a[i].u=j;a[i].v=i+n-m;
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m+k;i++){
		if(ffa(a[i].u)!=ffa(a[i].v)){
			mrg(a[i].u,a[i].w);
			mrg(a[i].w,a[i].u);
			ans+=a[i].w;
//			for(int j=1;j<=n;j++){
//				cout<<fa[j]<<" ";
//			}
//			printf("u=%d,v=%d,w=%d,ffax=%d,ffay=%d\n",a[i].u,a[i].v,a[i].w,ffa(a[i].v),ffa(a[i].u));
		}
	}
//	cout<<"---------"<<ffa(3)<<" "<<ffa(4)<<"\n";
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
