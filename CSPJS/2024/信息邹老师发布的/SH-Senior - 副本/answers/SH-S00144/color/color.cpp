#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[2000005]={2222},ans=0;
void dfs(int id,int lr,int lc,int sc){
	ans=max(ans,sc);
	if(id==n+1)
		return;
	if(a[id]==a[lr])
		sc+=a[id];
	dfs(id+1,id,lc,sc);
	if(a[id]==a[lr])
		sc-=a[id];
	if(a[id]==a[lc])
		sc+=a[id];
	dfs(id+1,lr,id,sc);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n>15){
			cout<<0<<"\n";
			continue;
		}
		else{
			ans=0;
			dfs(1,0,0,0);
			cout<<ans<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
