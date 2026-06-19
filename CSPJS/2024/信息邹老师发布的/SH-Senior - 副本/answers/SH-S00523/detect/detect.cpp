#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define re register
using namespace std;
const int N=1e5+5;
ll T,n,m;
ll L,V;
ll d[N],v[N],a[N];
ll p[N];
ll l[N],r[N];
ll ans,anss;
pii pa[N];
bool cmp(pii x,pii y){
	return x.se==y.se?x.fi<y.fi:x.se<y.se;
}

inline int lowe(ll x){
	int l=1,r=m+1;
	while(l<r){
		int mid=l+((r-l)>>1);
		if(p[mid]<x){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	return l;
}
inline int uppe(ll x){
	int l=1,r=m+1;
	while(l<r){
		int mid=l+((r-l)>>1);
		if(p[mid]<x){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	if(p[l]==x)return l+1;
	return l;
}

inline ll read(){
	ll x=0;int t=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-')t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*t;
}
// fc /W detect.out detect5.ans
//clock_t st,ed;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	T=read();
	while(T--){
//		if(T==10)st=clock();
		ans=0;anss=0;
		n=read();
		m=read();
		L=read();
		V=read();
		for(re int i=1;i<=n;i++){
			d[i]=read();
			v[i]=read();
			a[i]=read();
		}
		for(re int i=1;i<=m;i++){
			p[i]=read();
		}
		int qwq,qaq;
		for(re int i=1;i<=n;i++){
			if(a[i]>0){
				if((V*V-v[i]*v[i])/(a[i]<<1)+1ll+d[i]>L)continue;
				if(v[i]>V)l[i]=d[i];
				else l[i]=(V*V-v[i]*v[i])/(a[i]<<1)+1ll+d[i];
				r[i]=L+1;
//				qwq=lower_bound(p+1,p+m+1,l[i])-p;
//				qaq=upper_bound(p+1,p+m+1,r[i])-p-1;
				qwq=lowe(l[i]);
				qaq=uppe(r[i])-1;
				if(qwq<=qaq)pa[++ans]=mp(qwq,qaq);
			}
			else if(a[i]==0){
				if(v[i]>V){
					l[i]=d[i];
					r[i]=L;
//					qwq=lower_bound(p+1,p+m+1,l[i])-p;
					qwq=lowe(l[i]);
					if(qwq<=m)pa[++ans]=mp(qwq,m);
				}
			}
			else{
				if(v[i]<=V)continue;
				l[i]=d[i];
				if((v[i]*v[i]-V*V)%((-a[i])<<1)==0){
					r[i]=d[i]+(v[i]*v[i]-V*V)/((-a[i])<<1)-1;
				}
				else r[i]=d[i]+(v[i]*v[i]-V*V)/((-a[i])<<1);
//				qwq=lower_bound(p+1,p+m+1,l[i])-p;
//				qaq=upper_bound(p+1,p+m+1,r[i])-p-1;
				qwq=lowe(l[i]);
				qaq=uppe(r[i])-1;
				if(qwq<=qaq)pa[++ans]=mp(qwq,qaq);
			}
		}
		int lst=-1;
		sort(pa+1,pa+ans+1,cmp);
		for(re int i=1;i<=ans;i++){
			if(pa[i].fi>lst){
				anss++;
				lst=pa[i].se;
			}
		}
		cout<<ans<<' '<<m-anss<<'\n';
	}
//	ed=clock();
//	cout<<"10*1e5 Time:"<<(double)(ed-st)<<"ms";
	return 0;
}
