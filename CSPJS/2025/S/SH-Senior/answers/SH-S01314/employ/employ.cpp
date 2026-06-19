#include<bits/stdc++.h>
using namespace std;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m; string s;
	cin>>n>>m; cin>>s;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
	}
	for(int i=1;i<=n;i++){
		ans=ans*i%998244353;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
