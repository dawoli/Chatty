#include<bits/stdc++.h>
using namespace std;
int vis[11];
int c[11];
int s[11];
int choose[11];
string str;
int n,m,ans;
void dfs(int u){
	if(u==n+1){
		int sum=0;
		int fail_sum=0;
		for(int i=1;i<=n;i++){
			if(fail_sum>=c[choose[i]]){
				fail_sum++;
				continue;
			}
			if(s[i]==1){
				sum++;
			}
			else{
				fail_sum++;
			}
		}
		if(sum>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			choose[u]=i;
			dfs(u+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=str[i-1]-'0';
	}
	dfs(1);
	cout<<ans;
	return 0;
}
