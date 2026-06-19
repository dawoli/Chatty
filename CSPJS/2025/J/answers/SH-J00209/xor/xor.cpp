#include<bits/stdc++.h>
//inclue<bits/extc++.h>
using namespace std;
long long n,k,qz[500009],t[5000009],a[500009],lastp=-1,ans;
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=5000000;i++) t[i]=-1e9;
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]^a[i];
		if(t[qz[i]^k]+1>lastp) ans++,lastp=i;
		t[qz[i]]=i;
		//cout<<ans<<' '<<qz[i]<<' '<<lastp<<'\n';
	}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long T=1;//cin>>T;
	while(T--) solve();
}
//subscribe tasho11y in bilibili(in luogu)!!! 
//S rp++
//AK at 10:36 
