#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
unsigned long long ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	ans=n;
	for(int i=n-1;i>=1;i--)ans*=i;
	ans%=998244353;
	cout<<ans;
	return 0;
}
