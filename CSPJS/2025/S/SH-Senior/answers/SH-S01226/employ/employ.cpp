#include<bits/stdc++.h>
using namespace std;
int c[505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1;i<=n;i++) {
		cin>>c[i];
	}
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1'){
			cnt++;
		}
	}
	if(cnt<m) {
		cout << 0;
		return 0;
	}
	int ans = 1;
	if(cnt==n||m==n){
		for(int i = 1; i <= n; i++) {
			ans*=i;
			ans%=998244353;
		}
		cout << ans << endl;
		return 0;
	}
	else if(m == 1) {
		sort(c+1,c+n+1);
		int fi;
		for(int i = 0; i < s.size(); i++) {
			if(s[i]=='1'){
				fi=i;
			}
		}
		if(c[1]>fi){
			for(int i = 1; i <= n; i++) {
				ans*=i;
				ans%=998244353;
			}
			cout << ans << endl;
			return 0;
		}
		else{
			int id;
			bool flag = true;
			for(int i = 1; i <= n-1; i++) {
				if(c[i]>fi && flag){
					id=n-i+1;
					flag = false;
				}
				ans*=i;
				ans%=998244353;
			}
			cout << ans*id << endl;
			return 0;
		}
	}
	return 0;
}
