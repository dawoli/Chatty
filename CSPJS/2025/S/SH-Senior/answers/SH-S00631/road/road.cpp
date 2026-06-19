#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,fa[10005],ans,b,c;
struct node {
	int u,v,w;
}a[10005];
ll Find(int x) {
	return fa[x]==x?fa[x]:fa[x]=Find(fa[x]);
}
void Union(int x,int y) {
	//int fx=Find(x),fy=Find(y);
	fa[x]=y;
}
bool cmp(node x,node y) {
	return x.w<y.w;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==0) {
		for(int i=1;i<=n;i++) {
			fa[i]=i;
		}
		for(int i=1;i<=m;i++) {
			scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
		}
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++) {
			int fx=Find(a[i].u),fy=Find(a[i].v);
			//printf("fx=%d fy=%d\n",fx,fy);
			if(fx==fy) continue;
			else {
				Union(fx,fy),ans+=a[i].w;
				//printf("father=%d\n",fa[fx]);
				int ff=Find(a[i].u);
				//printf("ff=%d\n",ff);
			}
		}
		printf("%lld\n",ans);
	} else {
		for(int i=1;i<=n;i++) {
			fa[i]=i;
		}
		for(int i=1;i<=m;i++) {
			scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
		}
		for(int i=1;i<=k;i++) {
			scanf("%lld",&c);
			for(int j=1;j<=n;j++) {
				scanf("%lld",&b);
				if(i!=j) a[++m].u=i,a[m].v=j,a[m].w=b;
			}
		}
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++) {
			int fx=Find(a[i].u),fy=Find(a[i].v);
			//printf("fx=%d fy=%d\n",fx,fy);
			if(fx==fy) continue;
			else {
				Union(fx,fy),ans+=a[i].w;
				//printf("father=%d\n",fa[fx]);
				int ff=Find(a[i].u);
				//printf("ff=%d\n",ff);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
/*

*/
