#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=998244353;
int n,m,ans=1;
int c;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a==0) c++;
	}
	if(c>n-m) cout<<0;
	else{
	for(int i=1;i<=n;i++){
			ans*=i;
			ans%=N;
		}
		cout<<ans;
	}
	return 0;
}
