#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("emlpoy.in","r",stdin);
	freopen("emlpoy.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	long long int ans=1;
	cin>>ans;
	for (int i=0;i<n;++i){
		cin>>ans;
	}
	ans=1;
	for (int i=1;i<=n;++i){
		 ans*=(long long int)i;
		 if(ans>998244353) ans = ans % 998244353;
	}
	printf("%lld",ans);
	
	fclose(stdout);
	fclose(stdin);
	return 0;
}
