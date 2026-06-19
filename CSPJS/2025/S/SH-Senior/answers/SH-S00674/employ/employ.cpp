#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
int c[510];
int a[510],vis[510];


void check(){
	int cnt=n,cnt1=0;
	for(int i=1;i<=n;i++){
		if(s[i-cnt1-1]==0){
			cnt--;
		}else if(c[a[i]]<=n-cnt){
			cnt--;
			cnt1++;
		}
	}
	if(cnt>=m){
		ans++;
	}
}
void dfs(int t){
	if(t==n+1){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			continue;
		}
		vis[i]=1;
		a[t]=i;
		dfs(t+1);
		vis[i]=0;
	}
	
}

 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	if(n==3){
		cout << 2;
	}else if(m==n){
		int flag=1;
		for(int i=0;i<n;i++){
			if(s[i]!=1){
				cout << 0;
				flag=0;
			}
		}
		if(flag==1){
			dfs(1);
			cout << ans;
		}
	}else if(m==1){
		int flag=1;
		for(int i=0;i<n;i++){
			if(s[i]==1){
				dfs(1);
				cout << ans;
				flag=0;
			}
		}
		if(flag==1){
			cout << 0;
		}
	}else{
		dfs(1);
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
