#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N];
bool vis[N];
int c[N];
int x[N];
int ans=0;
int n,m;
bool check(){
	//cout<<"check: a=";for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(x[i]==0)cnt++;
		else if(cnt>=a[i])cnt++;
		if(n-cnt<m)return false;
	}
	return true;
}
void dfs(int t,int cnt){
	if(n-cnt<m)return;
	if(t>n){
		//cout<<"check: a=";for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
		//cout<<"cnt="<<cnt<<endl<<endl;
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		a[t]=c[i];
		bool flag=0;
		if(x[t]==0)cnt++,flag=1;
		else if(cnt>=c[i])cnt++,flag=1;
		dfs(t+1,cnt);
		cnt-=flag;
		vis[i]=0;
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		x[i]=(ch=='1');
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	//cout<<"x: ";for(int i=1;i<=n;i++)cout<<x[i]<<" ";cout<<endl;
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
