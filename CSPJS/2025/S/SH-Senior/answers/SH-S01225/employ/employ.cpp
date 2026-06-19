#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;bool vis[505];
string s;const long long mod=998244353;
long long c[505],ne[505];
void count(){
	int wei,yi,fq;//未录取和已录取
	wei=yi=fq=0;int len=s.size();
	for(int i=0;i<len;i++) {
		if(fq+wei>=ne[i+1]) {
			fq++;continue;	
		}
		if(s[i]==49) yi++;
		else wei++;
		if(yi>=m) {
			ans=(ans+1)%mod;
			return ;
		}
	}
	return ;
}
void qpl(int cnt,int zz) {
	if(cnt==n){
		count();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) {
			vis[i]=1;
			ne[zz]=c[i];
			qpl(cnt+1,zz+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	qpl(0,1);
	cout<<ans;
	return 0;
}
