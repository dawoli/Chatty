#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;
int n,k,tmp,s[N],cnt,x;

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>tmp;
		s[i]=s[i-1]^tmp;
	}
	for(int r=1;r<=n;++r){
		for(int l=x+1;l<=r;++l){
			if((s[r]^s[l-1])==k){
				cnt++,x=r;
				break;
			}
		}
	}
	cout<<cnt;
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
