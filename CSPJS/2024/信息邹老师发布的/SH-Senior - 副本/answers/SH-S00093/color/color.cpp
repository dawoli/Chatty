#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n;
int a[N];
int vis[N];
long long query(){
	long long res=0;
	for(int i=1;i<=n;i++){
		for(int t=i-1;t>=1;t--){
			if(vis[t]==vis[i]&&a[t]==a[i]){
				res+=a[t];
				t=0;
			}
		}
	}
	return res;
}
long long dfs(int lv){
	if(lv>n){
		return query();
	}
	vis[lv]=0;
	long long val1=dfs(lv+1);
	vis[lv]=1;
	long long val2=dfs(lv+1);
	return max(val1,val2);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<dfs(1)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
