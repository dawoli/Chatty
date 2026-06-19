#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long t,n,m,L,V,d[100010],v[100010],a[100010],p[100010],ans1,ans2,pmax;
struct Node{
	long long lt,rt;
}node[100010];

bool cmp(Node x,Node y){
	return x.rt<y.rt;
}

long long min(long long x,long long y){
	return x<y ? x : y;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for(long long i=0;i<n;i++) scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
		for(long long i=0;i<m;i++) scanf("%lld",&p[i]);
		ans1=0;
		ans2=0;
		pmax=-1;
		p[m]=L+1;
		p[m+1]=L+2;
		for(long long i=0;i<n;i++){
			if(a[i]==0){
				if(v[i]<=V){
					node[i].lt=L+1,node[i].rt=L+1;
				}
				else node[i].lt=d[i],node[i].rt=L;
			}
			else if(a[i]>0){
				long long csinx=(V*V-v[i]*v[i])/(2*a[i]);
				if(csinx+d[i]+1<=L){
					node[i].lt=csinx+d[i]+1,node[i].rt=L;
				}
				else node[i].lt=L+1,node[i].rt=L+1;
			}
			else{
				if(v[i]<=V){
					node[i].lt=L+1,node[i].rt=L+1;
				}
				else{
					long long csinx=ceil(((long double)V*V-v[i]*v[i])/(2*a[i]));
					node[i].lt=d[i],node[i].rt=min(d[i]+csinx-1,L);
				}
			}
		}
		sort(node,node+n,cmp);
		for(int i=0;i<n;i++){
			if(pmax>node[i].lt){
				ans1++;
				continue;
			}
			long long bc=upper_bound(p,p+m+2,node[i].rt)-p-1;
			if(p[bc]<node[i].lt||p[bc]>node[i].rt||bc>=m) continue;
			pmax=p[bc];
			ans1++,ans2++;
		}
		printf("%lld %lld\n",ans1,m-ans2);
	}
	return 0;
} 
