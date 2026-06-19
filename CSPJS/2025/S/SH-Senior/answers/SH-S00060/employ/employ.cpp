#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m; 
int a[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	string s;
	bool flag=1;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]!='1'){
			flag=0;
			break;
		}
	}
	
	if(m==n){
		if(flag) cout<<1;
		else cout<<0;
		return 0;
	}
	else if(flag){
		ll ans=0;
		for(int i=m;i<=n;i++){
			ll k=1;
			for(int j=n-m;j<=n;j++){
				k*=1;
				k%=998244353;
			}
			ans+=k;
			ans%=998244353;
		}
		cout<<ans;
	}
	else if(m==1){
		cout<<0;
	}
	return 0;
}


