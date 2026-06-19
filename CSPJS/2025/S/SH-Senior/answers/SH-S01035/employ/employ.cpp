#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int c[505];
int vis[505];
string a;
int n,m;
int cnt=0;
void dfs(int ii,int y,int jv){
	if(ii>=n){
		if(y>=m){
			cnt++;
			cnt=cnt%mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			if(jv<c[i]){
				vis[i]=1;
				if(a[ii]-'0'==0){
					dfs(ii+1,y,jv+1);
				}
				else{
					dfs(ii+1,y+1,jv);
				}
				vis[i]=0;
			}
			else{
				vis[i]=1;
				dfs(ii+1,y,jv+1);
				vis[i]=0;
			}
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	int f=0;
	int ff=0;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'==0){
			f=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			ff=1;
		}
	}
	if(m==n){
		if(f==1||ff==1){
			cout<<0;
			return 0;
		}
		else{
			int ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*i;
				ans%=mod;
			}
			cout<<ans;
		}
	} 
	else if(f==0){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		dfs(0,0,0);
		cout<<cnt;
	}
	return 0;
}
