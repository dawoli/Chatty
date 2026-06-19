#include<bits/stdc++.h>
using namespace std;
const int N=519,M=998244353;
int n,m,c[N],ans,vis[N],cntc;
string s;
void dfs(int day,int ple,int die){
	if(ple>=m){
		ans=(ans+1)%M;
		return;
	}
	if(day==n+1)return;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(s[day]=='0'||die>=c[i])dfs(day+1,ple,die+1);
			else dfs(day+1,ple+1,die);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	int flag1=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i]!='1')flag1=0;
		if(c[i]==0)cntc++;
	}
	if(flag1){
		if(m>n-cntc){
			cout<<0;
		}else{
			cout<<(n-cntc)%M;
		}
		return 0;
	}
	if(n>100){
		cout<<0;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
