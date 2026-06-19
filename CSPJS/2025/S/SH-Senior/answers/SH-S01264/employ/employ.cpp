#include <bits/stdc++.h>
using namespace std;

unsigned long long ans=0;
unsigned long long mod=998244353;
unsigned long long n,m,c[1005],s[1005],cs[1005];
long long j(unsigned long long x){
	if(j==0){
		return 0;
	}
	unsigned long long ans=1;
	for(unsigned long long i=1;i<=x;i++){
		ans=(ans*i)%mod;
	}
	return ans;
}
unsigned long long check(){
	unsigned long long l=0,bad=0;
	for(unsigned long long i=0;i<n;i++){
		if(s[i]==1&&cs[i]>bad){
			l++;
		} else {
			bad++;
		}
	//	cout<<"l="<<l<<" bad="<<bad<<endl;
	}
	if(l>=m){
		return 1;
	}
	return 0;
}
unsigned long long vis[1005];
void dfs(unsigned long long depth){
	if(depth==n){
//		for(unsigned long long i=0;i<n;i++){
//			cout<<cs[i]<<" ";
//		}
		if(check()){
			ans=(ans+1)%998244353;
		}
		return ;
	}
	for(unsigned long long i=0;i<n;i++){
		if(vis[i]==0){
			cs[depth]=c[i];
			vis[i]=1;
			dfs(depth+1);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ2.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool isA=true;
	string str;
	cin>>str;
	for(unsigned long long i=0;i<n;i++){
		s[i]=str[i]-'0';
		if(s[i]==0){
			isA=false;
		}
	}
	unsigned long long ppp=0;
	for(unsigned long long i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0){
			ppp++;
		}
	}
	if(isA){
		unsigned long long mp=n-ppp;
		if(mp>=m){
		//	cout<<"mp="<<mp<<endl;
			cout<<j(mp)%mod;
		} else {
			cout<<0<<endl;
		}
		return 0;
	}
	dfs(0);
	cout<<(ans+mod)%mod<<endl;
	return 0;
}
