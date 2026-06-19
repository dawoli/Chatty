#include<bits/stdc++.h>
using namespace std;
int n,num[5005],ans=0,kk[5005];
void dfs(int cnt,int dep,int vv){
	if(dep>cnt){
		int w=0,maxw=-1;
		for(int i=1;i<=cnt;i++){
			w+=kk[i];
			maxw=max(maxw,kk[i]);

		}

		if(w>maxw*2)ans++;
		return ;
	}
	for(int i=vv+1;i<=n;i++){
		kk[dep]=num[i];
		dfs(cnt,dep+1,i);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=3;i<=n;i++){
		dfs(i,1,0);
	}
	cout<<ans%998244353;
	fclose(stdin);fclose(stdout);
	return 0;
}
