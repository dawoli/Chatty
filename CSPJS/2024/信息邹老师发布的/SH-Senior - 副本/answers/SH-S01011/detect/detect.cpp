#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int t;
int n,m,l,v0;
int d[N],v[N],a[N];
int p[N];
double c[N];
int ans;
queue <int> q[N];
void solve(){
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			if(v[i]>v0){
				for(int j=1;j<=m;j++){
					if(d[i]>p[j]) continue;
					q[i].push(p[j]);
				}
			}
		}
		if(a[i]>0){
			for(int j=1;j<=m;j++){
				if(d[i]*1.0+c[i]>=p[j]||d[i]>p[j]) continue;
				q[i].push(p[j]);
			}
		}
		if(a[i]<0){
			for(int j=1;j<=m;j++){
				if(d[i]*1.0+c[i]<=p[j]||d[i]>p[j]) continue;
				q[i].push(p[j]);
			}
		}
		if(q[i].size()!=0) ans++;
	}
	for(int i=1;i<=n;i++){
		while(q[i].size()) {
			cout<<q[i].front()<<" ";
			q[i].pop();
		}
		cout<<endl;
	}
//	cout<<ans;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>v0;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0) c[i]=(3*3-v[i]*v[i])*1.0/2.0/a[i];
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		solve();
	}
	return 0;
}
