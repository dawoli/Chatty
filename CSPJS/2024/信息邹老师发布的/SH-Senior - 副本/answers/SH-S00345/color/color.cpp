#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int T;
int n,a[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=15){
		int ans=0;
		for(int i=0;i<(1<<n);i++){
			int r=0,b=0,sum=0;
			for(int j=1;j<=n;j++){
				int bit=(i>>(j-1)&1);
				if(bit==1){
					if(a[j]==a[r]) sum+=a[j];
					r=j;
				}else{
					if(a[j]==a[b]) sum+=a[j];
					b=j;
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans<<'\n';
		return ;
	}
	cout<<0<<'\n';
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}
