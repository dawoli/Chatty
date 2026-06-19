#include<bits/stdc++.h>
#define int long long
#define rint register int
using namespace std;

int n,m;
int s[510];

int find(int k){
	int sum = 1;
	for(int i = 1;i<=k;i++){
		sum *= i;
	}
	return sum;
}

signed main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin >> n >> m;
	bool flag = false;
	for(int i = 1;i<=n;i++){
		int k;
		scanf("%1lld",&k);
		s[i] = k;
		if(k == 0) flag = true;
	}
	if(!flag){
		int ans = 1;
		for(int i = 1;i<=l;i++){
			ans *= i;
			ans %= mod;
		}
		cout << ans;
	}else if(m == n){
		cout << 0 << endl;
	}
	return 0;
}
