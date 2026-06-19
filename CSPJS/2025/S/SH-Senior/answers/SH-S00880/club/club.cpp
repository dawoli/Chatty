#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005],b[100005],c[100005],k,ans;
void dfs(int a1,int b1,int c1,int x,int suma,int sumb,int sumc){
	if(x==n+1&&a1<=k&&b1<=k&&c1<=k){
		ans=max(ans,suma+sumb+sumc);
		return;
	}else if(x==n+1){
		return;
	}else if(a1>k||b1>k||c1>k){
		return;
	}else{
		dfs(a1+1,b1,c1,x+1,suma+a[x],sumb,sumc);
		dfs(a1,b1+1,c1,x+1,suma,sumb+b[x],sumc);
		dfs(a1,b1,c1+1,x+1,suma,sumb,sumc+c[x]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		k=n/2;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(0,0,0,1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
} 
