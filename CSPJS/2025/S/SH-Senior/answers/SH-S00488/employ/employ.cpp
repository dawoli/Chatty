#include<bits/stdc++.h>
#define mod 998244353LL
//Ren5Jie4Di4Ling5%
//1111111111
//5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 
using namespace std;
int n,m,ans=0;
string s;
int c[502],q[15],vis[502];
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'||cnt>=c[q[i]]) cnt++;
	}
	return n-cnt>=m;
}
void dfs(int dep){
	if(dep==n+1){
		if(check()) ans++;
		return; 
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		q[dep]=i;
		vis[i]=1;
		dfs(dep+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s="1"+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int flag=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			flag=0;
			break;
		}
	}
	if(flag){
		long long sum=1;
		for(long long i=2;i<=n;i++){
			sum=(sum*i)%mod;
//			cout<<sum<<" ";
		}
		cout<<sum<<endl;
		return 0;
	}
	if(m==n){
		cout<<0<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
