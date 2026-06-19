#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5+9;

ll t, n, a[N][4];

void input(){
	cin>>n;
	for(ll i=1; i<=n; i++)
		for(ll j=1; j<=3; j++)
			cin>>a[i][j];
}

void solve1(){
	ll ans=0;
	for(ll i=1; i<=3; i++)
		for(ll j=1; j<=3; j++)
			if(j!=i) ans = max(ans, a[1][i]+a[2][j]);
	cout<<ans<<'\n';
}

struct node{
	ll vl, id;
	bool operator < (const node&a)const{
		return vl>a.vl;
	}
}w[4];
priority_queue<node> q[4];
ll cnt[4], ans;
ll bomb=0;

void solve(){
	for(ll i=1; i<=n; i++){
		for(ll j=1; j<=3; j++) w[j] = (node){a[i][j], j};
		sort(w+1, w+4);
		ll id1 = w[1].id;
		if(cnt[id1]+1<=n/2){
			if(bomb==0) q[id1].push((node){w[1].vl-w[2].vl});
		//	cout<<i<<' '<<w[2].vl-w[1].vl<<endl;
			ans+=w[1].vl;
			cnt[id1]++;
		}
		else{
			bomb=1;
			node tp = q[id1].top();
			if(tp.vl<w[1].vl-w[2].vl){
				q[id1].pop();
				q[id1].push((node){w[1].vl-w[2].vl});
				ans+=(-tp.vl+w[1].vl);
			}
			else
				ans+=w[2].vl;
		}
	}
	cout<<ans<<'\n';
}
void csh(){
	ans=0; bomb=0;
	for(ll i=1; i<=3; i++) cnt[i]=0;
	for(ll i=1; i<=3; i++)
		while(!q[i].empty()) q[i].pop();
}
bool a_0(){
	for(ll i=1; i<=n; i++)
		if(a[i][2]!=0||a[i][3]!=0) return 0;
	return 1;
}
ll z[N];
void solve2(){
	for(ll i=1; i<=n; i++) z[i] = a[i][1];
	sort(z+1, z+n+1);
	ans=0;
	for(ll i=n; i>=n/2+1; i--) ans+=z[i];
	cout<<ans<<'\n';
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin>>t;
	while(t--){
		csh();
		input();
		if(n==2) solve1();
		else if(a_0()) solve2();
		else solve();
	}
	
	return 0;
}
