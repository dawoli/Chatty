#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int n,m,ans,c[N],d[N];
string s;
bool employ(){
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(cnt>=c[d[i]]||s[i-1]=='0')++cnt;
		if(cnt>n-m)return 0;
	}return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)cin>>c[i];
	sort(c+1,c+n+1);
	for(int i=1;i<=n;++i)d[i]=i;
	while(1){
		ans=(ans+employ())%MOD;
		bool ok=1;
		for(int i=1;i<=n;++i)if(d[i]!=n+1-i){ok=0;break;}
		if(ok)break;
		else next_permutation(d+1,d+n+1);
	}cout<<ans;
	return 0;
}
