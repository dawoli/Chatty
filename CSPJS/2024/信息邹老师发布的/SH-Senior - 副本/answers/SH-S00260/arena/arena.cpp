#include<bits/stdc++.h>
using namespace std;

const int N=100005,N2=131080;
int n,m,ax[N],a[N];
bool d[20][N2];
int c[N],lgu[N],lgd[N];

namespace A {
	int res[N];
	void solve() {
		int ans=0;
		for(int i=1; i<=m; ++i) {
			for(int j=1; j<=c[i]; ++j) res[j]=j;
//			for(int j=1; j<=c[i]; ++j) cout<<a[j]<<" ";
//			cout<<endl;
			for(int j=1; j<=lgu[c[i]]; ++j) {
//				cout<<(1<<(lgu[c[i]]-j))<<":";
				for(int k=1; k<=(1<<(lgu[c[i]]-j)); ++k) {
					int op=(2*k)+d[j][k]-1;
//					cout<<op<<":"<<4*k-1-op<<" "<<d[j][k]<<" ";
					res[k]=(a[res[op]]>=j)?res[op]:res[4*k-1-op];
				}
//				cout<<endl;
			}
			ans^=res[1]*i;
//			cout<<res[1]<<endl;
		}
		cout<<ans<<endl;
	}
}

int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	for(int i=2; i<=N-1; ++i) lgd[i]=lgd[i/2]+1;
	for(int i=2; i<=N-1; ++i) lgu[i]=lgd[i]+1;
	for(int i=1; i<=N-1; i<<=1) --lgu[i];
	cin>>n>>m;
	for(int i=1; i<=n; ++i) cin>>ax[i];
	for(int i=1; i<=m; ++i) cin>>c[i];
	char ctmp;
	for(int i=1; i<=lgu[n]; ++i) {
		for(int j=1; j<=(1<<(lgu[n]-i)); ++j) {
			cin>>ctmp;
			d[i][j]=ctmp-'0';
		}
	}
	int T;
	cin>>T;
	while(T--) {
		int x[4];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1; i<=n; ++i) a[i]=ax[i]^x[i%4];
		A::solve();
	}
	return 0;
}

