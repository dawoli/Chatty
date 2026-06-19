#include <bits/stdc++.h>
using namespace std;
int n,m,c[510],a[510],vis[510];
char s[510];
int now,cnt;
bool check(){
//	cout<<"check:";
//	for(int i=0;i<n;i++) cout<<a[i]<<" ";
//	cout<<endl;
	now=0,cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'||now>=c[a[i]]) now++;
		else cnt++;
	}
	if(cnt>=m){
//		cout<<1;
		return true;
	}
	return false;
}
int dfs(int depth){
	if(depth==n){
		if(check()) return 1; 
	}
	int sum=0;
	for(int i=0;i<n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		a[depth]=i;
		sum+=dfs(depth+1);
		vis[i]=false;
		sum%=998244353;
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i]; 
	}
	cout<<dfs(0);
	return 0;
}
