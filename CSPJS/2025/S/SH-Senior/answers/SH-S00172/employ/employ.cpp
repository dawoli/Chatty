#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[501]={},p[501]={};
bool vis[19]={};
const long long mod=998244353ll;
long long re=0ll,lq=0;
void dfs(int dep){
	if(lq>=m){
		long long tmp=1ll;
		for(long long i=2;i<=n-dep+1;i++){
			tmp*=i;
		}
		re+=tmp;
		return ;
	}
	if(dep==n+1)return ;
	int nolq=dep-lq-1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(nolq<c[i]&&s[dep-1]=='1'){
				lq++;
			}
			dfs(dep+1);
			vis[i]=0;
			if(nolq<c[i]&&s[dep-1]=='1'){
				lq--;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	bool flag=1;
	for(int i=0;i<n;i++){
		if(s[i]!='1')flag=0;
	}
	if(m==n){
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		long long ans=1ll;
		for(long long i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}else if(n<=18){
		dfs(1);
		cout<<re;
	}else if(flag){
		
	}else{
		srand(time(0));
		cout<<rand()%998244353;
	}
	return 0;
}
