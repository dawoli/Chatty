#include <bits/stdc++.h>
using namespace std;
int a[2020];
int b[2020];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,ans=1,ans2=1,s0=0,mod=998244353;
	string s;
	cin >> n >> m >> s;
	s=' '+s;
	for(int i=n;i>=1;i--){
		if(s[i]=='1'){
			b[i]=b[i+1]+1;
		}else{
			b[i]=b[i+1];
			s0++;
		}
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		//cout << "# " << a[i] << ' ' << b[a[i]] << ' ' << s0 << ' ' << i << endl; 
		ans=(ans*(b[a[i]+1]+s0-(n-i)))%mod;
	}
	for(int i=1;i<=n;i++){
		ans2=(ans2*i)%mod;
	}
	
	cout << (ans2-ans+mod)%mod << endl;
	return 0;
} 
