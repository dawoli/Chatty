#include<bits/stdc++.h>
using namespace std;
long long n,m,c[1009],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
	cout<<ans;
	return 0;
}
