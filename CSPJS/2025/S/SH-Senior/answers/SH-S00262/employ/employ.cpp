#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[505];
	cin>>n>>m;
	string s;
	cin>>s;
	long long ans=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		ans*=(n-i+1);
			
	}
	ans%=998244353;	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

