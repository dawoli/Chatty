#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[505];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin >> c[i];
		if(s[i-1]!=1) flag=false;
	}
	s=" "+s;
	sort(c+1,c+n+1);
	if(flag){
		int cnt=1;
		for(int i=2;i<=n;i++){
			cnt=cnt*i%mod;
		}
		cout << cnt;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0||s[i]==0){
				cout << 0;
				return 0;
			}
		}
		int cnt=1;
		for(int i=2;i<=n;i++){
			cnt=cnt*i%mod;
		}
		cout << cnt;
		return 0;
	}
	int ans=0;
	int csp=1,res=1;
	for(int i=2;i<=n;i++){
		if(c[i]==c[i-1]) res++;
		else{
			csp*=res;
			res=1;
		}
	}
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[i]||s[i]=='0'){
				cnt++;
			} 
		}
		if(n-cnt>=m){
			ans+=csp;
		} 
	}while(next_permutation(c+1,c+n+1));
	cout << ans;
	return 0;
}
