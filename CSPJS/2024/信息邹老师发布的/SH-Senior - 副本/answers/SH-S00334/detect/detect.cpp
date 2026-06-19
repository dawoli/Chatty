#include<bits/stdc++.h>
#define N 100009
using namespace std;
typedef long long ll;
ll n,m,L,V,d[N],v[N],a[N],p[N],nR,ans=0;
bool ok[N];
struct Range{
	ll l,r;
	bool operator<(const Range&re)const{
		return l>re.l||l==re.l&&r<re.r;
	}
} ra[N],rb[N];
bool check(){
	for(ll i=1;i<=nR;i++){
		bool flag=1;
		for(ll j=ra[i].l;j<=ra[i].r;j++)
			if(ok[j]){
				flag=0;
				break;
			}
		if(flag) return 0;
	}
	return 1;
}
void dfs(ll u,ll cnt){
	if(cnt+m-u+1<=ans) return;
	if(u>m){
		if(check()) ans=cnt;
		return;
	}
	ok[u]=0;
	dfs(u+1,cnt+1);
	ok[u]=1;
	dfs(u+1,cnt);
}
void input(){
	scanf("%lld %lld %lld %lld",&n,&m,&L,&V);
	nR=0; ans=0;
	for(ll i=1;i<=n;i++) scanf("%lld %lld %lld",&d[i],&v[i],&a[i]);
	for(ll i=1;i<=m;i++) scanf("%lld",&p[i]); 
}
void solveBF(){
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		bool flag=1;
		for(ll j=1;j<=m;j++){
			if(p[j]<d[i]) continue;
//			printf("%lld\n",v[i]*v[i]+2*a[i]*(p[j]-d[i]));
			if(flag&&v[i]*v[i]+2*a[i]*(p[j]-d[i])>V*V){
				flag=0; ra[++nR].l=j;
				ra[nR].r=m; cnt++;
			}else if(!flag&&v[i]*v[i]+2*a[i]*(p[j]-d[i])<=V*V) ra[nR].r=j-1,flag=1;
			if(v[i]*v[i]+2*a[i]*(p[j]-d[i])<=0) break;
		}
//		printf("\n");
//		printf("[%lld,%lld]\n",ra[nR].l,ra[nR].r);
	}
	printf("%lld ",cnt);
	for(ll i=1;i<=m;i++) ok[i]=1;
	dfs(1,0);
	printf("%lld\n",ans);
}
void solveBFR(){
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		bool flag=1;
		for(ll j=1;j<=m;j++){
			if(p[j]<d[i]) continue;
//			printf("%lld\n",v[i]*v[i]+2*a[i]*(p[j]-d[i]));
			if(flag&&v[i]*v[i]+2*a[i]*(p[j]-d[i])>V*V){
				flag=0; ra[++nR].l=j;
				ra[nR].r=m; cnt++;
			}else if(!flag&&v[i]*v[i]+2*a[i]*(p[j]-d[i])<=V*V) ra[nR].r=j-1,flag=1;
			if(v[i]*v[i]+2*a[i]*(p[j]-d[i])<=0) break;
		}
//		printf("\n");
//		printf("[%lld,%lld]\n",ra[nR].l,ra[nR].r);
	}
	printf("%lld ",cnt);
	if(cnt==0){
		printf("%lld\n",m);
		return;
	}
	sort(ra+1,ra+nR+1);
	ll nUnq=1,rn=ra[1].r;
	for(ll i=2;i<=nR;i++)
		if(ra[i].r<rn){
			rn=ra[i].r;
			ra[++nUnq]=ra[i];
		}
//	printf("%lld ",nUnq);
//	for(ll i=1;i<=nUnq;i++) printf("[%lld,%lld]\n",ra[i].l,ra[i].r);
	ll tot=1;
	rb[1]=ra[1];
	for(ll i=2;i<=nUnq;i++){
		if(ra[i].r>=rb[tot].l) rb[tot].r=ra[i].r;
		else rb[++tot]=ra[i];
	}
	printf("%lld\n",m-tot);
}
void solveR(){
	ans=0;
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		ll l=1,r=m,pos=m+1;
		while(l<=r){
			ll mid=(l+r)/2;
			if(p[mid]>=d[i]){
				pos=mid;
				r=mid-1;
			}else l=mid+1;
		} 
		if(pos==m+1) continue;
		if(a[i]==0){
			if(v[i]>V) ra[++nR]=(Range){pos,m};
		}else if(a[i]>0){
			ll res=m+1;
			l=pos; r=m;
			while(l<=r){
				ll mid=(l+r)/2;
				if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])>V*V){
					res=mid;
					r=mid-1;
				}else l=mid+1;
			}
			if(res<=m) ra[++nR]=(Range){res,m};
		}else{
			if(v[i]<=V) continue;
			ll res=pos-1;
			l=pos; r=m;
			while(l<=r){
				ll mid=(l+r)/2;
				if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])>V*V){
					res=mid;
					l=mid+1;
				}else r=mid-1;
			}
			if(res>=pos) ra[++nR]=(Range){pos,res};
		}
//		printf("\n");
//		printf("[%lld,%lld]\n",ra[nR].l,ra[nR].r);
	}
	printf("%lld ",nR);
	if(nR==0){
		printf("%lld\n",m);
		return;
	}
	sort(ra+1,ra+nR+1);
	ll nUnq=1,rn=ra[1].r;
	for(ll i=2;i<=nR;i++)
		if(ra[i].r<rn){
			rn=ra[i].r;
			ra[++nUnq]=ra[i];
		}
//	printf("%lld ",nUnq);
//	for(ll i=1;i<=nUnq;i++) printf("[%lld,%lld]\n",ra[i].l,ra[i].r);
	ll tot=1;
	rb[1]=ra[1];
	for(ll i=2;i<=nUnq;i++){
		if(ra[i].r>=rb[tot].l) rb[tot].r=ra[i].r;
		else rb[++tot]=ra[i];
	}
	printf("%lld\n",m-tot);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	for(ll i=1;i<=T;i++){
		input();
		if(n<=10&&m<=10)
			solveBF();
		else if(n<=3000&&m<=3000)
			solveBFR();
		else
			solveR();
	}
	return 0;
}


