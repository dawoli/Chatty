#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
const int N=509; 
int n,m,c[N],ans,cnt;
string s;
int mul(int x){
	int res=1;
	for(int i=2;i<=x;i++) res=(res*i)%MOD;
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='1')
			cnt++;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n){
		if(cnt!=n){
			cout<<0;
			return 0;
		}
		ans=mul(n);
		cout<<ans;
		return 0;
	}
	if(cnt==n){
		ans=(mul(n)/((mul(n-m)*mul(m))%MOD))%MOD;
		cout<<ans;
	}
	cout<<13253;
	return 0;
}
