#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],ans,preans;
bool color[200005];
void dfs(int x,int nb,int nr){
	if(x==n+1){
//		if(ans<preans){
//			for(int i=1;i<=n;i++)cout<<color[i]<<" ";
//			cout<<endl;
//		}
		ans=max(ans,preans);
		return;
	}
	color[x]=1;
	if(a[x]==nb)preans+=nb;
	dfs(x+1,a[x],nr);
	if(a[x]==nb)preans-=nb;
	
	color[x]=0;
	if(a[x]==nr)preans+=nr;
	dfs(x+1,nb,a[x]);
	if(a[x]==nr)preans-=nr;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		preans=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		dfs(1,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1
8
3 5 2 5 1 2 1 4
*/
