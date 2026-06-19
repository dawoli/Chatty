#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	if(m==1 || m==n){
		cout<<0;
		return 0;
	}
	else{
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				if(i+1==m){
					long long ans=n;
					for(int i=n-1;i>=1;i--){
						ans*=i;
						ans=ans%998244353;
					}
					cout<<ans;
				}
				else cout<<0;
				return 0;
			}
		}
	}
	return 0;
}
