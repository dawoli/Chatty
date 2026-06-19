#include<iostream>
#include<algorithm>
#define debug(x) (cerr<<#x<<':'<<(x)<<endl)
#define endl '\n'
using namespace std;
typedef long long ll;
int const N=505;
ll const MOD=998244353;
string S;
int c[N],s[N],p[N];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	cin>>S;
	for(int i=1;i<=n;i++) s[i]=S[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0;
	do {
		int refuse=0,pass=0;
		for(int i=1;i<=n;i++) {
			if(refuse>=c[p[i]]||!s[i]) refuse++;
			else pass++;
		}
		if(pass>=m) ans++;
	} while(next_permutation(p+1,p+n+1));
	cout<<ans<<endl;
	return 0;
}

