#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=505,MOD=998244353;
int n,m,fs,a[MAXN];
string s;
int qpl(int x){
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=MOD;
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]!='1'){
			fs=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(!fs){
		cout<<qpl(n)<<endl;
		return 0;
	}
}
