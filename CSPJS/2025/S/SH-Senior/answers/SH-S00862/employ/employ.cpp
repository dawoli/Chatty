#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c[600],vis[600],ans=0,n,m;
string s;
void dfs(int x,int sum,int mn){
	if(x==n+1){
		if(sum>=m) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]!=0) continue;
		if(mn>=c[i]||s[x-1]=='0'){
			vis[i]=1;
			dfs(x+1,sum,mn+1);
			vis[i]=0;
		}
		else{
			vis[i]=1;
			dfs(x+1,sum+1,mn);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int flag=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0') flag=1;
	}
	int flag2=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) flag2=1;
	}
	if(n<=100){
		memset(vis,0,sizeof(vis));
		ans=0;
		dfs(1,0,0);
		cout<<ans;		
		return 0;
	}
	if(m==n){
		if(flag==1||flag2==1){
			cout<<"0";
		}
		else{
			int sum=1;
		    for(int i=1;i<=n;i++){
			    sum=sum%mod*i%mod;
		    }
		    cout<<sum;
		}
		return 0;
	}
	if(flag==0){
		int sum=1;
		for(int i=1;i<=n;i++){
			sum=sum%mod*i%mod;
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
