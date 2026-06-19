#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int mod=998244353;
int a[10000];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ll cnt=1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			cnt=cnt*(i%mod)%mod;
		}
		cout<<cnt;
		return 0;
	}
	cout<<0;
	
	return 0;
}
/*

f[n][m]=f[n-1][m]+f[n-1][m-1]
*/
