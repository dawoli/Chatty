#include<bits/stdc++.h>
using namespace std;
int t,n,a[200000],ans,c[200000];
void dfs(int u){
	if(u==n){
		int num=0;
		for(int i=0;i<n;i++)
			for(int j=i-1;j>=0;j--){
				if(c[j]!=c[i])continue;
				if(a[j]==a[i]){num+=a[j];break;}
				else break;
			}
		ans=max(ans,num);return;
	}
	dfs(u+1);c[u]=1;dfs(u+1);c[u]=0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;ans=0;
		for(int i=0;i<n;i++)cin>>a[i];
		dfs(0);cout<<ans<<endl;
	}
	return 0;
} 
