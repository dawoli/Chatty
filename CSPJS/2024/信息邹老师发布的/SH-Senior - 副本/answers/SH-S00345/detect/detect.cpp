#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pa pair<int,int>
#define fi first
#define se second
#define mp make_pair
const int N=1e6+5;
int T,n,m,L,V,p[N];
struct car{
	int d,v,a;
}a[N];
vector<pa> q;
int fd(int k,int typ){
	int l=1,r=m;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(p[mid]>k) r=mid;
		else if(p[mid]<k) l=mid;
		else return mid;
	}
	if(p[l]==k) return l;
	if(p[r]==k) return r;
	return (typ?l:r);
}
int fl(int aa,int bb){
	int l=0,r=aa;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(mid*bb>=aa) r=mid-1;
		else l=mid;
	}
	return l;
}
int ce(int aa,int bb){
	int l=1,r=aa;
	while(l<r){
		int mid=(l+r)>>1;
		if(mid*bb>aa) r=mid;
		else l=mid+1;
	}
	return l;
}
void solve(){
	while(q.size()) q.pop_back();
	cin>>n>>m>>L>>V;
	int a1=0,a2=m;
	L++;
	int f0=0,f1=0,f2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].d>>a[i].v>>a[i].a;
		a[i].d++;
		if(a[i].a==0) f0=1;
		if(a[i].a>0) f1=1;
		if(a[i].a<0) f2=1;
	}
	for(int i=1;i<=m;i++){
		cin>>p[i];
		p[i]++;
	}
	if((f0)&&(!f1)&&(!f2)){
		for(int i=1;i<=n;i++){
			if(a[i].v>V&&a[i].d<=p[m]){
				a1++;
			}
		}
		cout<<a1<<' '<<m-(a1!=0)<<'\n';
		return ;
	}
	if((!f0)&&(f1)&&(!f2)){
		for(int i=1;i<=n;i++){
			if(a[i].v>V&&a[i].d<=p[m]){
				a1++;
			}else{
				int x=ce((V*V-a[i].v*a[i].v),(2*a[i].a));
				if(x+a[i].d<=p[m]){
					a1++;
				}
			}
		}
		cout<<a1<<' '<<m-(a1!=0)<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		int s=0,t=-1;
		if(a[i].a==0){
			if(a[i].v>V){
				s=a[i].d;
				t=L;
			}
		}else if(a[i].a<0){
			if(a[i].v>V){
				s=a[i].d;
				int x=fl(-(V*V-a[i].v*a[i].v),-(2*a[i].a));
				t=min(s+x,L);
			}
		}else{
			if(a[i].v>V){
				s=a[i].d;
				t=L;
			}else{
				int x=ce((V*V-a[i].v*a[i].v),(2*a[i].a));
				if(x+a[i].d<=L){
					s=x+a[i].d;
					t=L;
				}
			}
		}
		if(s<=t){
			int l=fd(s,0),r=fd(t,1);
			if(l>r) continue;
			q.push_back(mp(l,r));
			a1++;
		}
	}
	sort(q.begin(),q.end());
	int xx=0;
	for(auto x:q){
		if(x.fi>xx){
			a2--;
			xx=x.se;
			if(xx==L) break;
		}
	}
	cout<<a1<<' '<<a2<<'\n';
	return ;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}
