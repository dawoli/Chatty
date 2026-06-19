#include<bits/stdc++.h>
using namespace std;

int T;
int n;
int a[1000];
int ans=0;

void dfs(int p,int k){
	if(k==n){
		int b[39]={},c[39]={};
		for(int i=0;i<n;i++){b[i]=(p>>i)&1;}
		//for(int i=0;i<n;i++){cerr<<b[i];}cout<<"\n";
		int pre[2]={-1,-1};
		for(int i=0;i<n;i++){
			if(a[pre[b[i]]]==a[i])c[i]=a[pre[b[i]]];
			pre[b[i]]=i;
		}
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=c[i];
		}
		ans=max(ans,sum);
		return;
	}
	dfs(p*2+1,k+1);
	dfs(p*2,k+1);
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;	
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		dfs(0,0);
		cout<<ans<<"\n";
	}
} 
