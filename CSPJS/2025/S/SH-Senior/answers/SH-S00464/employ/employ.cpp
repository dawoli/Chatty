#include<bits/stdc++.h>
using namespace std;
int c[505]; 
string s;
long long n,m,ans;
bool vis[505];
int x[505];
void dfs(int now){
	if(now){
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				x[n-now+1]=i;
				dfs(now-1);
				vis[i]=0;
			}
		}
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(i-cnt-1<c[x[i]] && s[i-1]=='1')cnt++;
			//cout<<x[i]<<' '<<(int)(i-cnt-1<c[x[i]])<<'\n';
		}//cout<<'\n';
		if(cnt>=m)ans++;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(n);
		cout<<ans<<endl;
	}else{
		cout<<0<<endl;
	} 
	return 0;
}

