#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,a,b,c;
void solve(){
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++)cin>>a>>b>>c;
	for(int i=1;i<=m;i++)cin>>a;
	cout<<n<<" "<<m<<"\n";
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;cin>>t;
	while(t--)solve();
}
