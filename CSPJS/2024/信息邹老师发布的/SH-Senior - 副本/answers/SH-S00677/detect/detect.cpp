#include<bits/stdc++.h>
#define For(i,a,b) for(ll i=(a),endi=(b);i<=endi;++i)
#define foR(i,a,b) for(ll i=(a),endi=(b);i>=endi;--i)
#define N 100009
typedef long long ll;
using namespace std;
ll T;
ll n,m,L,V;
ll pos;
ll ans,ans2;
ll d[N],v[N],a[N];
ll p[N];
ll num[N];
ll idn;
ll j;
bool flag;
bool f;
ll lowbit(ll x) {
	return x&(-x);
}
vector<ll> t[N];
void solveBF() {
//	For(i,1,m)
//		cout<<p[i]<<' ';
//	cout<<'\n';
	For(i,1,n) {
		flag=false;
		pos=lower_bound(p+1,p+m+1,d[i])-p;
//		cout<<i<<' '<<pos<<'\n';
		For(j,pos,m) {
			if(a[i]==0) {
				if(v[i]>V) {
					if(!flag) {
						ans++;
						flag=true;
					}
					t[i].push_back(j);
				}
			} else if(a[i]>0) {
				if(p[j]>(ll)(d[i]+(double)(V*V-v[i]*v[i])*1.00/(2*a[i]))) {
					if(!flag) {
						ans++;
						flag=true;
					}
					t[i].push_back(j);
				}
			} else {
				if(p[j]<(ll)(d[i]+(double)(V*V-v[i]*v[i])*1.00/(2*a[i]))) {
					if(!flag) {
						ans++;
						flag=true;
					}
					t[i].push_back(j);
				}
			}
		}
//		cout<<i<<' '<<ans<<'\n';
	}
	cout<<ans;
//	For(i,1,n) { 
//		For(j,0,t[i].size()-1)
//			cout<<t[i][j]<<' ';
//		cout<<'\n'; 
//	} 
	For(i,0,(1<<n)-1) {
		j=i;
		idn=0;
		fill(num+1,num+n+1,0);
		while(j!=0) {
			num[++idn]=log(lowbit(j))/log(2)+1;
			j-=lowbit(j);
		}
//		For(i,1,idn)
//			cout<<num[i]<<' ';
//		cout<<'\n';
		f=true;
		For(j,1,n) {
			flag=false;
			if(t[j].empty()) continue;
//			cout<<j<<'\n';
			for(auto pp:t[j]) {
				For(i,1,idn) 
					if(pp==num[i]) {
						flag=true;
						break;
					}
				if(flag)
					break;
			}
			if(!flag) {
				f=false;
				break;
			}
		}
		if(f) ans2=max(ans2,n-idn);
	}
	cout<<' '<<ans2<<'\n';
	For(i,1,n)
		t[i].clear();
}
bool isa0() {
	For(i,1,n)
		if(a[i]!=0)
			return false;
	return true;
}
void solvea0() {
	For(i,1,n) {
		pos=lower_bound(p+1,p+m+1,d[i])-p;
		if(pos!=m+1&&v[i]>V)
			ans++;
	}
	cout<<ans<<' ';
	if(ans==0) cout<<m<<'\n';
	else cout<<m-1<<'\n';
}
void solveab() {
	For(i,1,n) {
		pos=upper_bound(p+1,p+m+1,(ll)(d[i]+(V*V-v[i]*v[i])*1.0/(2*a[i])))-p;
		if(pos!=m+1)
			ans++;
	}
	cout<<ans<<' ';
	if(ans==0) cout<<m<<'\n';
	else cout<<m-1<<'\n';
}
bool isab() {
	For(i,1,n)
		if(a[i]<=0)
			return false;
	return true;
}
void solve() {
	ans=0;
	ans2=0;
	cin>>n>>m>>L>>V;
	For(i,1,n) 
		cin>>d[i]>>v[i]>>a[i];
	For(i,1,m)
		cin>>p[i];
	if(n<=20)
		solveBF();
	else if(isa0())
		solvea0();
	else if(isab())
		solveab();
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
		solve();
	return 0;
}

