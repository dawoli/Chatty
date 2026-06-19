#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100009;
const int L=1000009;
ll n,m,lmax,vmax,d[N],v[N],a[N],p[N];
int nxt[L];
struct Node{
	ll x,y;
}c[N];
bool cmp(const Node&A,const Node&B){
	if(A.y!=B.y) return A.y<B.y;
	return A.x<B.x;
}
bool ok(int u,int point){
	ll vnow2=v[u]*v[u]+2*a[u]*(p[point]-d[u]);
	if(vnow2>vmax*vmax) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>lmax>>vmax;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		int now=m+1;
		int ans1=0;
		for(int i=lmax;i>=1;i--){
			if(i<=p[now-1]) now--;
			nxt[i]=now;
		}
		for(int i=1;i<=n;i++){
			if(a[i]>=0){
				int l=nxt[d[i]],r=m,la=m+1;
				while(l<=r){
					int mid=(l+r)/2;
					if(ok(i,mid)) la=mid,r=mid-1;
					else l=mid+1;
				}
				if(la!=m+1) ans1++,c[i]=(Node){la,m};
				else c[i]=(Node){m+2,m+1};
			}else{
				int l=nxt[d[i]];
				if(!ok(i,l)){
					c[i]=(Node){m+2,m+1};
					continue;
				}
				ans1++;
				c[i].x=l;
				int r=m,lb=l;
				while(l<=r){
					int mid=(l+r)/2;
					if(ok(i,mid)) lb=mid,l=mid+1;
					else r=mid-1;
				}
				c[i].y=lb;
			}
		} 
		int ans2=0;
		sort(c+1,c+n+1,cmp);
		int nowp=-1;
		for(int i=1;i<=n;i++){
			if(c[i].y>m) break;
			if(c[i].x<=nowp) continue;
			ans2++;
			nowp=c[i].y;
		}
		cout<<ans1<<" "<<m-ans2<<endl;
	} 
	return 0;
} 
