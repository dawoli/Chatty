#include<bits/stdc++.h>
using namespace std;
const int p=998224353;
string s;
int vis[505],a[505],ans,n,m;
void dfs(int c,int fail,int success,int day){
	if(day==n+1){
		if(success>=m){
			ans=(ans+1)%p;
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(c==-1) dfs(a[i],fail,success,day+1);
			else if(fail>=c||s[day]=='0') dfs(a[i],fail+1,success,day+1);
			else dfs(a[i],fail,success+1,day+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(-1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

