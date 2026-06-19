#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[510];
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0){
			cnt+=1;
		}
	}
	if(m>n-cnt){
		cout<<0<<endl;
	}
	else{
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
