#include <bits/stdc++.h>
using namespace std;

const int MAXN=5005;
const long long MOD=998244353
long long n,a[MAXN],dp[MAXN];  //dp[i]对于前i根木棍（包括i），最多方案数 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	return 0;
}
