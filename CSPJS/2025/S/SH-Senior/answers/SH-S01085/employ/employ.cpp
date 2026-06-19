#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,mod=998244353;
int n,m,a[N],b[N];
int c[N],vis[N],ans;
string s;
void dfs(int st){
	if(st>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
//			cout<<c[i]<<" "<<a[c[i]]<<" "<<cnt<<"\n";
			if(a[c[i]]<=cnt||s[i]=='0'){
				cnt++;
			}
		}
		if(cnt<=n-m) ans++;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;c[st]=i;
		dfs(st+1);vis[i]=0;
	}
}
void solve(){
	cin>>n>>m>>s;s=" "+s;
	int f=1; 
	for(int i=1;i<=n;i++)
		cin>>a[i],f&=a[i];
	
	if(n<=18){
		dfs(1);
		cout<<ans%mod<<"\n";
	}
	
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	ios::sync_with_stdio;
//	cin.tie(0);cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}

