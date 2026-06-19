#include<bits\stdc++.h>
using namespace std;
int n,m,c[550];
string s;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int nn=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)nn--;
	}
	n=nn;
	if(n==m){
		for(int i=0;i<=s.size();i++){
			if(s[i]==0){
				cout<<0;
				return 0;
			}
			int ans=1;
			for(int j=1;j<=n;j++){
				ans*=j;
				ans%=mod;
			}
			cout<<ans;
			return 0;
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
