#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
using namespace std;
const int N=1e5+5;
const double q=1e-10;
struct tmp{
	int l,r;
}t[N];
struct node{
	double d,v,a;
}c[N];
int n,m,L,v,p[N];
int che(int pos,int a,int v){return sqrt(2*a*pos+v*v);}
bool cmp(tmp x,tmp y){return (x.l==y.l)?(x.r<y.r):(x.l<y.l);
}
void solve(){
	cin>>n>>m>>L>>v;
	
	memset(p,0,sizeof(p));
	rep(i,1,n)c[i].d=c[i].v=c[i].a=0;
	rep(i,1,n)t[i].l=t[i].r=0;
	
	rep(i,1,n)cin>>c[i].d>>c[i].v>>c[i].a;
	rep(i,1,m)cin>>p[i];
	sort(p+1,p+m+1);
	int ans=0;
	
	rep(i,1,n){
		if(c[i].a==0){
			if(c[i].v<=v){
				continue;
			}
			if(p[m]>=c[i].d)ans++;
			int pos=lower_bound(p+1,p+m+1,c[i].d)-p;
			if(p[pos-1]>=c[i].d)pos--;
			if(pos<=m){
				t[i].l=pos,t[i].r=m;
			}
			continue;
		}
		int l=0,r=m;
		if(c[i].a<0){
			if(c[i].v<=v){
				continue;
			}
			l=lower_bound(p+1,p+m+1,c[i].d)-p;
			if(p[l-1]>=c[i].d)l--;
			while(l+1<r){
				int mid=(l+r)>>1;
				if(che(p[mid]-c[i].d,c[i].a,c[i].v)>v)l=mid;
				else r=mid-1;
			}
		}
		if(c[i].a>0){
			l=1,r=m;
			l=lower_bound(p+1,p+m+1,c[i].d)-p;
			while(l+1<r){
				int mid=(l+r)>>1;
				if(che(p[mid]-c[i].d,c[i].a,c[i].v)>v)r=mid;
				else l=mid+1;
			}
			if(che(p[l+1]-c[i].d,c[i].a,c[i].v)>v)l++;
		}
		if(che(p[l]-c[i].d,c[i].a,c[i].v)>v){
			if(c[i].a>0)t[i].l=r,t[i].r=m;
			else
			{
				t[i].l=lower_bound(p+1,p+m+1,c[i].d)-p;
				t[i].r=l;
			}
			ans++;
		}
	}
	cout<<ans<<' ';
	ans=0;
	//rep(i,1,n)cout<<t[i].l<<' '<<t[i].r<<endl;
	sort(t+1,t+n+1,cmp);
	//rep(i,1,n)cout<<t[i].l<<' '<<t[i].r<<endl;
	int pos=1;
	while(t[pos].l==0)pos++;
	int l=-1,r=2e9;
	l=max(l,t[pos].l);
	r=min(r,t[pos].r);
	rep(i,pos,n){
		ans++;
		//cout<<'b'<<i<<endl;
		bool flag=false;
		rep(j,i+1,n){
			//cout<<i<<'a'<<l<<' '<<r<<endl;
			if(!(r<t[i].l||l>t[i].r))
			{
				l=max(l,t[j].l);
				r=min(r,t[j].r);
			}
			else
			{
				l=-1;r=2e9;
				i=j-1;
				flag=true;
				break;
			}
		}
		if(!flag)break;
	}
	cout<<(m-ans)<<endl;
}
signed main(){
	int TEST;
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>TEST;
	while(TEST--){
		solve();
	}
	return 0;
}
