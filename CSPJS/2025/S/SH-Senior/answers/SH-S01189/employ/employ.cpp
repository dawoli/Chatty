#include<bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
int n,m,a[550],b[550],x[550],c[550],cnt,sss;
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s = " "+s;
	for(int i = 1;i <= n;++i) a[i] = s[i]-'0';
	for(int i = 1;i <= n;++i) cin>>c[i],x[i] = i;
	if(n <= 10){
		long long ans = 0;
		do{
			int sum = 0;
			for(int i = 1;i <= n;++i){
				if(sum >= c[x[i]]) ++sum;
				else if(a[i] == 0) ++sum;
			}
			if(n-sum >= m) ++ans;
		}while(next_permutation(x+1,x+n+1));
		cout<<ans%mod;
		return 0;
	}
	if(m == n){
		bool flag = true;
		for(int i = 1;i <= n;++i){
			if(a[i] == 0) flag = false;
		}
		for(int i = 1;i <= n;++i){
			if(c[i] == 0) flag = false;
		}
		if(flag == false) cout<<0;
		return 0;
	}
	for(int i = 1;i <= n;++i){
		if(a[i] == 1) ++sss;
	} 
	if(sss < m){
		cout<<0;
		return 0;
	}
	long long ans = 1;
	for(int i = 1;i <= n;++i){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
