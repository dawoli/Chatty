#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll t,n,a[200010],b[200010],ans;
void dfs(int step){
	if (step>n){
		ll cnt=0;
		int last0=0,last1=0;
		for (int i=1;i<=n;i++){
			if (b[i]==0){
				if (a[last0]==a[i]) cnt+=a[i];
				last0=i;
			}else {
				if (a[last1]==a[i]) cnt+=a[i];
				last1=i;
			}
		}
		ans=max(ans,cnt);
		return;
	}
	b[step]=0;
	dfs(step+1);
	b[step]=1;
	dfs(step+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		b[1]=0;
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		dfs(2);
		cout<<ans<<endl;
	}
	return 0;
}
