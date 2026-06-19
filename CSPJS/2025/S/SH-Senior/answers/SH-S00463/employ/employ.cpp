#include<bits/stdc++.h>

using namespace std;
const int mod=998244353;
string s;
int c[507];
int n,m;
int p[507];
bool vis[507];
long long sum;
void dfs(int now){
	if(now==n+1){
		int ans=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]||s[i-1]=='0'){
				cnt++;
			}
			else{
				ans++;
			}
		}
		if(ans>=m){
			sum++;
			sum=sum%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			p[now]=i;
			vis[i]=1;
			dfs(now+1);
			p[now]=0;
			vis[i]=0;
		}
	}
	vis[p[now]]=0;
	p[now]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	} 
	if(n<=18){
		dfs(1);
		cout<<sum%mod<<endl;
	}
	return 0;
}
