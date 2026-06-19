#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[509];
long long ans=1;
int cnt=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			cnt++;
		}
	}
	if(m==n){
		if(cnt!=n){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
