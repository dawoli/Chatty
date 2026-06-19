#include<bits/stdc++.h>
using namespace std;
int maxs,n;
int a[100000];
void dfs(int s,int t,int x,int y){
	if(t==n+1){
		maxs=max(s,maxs);
		return;
	}
	dfs((a[t]==x?s+a[t]:s),t+1,a[t],y);
	dfs((a[t]==y?s+a[t]:s),t+1,x,a[t]);
	
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		maxs=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(0,1,0,0);
		cout<<maxs<<endl;
	}
	return 0;
}
/*
10
136 136 136 2417 136 136 2417 136 136 136

*/
