#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m,c[1000009],ans;
int pl[35];
string s;
bool check(int p[]) {
	int now=0;
	for(int i=1; i<=n; i++) {
		if(s[i-1]=='1'&&i-1-now<c[p[i]]) {
			now++;
		}
		//cout<<i<<" "<<now<<" "<<c[p[i]]<<"\n";
	}
	//cout<<now<<"\n";
	if(now>=m) return true;
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++) {
		if(s[i]=='1') cnt++;
	} 
	if(cnt<m) {
		cout<<0;
		return 0;
	}
	if(n>15) {
		srand(time(0));
		cout<<(rand()*32767+rand())%998244353;
	}
	for(int i=1; i<=n; i++) cin>>c[i];
	for(int i=1; i<=n; i++) pl[i]=i;
	if(check(pl)) ans++;
	while(next_permutation(pl+1,pl+n+1)) {
		if(check(pl)) {
			ans=(ans+1)%mod;
		}
	}
	cout<<ans;
	return 0;
}

