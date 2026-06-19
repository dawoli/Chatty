#include <bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
int d,v,a,l,r,x;
struct rng_info{
	int l,r;
}rng[100005];
bool cmp1(rng_info xx,rng_info yy){
	if(xx.l!=yy.l) return xx.l<yy.l;
	else return xx.r<yy.r;
}
bool cmp2(rng_info xx,rng_info yy){
	return xx.r<yy.r;
}
int cnt,ans;
int p[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	cin>>T;
	while(T--){
		scanf("%d%d%d%d",&n,&m,&L,&V);
		cnt=0;ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d,&v,&a);
			if(a==0){
				if(v>V){
					rng[++cnt].l=d;
					rng[cnt].r=L;
				}
			}else 
			if(a<0){
				if(v>V){
					x=((double)1.0*(V-v)*(V+v)/2/a)+3;
					while(2*a*x<=V*V-v*v) x--;
					rng[++cnt].l=d;
					rng[cnt].r=min(L,d+x);
				}
			}else {
				if(v>V){
					rng[++cnt].l=d;
					rng[cnt].r=L;
				}else{
					x=((double)1.0*(V-v)*(V+v)/2/a)-2;
					while(2*a*x<=V*V-v*v) x++;
					if(d+x<=L){
						rng[++cnt].l=d+x;
						rng[cnt].r=L;
					}
				}
			}
		}
		sort(rng+1,rng+cnt+1,cmp1);
		for(int i=1;i<=m;i++)
			scanf("%d",&p[i]);
		int pos=1;n=0;
		for(int i=1;i<=cnt;i++){
			while(rng[i].l>p[pos]&&pos<=m) pos++;
			if(pos>m) break;
			else 
				if(rng[i].r>=p[pos]) 
				{
					ans++;
					rng[++n].l=rng[i].l;
					rng[n].r=rng[i].r;
				}
		}
		printf("%d ",ans);
		sort(rng+1,rng+n+1,cmp2);
		pos=0,ans=m;p[0]=-1;
		for(int i=1;i<=n;i++){
			if(pos==m) break;
			if(p[pos]<rng[i].l){
				while(p[pos+1]<=rng[i].r) pos++;
				ans--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
