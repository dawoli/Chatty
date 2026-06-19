#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,d,v,a,s,o,l,r,mid,f,k,x,y,ans;
int p[100010],rr[100010];
struct g{
	int l,r;
}q[100010];
bool cmp1(g x,g y){
	if(x.l!=y.l)
		return x.l<y.l;
	return x.r<y.r;
}
double t;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(p,0,sizeof(p));
		memset(rr,0,sizeof(rr));
		s=0,l=0,r=0,mid=0,f=0,k=0,x=0,y=0,ans=0;
		o=1;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&d,&v,&a);
			if(v>V){
				if(a>=0){
					q[o].l=d;
					q[o].r=L;
					o++;
				}
				else{
					a*=-1;
					t=1;
					t=t*(v-V)/a;
					a*=-1;
					s=t*v+0.5*a*t*t;
					if(sqrt(v*v+2*a*s)==V)
						s--;
					q[o].l=d;
					q[o].r=min(d+s,L);
					o++;
				}
			}
			if(v<=V){
				if(a>0){
					t=1;
					t=t*(V-v)/a;
					s=t*v+0.5*a*t*t;
					if(sqrt(v*v+2*a*s)==V)
						s++;
					if(s+d<=L){
						q[o].l=s+d;
						q[o].r=L;
						o++;
					}
				}
			}
		}
		sort(q+1,q+o,cmp1);
		for(int i=1;i<=m;++i)
			scanf("%d",&p[i]);
		sort(p+1,p+m+1); 
		s=o-1;
		for(int i=1;i<o;++i){
			l=1,r=m,f=1e9;
			while(l<=r){
				mid=(l+r)/2;
				if(p[mid]<q[i].l)
					l=mid+1;
				else{
					f=mid;
					r=mid-1;
				}
			}
			if(p[f]>q[i].r){
				s--;
				k++;
			}
			if(i+k<o){
				q[i].l=q[i+k].l;
				q[i].r=q[i+k].r;
			}
		}
		rr[s+1]=1e9;
		for(int i=s;i>=1;--i){
			rr[i]=min(rr[i+1],q[i].r);
		}
		x=1,y=1;
		ans=0;
		while(x<=m&&y<=s){
			if(x==m||p[x+1]>rr[y]){
				ans++;
				while(q[y].l<=p[x]&&y<=s)
					y++;
				if(y>s)
					break;
			}
			x++;
		}
		printf("%d %d\n",s,m-ans);
	}
	return 0;
} 
