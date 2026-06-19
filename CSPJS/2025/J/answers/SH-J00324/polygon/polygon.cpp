#include <bits/stdc++.h>
#define i64 long long
#define mod 998244353
#define N 5008
using namespace std;
i64 n,ans=0;
i64 a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=i;
	}
	cout<<ans%mod<<endl;
	return 0;
}
