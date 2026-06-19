#include<bits/stdc++.h>
using namespace std;
const int N=100009;
struct Node{int l,r;}q[N];
int T,n,m,L,V,ans,cnt,d[N],v[N],a[N],p[N],pos[N];
bool cmp(const Node&x,const Node&y){return x.r<y.r||(x.r==y.r&&x.l<y.l);}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&L,&V),ans=cnt=0;
		for(int i=1;i<=n;++i)scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;++i)scanf("%d",&p[i]);
		for(int i=1;i<=n;++i){
			if(a[i]>0){
				if(v[i]>V){
					int lft=lower_bound(p+1,p+m+1,d[i])-p;
					if(lft<=m)++ans,q[ans].l=lft,q[ans].r=m;
					continue;
				}double x=d[i]+0.5*(V*V-v[i]*v[i])/a[i];
				int lft=upper_bound(p+1,p+m+1,x)-p;
				if(lft<=m)++ans,q[ans].l=lft,q[ans].r=m;
			}else if(a[i]<0){
				if(v[i]<=V)continue;
				double x=d[i]+0.5*(V*V-v[i]*v[i])/a[i];
				int lft=lower_bound(p+1,p+m+1,d[i])-p;
				int rght=lower_bound(p+lft,p+m+1,x)-p;
				if(lft<rght)++ans,q[ans].l=lft,q[ans].r=rght-1;
			}else if(v[i]>V){
				int lft=lower_bound(p+1,p+m+1,d[i])-p;
				if(lft<=m)++ans,q[ans].l=lft,q[ans].r=m;
			}
		}printf("%d ",ans),sort(q+1,q+ans+1,cmp);
		for(int i=1;i<=ans;++i)if(q[pos[cnt]].r<q[i].l)pos[++cnt]=i;
		printf("%d\n",m-cnt);
	}
	return 0;
}
