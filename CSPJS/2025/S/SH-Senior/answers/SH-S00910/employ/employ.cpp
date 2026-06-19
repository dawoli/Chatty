#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
string s;
int a[510];
int n,m;
ll sum;
int cnt;
bool vis[510];
void dfs(int id,int num,int last){
	if(id==n+1){
		if(num>=m){
			cnt++;
			cnt%=mod;
		}
		return ;
	}
	if(n-id+1+num<m) return ;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		if(last>=a[i]){
			vis[i]=1;
			dfs(id+1,num,last+1);
			vis[i]=0;
		}else{
			if(s[id-1]=='0'){
				vis[i]=1;
				dfs(id+1,num,last+1);
				vis[i]=0;
			}else{
				vis[i]=1;
				dfs(id+1,num+1,last);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
