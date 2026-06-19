#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	int x[505];
	cin >> n >> m;
	string s;
	cin >> s;
	bool flg=0;
	for(int i=1; i<=n; ++i){
		cin >> x[i];
		if(x[i]==0){
			flg=1;
		}
	}
	for(int i=1; i<=n; ++i){
		if(s[i]=='0'){
			flg=1;
		}
	}
	if(m==n){
		if(flg==0){
			long long ans=1;
			for(int i=1; i<=n; ++i){
				ans*=i;
				ans%=998244353;
			}
		//	cout << 1 << endl;
			cout << ans << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
	return 0;
} 
