#include<bits/stdc++.h>
using namespace std;
int n,m,l,x;
int d[100009],v[100009],a[100009];
int p[100009];
void solve() {
	cin>>n>>m>>l>>x;
	long long ans1=0,ans2=0;
	for(int i=1;i<=n;i++) {
		cin>>d[i]>>v[i]>>a[i];
	}
	for(int i=1;i<=m;i++) {
		cin>>p[i];
	}
	if(a[1]==0) {
		for(int i=1;i<=n;i++) {
			if(d[i]<=p[m]&&v[i]>x) ans1++;
		}
		if(ans1==0) cout<<ans1<<" "<<m<<endl;
		else cout<<ans1<<" "<<m-1<<endl;
	}
	else if(a[1]>0) {
		for(int i=1;i<=n;i++) {
			if(d[i]<=p[m]&&(v[i]*v[i]+2*a[i]*(p[m]-d[i]))>x*x) ans1++;
		}
		if(ans1==0) cout<<ans1<<" "<<m<<endl;
		else cout<<ans1<<" "<<m-1<<endl;
	}
	else {
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}
