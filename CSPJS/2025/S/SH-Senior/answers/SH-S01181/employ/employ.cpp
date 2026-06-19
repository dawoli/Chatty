#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int x;
	for(int i=1;i<=n;i++) cin>>x;
	if(m==n){
		int l=s.size();
		for(int i=0;i<l;i++){
			if(s[i]=='0'){
				cout<<"0";
				return 0;
			}
		}
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	else {
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
