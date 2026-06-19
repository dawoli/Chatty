#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,pair<int,int> > tu;
#define M 1000114
#define N 10114
tu edg2[M*2];
set<tu> s;
ll b[11][N]; 
ll c[11];
int f[N+11];
int n,k;
int fd(int u) {
	if(f[u]==u) return u;
	return f[u]=fd(f[u]);
}
//ll op;
ll krus(int cnt2) {
	for(int i=1;i<=n+k;i++) {
		f[i]=i;
	}
	int cnt=0;
	ll ans=0;
	for(multiset<tu>::iterator it=s.begin();it!=s.end();it++) {
		tu np=*it;
		int tmpu=fd(np.second.first);
		int tmpv=fd(np.second.second); 
		//op++;
		if(tmpu==tmpv) continue;
		f[tmpu]=tmpv;
		cnt++;
		ans+=np.first;
		if(cnt==cnt2-1) return ans;
	}
	return ans;
}
ll dfs(int u,int cnt2) {
	if(u==k+1) {
		return krus(n+cnt2);
	}
	ll ans1=dfs(u+1,cnt2);
	for(int i=1;i<=n;i++) s.insert(make_pair(b[u][i],make_pair(i,n+u)));
	//op+=n;
	ll ans2=dfs(u+1,cnt2+1)+c[u];
	for(int i=1;i<=n;i++) {
		s.erase(make_pair(b[u][i],make_pair(i,n+u)));
	}
	//op+=n;
	return min(ans1,ans2);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	int m;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>edg2[i].second.first>>edg2[i].second.second>>edg2[i].first;
		s.insert(edg2[i]);
	}
	bool fl=true;
	for(int j=1;j<=k;j++) {
		cin>>c[j];
		if(c[j]) fl=false;
		bool fl2=false;
		for(int i=1;i<=n;i++) {
			cin>>b[j][i];
			if(not(b[j][i])) fl2=true;
		}
		if(not(fl2)) fl=false;
	}
	//op=0;
	if(fl) {
		for(int j=1;j<=k;j++) {
			for(int i=1;i<=n;i++) {
				s.insert(make_pair(b[j][i],make_pair(i,n+j)));
			}
		}
		cout<<krus(n+k)<<"\n";
		return 0;
	}
	cout<<dfs(1,0)<<"\n";
	//cout<<op<<"\n";
	return 0;
} 
