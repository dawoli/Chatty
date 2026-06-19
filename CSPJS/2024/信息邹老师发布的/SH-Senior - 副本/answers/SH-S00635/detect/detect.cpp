#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
int t;
int n,m,L,v;
struct node{
	int d,v,a;
	node(int ad=0,int av=0,int aa=0){
		d=ad;
		v=av;
		a=aa;
	}
}c[N];
struct seg{
	int l,r;
	seg(int al=0,int ar=0){
		l=al;
		r=ar;
	}
}se[N];
int tot;
int p[N],sum[M],ll[M],dp[M];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		tot=0;
		cin>>n>>m>>L>>v;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=1;i<=L+1;i++){
			sum[i]=0;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			sum[p[i]+1]=1;
		}
		for(int i=0;i<=m;i++){
			dp[i]=0;
			ll[i]=-1;
		}
		for(int i=1;i<=L+1;i++){
			sum[i]=sum[i-1]+sum[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int l,r;
			if(c[i].a>0){
				if(c[i].v>v){
					l=c[i].d,r=L;
				}
				else{	
					double w=(double)((double)v*(double)v-(double)c[i].v*(double)c[i].v)/(double)c[i].a;
					w/=(double)2.0;
					w+=(double)c[i].d;
					w=floor(w)+1;
					int ss=ceil(w);
					l=ss,r=L;
				}
			}
			else if(c[i].a<0){
				if(c[i].v<=v){
					l=-1,r=-1;
				}
				else{
					double w=(double)((double)c[i].v*(double)c[i].v-(double)v*(double)v)/(double)(-c[i].a);
					w/=(double)2.0;
					w+=(double)c[i].d;
					w=ceil(w)-1;
					w=min(w,(double)L);
					int ss=(int)w;
					l=c[i].d,r=ss;
				}
			}
			else{
				if(c[i].v<=v){
					l=-1,r=-1;
				}
				else{
					l=c[i].d,r=L;
				}
			}
			if(l>r){
				continue;
			}
			if(l!=-1 && r!=-1){
				if(sum[r+1]-sum[l]>0){
					se[++tot]=seg(l,r);
					ans++;
				}
			}
		}
		for(int i=1;i<=tot;i++){
			int lx=lower_bound(p+1,p+m+1,se[i].l)-p;
			int rx=upper_bound(p+1,p+m+1,se[i].r)-p-1;
			if(lx>rx)	continue;
			se[i].l=lx,se[i].r=rx;
			se[i].l--;
			ll[se[i].r]=max(ll[se[i].r],se[i].l);
		}
		for(int i=1;i<=m;i++){
			if(ll[i]>-1){
				dp[i]=max(dp[i],dp[ll[i]]+1);
			}
			dp[i]=max(dp[i-1],dp[i]);
		}
		cout<<ans<<" "<<m-dp[m]<<"\n";
	}
	return 0;
}
