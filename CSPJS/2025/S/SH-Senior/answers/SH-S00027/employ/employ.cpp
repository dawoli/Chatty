#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=505,mod=998244353;
int n,m,c[N],a[N],ans;
string s;

bool check(){
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			return false;
		}
	}
	return true;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[i]=i;
	}
	if(n<=10){
		do{
			int rf=0;
			for(int i=1;i<=n;i++){
				if(s[i-1]=='0'||rf>=c[a[i]]){
					rf++;
				}
			}
			if(n-rf>=m) ans=(ans+1)%mod;
		}while(next_permutation(a+1,a+n+1));
		cout<<ans;
		return 0;
	}
	if(check()){
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
