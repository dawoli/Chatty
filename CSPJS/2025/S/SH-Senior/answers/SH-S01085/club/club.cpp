#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=1e5+10;
int n,c[N];
int x[N],y[N],z[N];
int f(int b) {
	if(x[b]>max(y[b],z[b]))
		return 1;
	if(y[b]>max(x[b],z[b]))
		return 2;
	if(z[b]>max(x[b],y[b]))
		return 3;
	if(x[b]==y[b]){
		if(c[1]<=c[2]) return 1;
		else  return 2;
	}
	if(x[b]==z[b]){
		if(c[1]<=c[3]) return 1;
		else return 3; 
	}
	if(y[b]==z[b]){
		if(c[2]<=c[3]) return 2;
		else return 3;
	}
//	else return 1;
}
void solve() {
	cin>>n;
	int ans=0;
	priority_queue<pii>q;
	for(int i=1; i<=n; i++) {
		cin>>x[i]>>y[i]>>z[i];
		int mx=max({x[i],y[i],z[i]});
		int mn=min({x[i],y[i],z[i]});
		ans+=mn;
		q.push({mx-mn,i});
	}
	c[1]=c[2]=c[3]=n/2;int cnt=0;
	while(q.size()) {
		cnt++;
		if(cnt>50) break;
		pii t=q.top();
		q.pop();
		int id=t.second;
//		cout<<id<<" "<<f(id)<<"\n";
		if(c[f(id)]) {
//			cout<<id<<" "<<f(id)<<" "<<ans<<"\n";
			c[f(id)]--;
			ans+=t.first;
			
		} else {
//			cout<<"!!!!!!!!!!!!!!!\n";
			queue<pii>qq;
			if(f(id)==1){
				for(int i=1;i<=n;i++)
					x[i]=0;
				qq.push({abs(y[id]-z[id]),id});
				while(q.size()){
					t=q.top();q.pop();
					id=t.second;
					qq.push({abs(y[id]-z[id]),id});
				}
			}else if(f(id)==2){
				for(int i=1;i<=n;i++)
					y[i]=0;
				qq.push({abs(x[id]-z[id]),id});
				while(q.size()){
					t=q.top();q.pop();
					id=t.second;
					qq.push({abs(x[id]-z[id]),id});
				}
			}else{
				for(int i=1;i<=n;i++)
					z[i]=0;
				qq.push({abs(x[id]-y[id]),id});
				while(q.size()){
					t=q.top();q.pop();
					id=t.second;
					qq.push({abs(x[id]-y[id]),id});
				}
			}
			while(qq.size()){
				t=qq.front();qq.pop();
				q.push({t.first,t.second});
			}
		}
	}
	cout<<ans<<"\n";
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio;
//	cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
