#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int N=1e5+7;
int t;
int n,m,L,V;
int d[N],v[N],a[N];
int p[N];
int sum[N*10];
int l[N],r[N],c[N],g[N];
struct edge{int l,r;}e[N];
bool cmp(edge a,edge b){return a.r<b.r;}
int cnt=0;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)
			l[i]=r[i]=c[i]=g[i]=0;
		cnt=0;
		for(int i=1;i<=1e6;i++)
			sum[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",d+i,v+i,a+i);
			if(a[i]>0){
				int chao=floor(1.*(V*V-v[i]*v[i])/(2*a[i]))+1;
				if(chao<=0)
					c[i]=1,l[i]=d[i],r[i]=L;
				else{
					int cd=chao+d[i];
					if(cd>L)
						c[i]=0;
					else
						c[i]=1,l[i]=cd,r[i]=L;
				}
			}else if(a[i]==0){
				if(v[i]<=V)
					c[i]=0;
				else
					c[i]=1,l[i]=d[i],r[i]=L;
			}else{
				int chao=ceil(1.*(V*V-v[i]*v[i])/(2*a[i]))-1;
				if(chao<0)
					c[i]=0;
				else{
					int cd=chao+d[i];
					if(cd>L)
						c[i]=1,l[i]=d[i],r[i]=L;
					else
						c[i]=1,l[i]=d[i],r[i]=cd;
				}
			}
		}
		for(int i=1;i<=m;i++)
			scanf("%d",p+i),sum[p[i]]=1;
		for(int i=1;i<=1e6;i++)
			sum[i]+=sum[i-1];
		int ans1=0;
		for(int i=1;i<=n;i++)
			if(c[i])
				ans1+=(!!(sum[r[i]]-sum[l[i]-1])),
				g[i]=(!!(sum[r[i]]-sum[l[i]-1]));
		printf("%d ",ans1);
		for(int i=1;i<=n;i++)
			if(g[i])
				e[++cnt]={l[i],r[i]};
		sort(e+1,e+cnt+1,cmp);
		int tot=0,ans=m;
		for(int i=1;i<=cnt;i++){
			if(p[tot]<=e[i].r&&p[tot]>=e[i].l)
				continue;
			while(tot<=m&&p[tot]<=e[i].r)
				++tot;
			--tot;
			ans--;
		}
		printf("%d\n",ans);
	}
}
