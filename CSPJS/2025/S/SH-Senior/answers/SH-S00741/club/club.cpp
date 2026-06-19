#include<bits/stdc++.h>
#define ll long long
#define N 100009
using namespace std;
int n;
priority_queue<ll,vector<ll>,greater<ll>> pq[4];
ll a[N][4],ans;
void solve(){
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	ans=0;
	for(int i=1;i<=n;i++){
		if(a[i][1]>=max(a[i][2],a[i][3])){
			pq[1].push(a[i][1]-max(a[i][2],a[i][3]));ans+=a[i][1];
		}
		else if(a[i][2]>max(a[i][1],a[i][3])){
			pq[2].push(a[i][2]-max(a[i][1],a[i][3]));ans+=a[i][2];
		}
		else{
			pq[3].push(a[i][3]-max(a[i][1],a[i][2]));ans+=a[i][3];
		}
	}
	for(int i=1;i<=3;i++){
		while(pq[i].size()>(n>>1)){
			ans-=pq[i].top();pq[i].pop();
		}
		while(!pq[i].empty())pq[i].pop();
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>T;while(T--)solve();return 0;
}
