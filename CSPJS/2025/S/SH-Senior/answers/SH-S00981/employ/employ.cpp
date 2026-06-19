#include<iostream>
#include<algorithm>
using namespace std;
int n,m,c[505];
string s;
bool vis[505];
long long ans;
void dfs(int x,int l,int sum){
	if(x==n){
		if(sum>=m){
			ans+=1;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(c[i]<=l||s[x]=='0')dfs(x+1,l+1,sum);
			else dfs(x+1,0,sum+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
