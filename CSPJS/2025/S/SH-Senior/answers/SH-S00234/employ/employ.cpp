#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MD=998244353;
	ll dp[505];
	bool vis[505];
	ll a[505],n,m,ans;
	string s;
void dfs(int x,int fl){
	if(x>n){
		if(n-fl>=m)++ans;
	}
	for(int i=1;i<=n;++i)if(!vis[i]){
		if(fl>=a[i]||s[x-1]=='0')
		++fl;
		vis[i]=1;
		
		dfs(x+1,fl);
		
		vis[i]=0;
		if(fl>=a[i]||s[x-1]=='0')
		--fl;
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==n){string s;cin>>s;
		for(int i=0;i<n;++i){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		for(int i=1,x;i<=m;++i){
			cin>>x;
			if(!x){
				cout<<0;
				return 0;
			}
		}
		long long ans=1;
		for(int i=2;i<=m;++i)ans=ans*i%MD;
		cout<<ans;
		return 0;
	}
	cin>>s;
	for(int i=1;i<=n;++i)cin>>a[i];
	dfs(1,0);cout<<ans;
	/*
	if(m==1){
		string s;cin>>s;
		int ky=-1;
		for(int i=0;i<n;++i)if(s[i]=='1'){
			ky=i;
			break;
		}if(ky==-1){cout<<0; return 0;}
		ll AA=0,BB=0,madd=1145141919;
		for(int i=1,x;i<=n;++i){
			cin>>x;if(x<=ky)++AA;
			if(x>ky){if(x<madd){
			
				madd=x;BB=1;
			}else if(x==madd){
				++BB;
			}}
		}
		
		cout<<BB<<"??";
		ll ans=BB;
		for(ll i=n-1;i>1;--i)ans=(ans*i)%MD;
		cout<<ans;
		return 0;
	}*/
	return 0;
}
