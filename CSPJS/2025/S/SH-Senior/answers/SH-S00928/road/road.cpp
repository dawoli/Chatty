#include<bits/stdc++.h>
using namespace std;

int n,m,k,nn,cnt,fa[10104],c[16],vis[16],sum,ans;

struct fay{
	int u,v,w;
}wa[1000104];

bool cmp(fay x,fay y){
	return x.w<y.w;
}

int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}

void merge(int x,int y){
	fa[get(x)]=get(y);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	nn=n;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int uu,vv,ww; cin>>uu>>vv>>ww;
		wa[i].u=uu;wa[i].v=vv;wa[i].w=ww;
	}

	cnt=m;
	for(int i=1;i<=k;i++){
		int cc;cin>>cc;
		c[nn+i]=cc;
		for(int j=1;j<=n;j++){
			int ww; cin>>ww;
			cnt++;
			wa[cnt].u=nn+i; wa[cnt].v=j; wa[cnt].w=ww+cc;
		}
	}
	sort(wa+1,wa+cnt+1,cmp);
	
	for(int i=1;i<=cnt;i++){
		int uu=wa[i].u,vv=wa[i].v,ww=wa[i].w;
		if(get(uu)!=get(vv)){
			if(uu<=n){
				ans+=ww;
				merge(uu,vv);
			}else if(vis[uu]){
				ans+=ww;
				ans-=c[uu];
				merge(uu,vv);
			}else{
				vis[uu]=1;
				ans+=ww;
				merge(uu,vv);
			}
		}
	}
	cout<<ans;
	
	
	fclose(stdin);
	fclose(stdout);
}
