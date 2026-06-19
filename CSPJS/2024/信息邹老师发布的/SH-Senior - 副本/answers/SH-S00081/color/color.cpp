#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+999,A=1e6+999;
int n;
ll a[N],f[A],mx,tg,now;
void solve(){
	memset(f,-0x3f3f3f,sizeof(f));
	mx=tg=now=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		now=mx;
		now=max(f[a[i]]+tg+a[i],now);
		if(a[i]==a[i-1]){
			mx+=a[i];
			tg+=a[i];
		}
		mx=max(mx,now);
		f[a[i-1]]=max(f[a[i-1]],now-tg);
	}
	cout<<mx<<'\n';
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin>>T;
	while(T--) solve();
	return 0;
}