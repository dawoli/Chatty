#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back
using namespace std;
#define debug(x) (cerr<<#x": "<<x<<endl)
#define int ll

const int N=1e5+5;
int n,m,L,V;
int d[N],v[N],a[N],p[N];
int l[N],r[N];
int cl(int x,int y){return (x+y-1)/y;}
vector<pii> ii;
void work(){
	int i;
	cin>>n>>m>>L>>V;
	
	for(i=0;i<=n+1;i++) d[i]=v[i]=a[i]=l[i]=r[i]=0;
	for(i=0;i<=m+1;i++) p[i]=0;
	ii.clear();
	
	for(i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
	for(i=1;i<=m;i++) cin>>p[i];
	L++;
	int cnt=0;
	for(i=1;i<=n;i++){
		if(a[i]>0){
			r[i]=L;
			if(v[i]>V) l[i]=d[i];
			else l[i]=min(L,d[i]+cl(V*V-v[i]*v[i]+1,2*a[i]));
		}
		else if(a[i]==0){
			if(v[i]>V) l[i]=d[i];
			else l[i]=L;
			r[i]=L;
		}
		else{
			if(v[i]<=V) l[i]=r[i]=L;
			else l[i]=d[i],r[i]=min(L,d[i]+(v[i]*v[i]-V*V-1)/(-2*a[i]));
		}
		int l1,r1;
		l1=lower_bound(p+1,p+m+1,l[i])-p;
		r1=upper_bound(p+1,p+m+1,r[i])-p-1;
		if(l1<=r1) cnt++,ii.pb(l1,r1);
	}
	sort(ii.begin(),ii.end(),[](pii x,pii y){return x.se<y.se;});
	int ans=0,rr=0;
	for(auto p:ii){
		if(p.fi>rr) rr=p.se,ans++;
	}
	cout<<cnt<<' '<<m-ans<<'\n';
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _;cin>>_;while(_--) work();
	return 0;
}
