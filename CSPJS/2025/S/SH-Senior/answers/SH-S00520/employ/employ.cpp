#include<bits/stdc++.h>
#define FILE(X) freopen(X".in","r",stdin); freopen(X".out","w",stdout);
#define ll long long
using namespace std;
const int N=520,M=520;const ll mod=998244353;
int n,m;
int s[N];
int c[N];
ll ans=0;

int main() {
	FILE("employ");
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	int s_cnt=0;
	for(int i=0;i<n;i++) {
		char cha_r;
		cin>>cha_r;
		s[i]=cha_r-'0';
		s_cnt+=s[i];
	}
//		cout<<s_cnt<<"\n";
	int no_patience=0;
	for(int i=0;i<n;i++) {
		cin>>c[i];
		if(!c[i]) no_patience++;
	}
//		cout<<no_patience<<"\n";
	if(s_cnt==n&&n-no_patience>=m) {
		ans=1;
		for(int i=1;i<=n;i++) {
			ans*=i;ans%=mod;
		}
	}
	else if(m==1&&s_cnt&&no_patience<n) {
		int fst=0;
		while(s[fst]==0) fst++;
		int cnt=0;
		for(int i=0;i<n;i++) if(c[i]>=fst) cnt++;
		ans=cnt;
		for(int i=1;i<=n-1;i++) {
			ans*=i;ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
