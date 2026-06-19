#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+10,mod=998244353;
int n,m,a[N],tmp;
string s;

int level(int n){
	for(int i=n-1;i>1;--i){
		n*=i%mod;
		n%=mod;
	}
	return n;
}

void solve(){
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i){
		cin>>tmp;
		if(tmp==0) n--;
	}
	cout<<level(n);
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
} 
