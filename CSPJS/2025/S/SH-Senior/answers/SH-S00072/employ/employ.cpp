#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,c[505];
long long ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ans*=c[i];
		ans%=MOD;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
