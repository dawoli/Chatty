#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
typedef long long ll;
ll n,m,A[N],a[N],b[N];
string q[200];
void solve(){
	ll x[4];
	ll res=0;
	cin>>x[0]>>x[1]>>x[2]>>x[3];
	for(int i=1;i<=n;i++)a[i]=A[i]^x[i%4];
	for(int i=1;i<=m;i++){
		int k=0;
		while((1<<k)<b[i])k++;
		int ans=0;
		for(int j=b[i]+1;j<=(1<<k);j++)ans+=j;
		ans+=b[i]&5;
		res^=(i*ans);
	}
	cout<<res<<endl;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>A[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	int K=0;
	while((1<<K)<n)K++;
	for(int i=1;i<=K;i++)cin>>q[i];
	int T;whille(T--)solve();
	return 0;
}
