#include<bits/stdc++.h>
using namespace std;
const int N=100009,M=100009;
int T,n,m,L,V,d[N],v[N],a[N],p[M];
bool A=true;	// ai=0
void solveA(){
	int ans=0;
	for(int i=1;i<=n;++i)ans+=v[i]>V&&p[m]>=d[i];
	cout<<ans<<' ';
	if(ans)cout<<m-1<<'\n';
	else cout<<m<<'\n';
}
void solve(){
	solveA();
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;++i){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0)A=false;
		}
		for(int i=1;i<=m;++i)cin>>p[i];
		if(A)solveA();
		else solve();
	}
	return 0;
}

