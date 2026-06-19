#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string s;
int c[510];
int main(){
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
//		cout<<c[i]<<endl;
		if(c[i]!=0)
			cnt++;
	}
	long long ans=1;
//	cout<<cnt<<endl;
	if(cnt<m){
		cout<<0<<endl;
	}
	else{
		for(int i=m;i>=1;i--){
			ans*=i;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
