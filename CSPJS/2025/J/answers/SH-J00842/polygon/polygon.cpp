#include<bits/stdc++.h>
using namespace std;
int n,a[10001]={},v[10001]={};
int cnt=0;
int maxx=0;
int ans=0;
int dfs(int dep){
	if(dep>n){
		return 0;
	}
	for(int i=1;i<=2;i++){
		v[dep]=2-i;
		dfs(dep+1);
		if(dep==n){
			maxx=0;
			int num=0;
			cnt=0;
			for(int j=1;j<=n;j++){
				if(v[j]==1){
					maxx=max(maxx,a[j]);
					cnt+=a[j];
					num++;
				}
			}
			if(cnt>2*maxx&&num>=3){
				ans++;
				ans=ans%998244353;
				/*for(int j=1;j<=n;j++){
					cout<<v[j]<<" ";
				}
				cout<<endl;*/
			}
		}
	}
	
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
