#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
int n,m;
bool task[505];
int nums[505];
int Order[15];
bool vis[15];
int res=0;
bool check(){
	int unemployed=0,employed=0;
	for(int i=1;i<=n;i++){
		if(task[i]==true&&unemployed<Order[i]) employed++;
		else unemployed++;
	}
	return employed>=m;
}
void dfs(int level){
	if(level==n+1){
		if(check()){
			res++;
			if(res>=mod) res-=mod;
		} 
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		Order[level]=nums[i];
		dfs(level+1);
		vis[i]=0;
		Order[level]=0;
		
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		bool res=ch-'0';
		task[i]=res;
	}
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	if(n<=10){
		dfs(1);
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
