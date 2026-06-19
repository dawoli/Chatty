#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
bool vis[5010];
int cnt;

priority_queue<int> use;

bool check(){
	while(!use.empty()) use.pop();
	for(int i=1;i<=n;i++) if(vis[i]) use.push(a[i]);
	if(use.size()<3) return 0;
	int sum=0;
	int largest=use.top();
	while(!use.empty()){
		sum+=use.top();
		use.pop();
	}
	if(sum<=2*largest) return 0;
	return 1;
}


void dfs(int x){
	if(x==n+1){
		if(check()){
		 cnt++;
		}	 
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cnt=0;
	dfs(1);
	cout<<cnt;
	return 0;
}
