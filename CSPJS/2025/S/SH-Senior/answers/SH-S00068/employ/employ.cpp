#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int pati[510];
//int read(){
//	int x = 0,f = 1;
//	char c = getchar();
//	while(c<'0' and c>'9'){
//		if(c == '-')f=-1;
//		c = getchar();
//	}
//	while(c>='0' and c<='9'){
//		x = x*10+c-'0';
//		c = getchar();
//	}
//	return x*f;
//}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("employ3.in","r",stdin);
//	freopen("employ.out","w",stdout);
	bool flag=1;
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='1')flag = 0;
	}
	for(int i=1;i<=n;i++)cin>>pati[i];
	if(flag){
		int res=1;
		for(int i=n;i>=n-m+1;i--)res = (res*i)%MOD;
		cout<<res;
	}
	else cout<<0;
	return 0;
}
