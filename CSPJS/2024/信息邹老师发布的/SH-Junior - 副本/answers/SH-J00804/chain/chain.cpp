#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
using namespace std;
const int N=2e3+5;
const int M=2e5+5;
int n,k,q,l[N],t,r,c;
int s[N][N];
map<int,int> h[N],f[N],p[N];

bool work(){
	rep(i,1,n){
		int t1=p[i][1],t2=p[i][c];
		while(t1&&t2){
			if(t2>t1&&t2-t1+1<=k)return true;
			if(t1<t2)t1=f[i][t1];
			else t2=f[i][t2];
		}
	}
	return false;
}
void solve(){
	memset(l,0,sizeof(l));
	memset(s,0,sizeof(s));
	cin>>n>>k>>q;
	rep(i,1,n)h[i].clear(),f[i].clear(),p[i].clear();
	rep(i,1,n){
		cin>>l[i];
		rep(j,1,l[i]){
			cin>>s[i][j];
			t=s[i][j];
			if(!h[i][t])p[i][t]=j;
			f[i][h[i][t]]=j;
			h[i][t]=j;
		}
	}
	rep(i,1,q){
		cin>>r>>c;
		if(r<=1) cout<<work()<<'\n';
		else cout<<0<<'\n';
	}
}
signed main(){
	int TEST;
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>TEST;
	while(TEST--)
		solve();
	return 0;
}
