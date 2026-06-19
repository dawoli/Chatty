#include<iostream>
#include<queue>
#include<cstring>
#define debug(x) (cerr<<#x<<':'<<(x)<<endl)
#define endl '\n'
using namespace std;
typedef long long ll;
int const N=100005;
typedef pair<int,int> pii;
int a[N][4];
bool vis[N];
priority_queue<pii,vector<pii>,greater<pii>> pq1,pq2,pq3,pq12,pq13,pq21,pq23,pq31,pq32; // First For Value And Second For ID
void inline clear(priority_queue<pii,vector<pii>,greater<pii>> &p) {
	while(!p.empty()) p.pop();
}
void solve() {
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=n;i++) {
		int maxa=max(a[i][1],max(a[i][2],a[i][3]));
		if(maxa==a[i][1]) ans+=maxa,pq1.push({a[i][1],i}),pq12.push({a[i][1]-a[i][2],i}),pq13.push({a[i][1]-a[i][3],i});
		else if(maxa==a[i][2]) ans+=maxa,pq2.push({a[i][2],i}),pq21.push({a[i][2]-a[i][1],i}),pq23.push({a[i][2]-a[i][3],i});
		else if(maxa==a[i][3]) ans+=maxa,pq3.push({a[i][3],i}),pq31.push({a[i][3]-a[i][1],i}),pq32.push({a[i][3]-a[i][2],i});
	}
	if(pq1.size()>n/2) {
		int cnt=pq1.size();
		while(cnt>n/2) {
			while(!pq12.empty()&&vis[pq12.top().second]) pq12.pop();
			while(!pq13.empty()&&vis[pq13.top().second]) pq13.pop();
			pair<int,int> res={1e5,0};
			if(!pq12.empty()) res=min(res,pq12.top());
			if(!pq13.empty()) res=min(res,pq13.top());
			if(!pq12.empty()&&res==pq12.top()) {
				vis[pq12.top().second]=1;
				ans-=pq12.top().first;
				pq12.pop();
			}
			else if(!pq13.empty()&&res==pq13.top()) {
				vis[pq13.top().second]=1;
				ans-=pq13.top().first;
				pq13.pop();
			}
			--cnt;
		}
	}
	else if(pq2.size()>n/2) {
		int cnt=pq2.size();
		while(cnt>n/2) {
			while(!pq21.empty()&&vis[pq21.top().second]) pq21.pop();
			while(!pq23.empty()&&vis[pq23.top().second]) pq23.pop();
			pair<int,int> res={1e5,0};
			if(!pq21.empty()) res=min(res,pq21.top());
			if(!pq23.empty()) res=min(res,pq23.top());
			if(!pq21.empty()&&res==pq21.top()) {
				vis[pq21.top().second]=1;
				ans-=pq21.top().first;
				pq21.pop();
			}
			else if(!pq23.empty()&&res==pq23.top()) {
				vis[pq23.top().second]=1;
				ans-=pq23.top().first;
				pq23.pop();
			}
			--cnt;
		}
	}
	else if(pq3.size()>n/2) {
		int cnt=pq3.size();
		while(cnt>n/2) {
			while(!pq31.empty()&&vis[pq31.top().second]) pq31.pop();
			while(!pq32.empty()&&vis[pq32.top().second]) pq32.pop();
			pair<int,int> res={1e5,0};
			if(!pq31.empty()) res=min(res,pq31.top());
			if(!pq32.empty()) res=min(res,pq32.top());
			if(!pq31.empty()&&res==pq31.top()) {
				vis[pq31.top().second]=1;
				ans-=pq31.top().first;
				pq31.pop();
			}
			else if(!pq32.empty()&&res==pq32.top()) {
				vis[pq32.top().second]=1;
				ans-=pq32.top().first;
				pq32.pop();
			}
			--cnt;
		}
	}
	cout<<ans<<endl;
	clear(pq1),clear(pq2),clear(pq3),clear(pq12),clear(pq13),clear(pq21),clear(pq23),clear(pq31),clear(pq32);
	memset(vis,0,sizeof vis);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
