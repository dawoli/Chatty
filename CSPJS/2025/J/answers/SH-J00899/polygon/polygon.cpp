#include <bits\stdc++.h>
using namespace std;
int n;
int a[5010];
int vis[5010][200];
int ans;
//int dfs(){
//	
//} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=max(x,a[i]);
	}
	if(x==1){
		long long ans=1;
		while(ans>=3){
			ans*=n;
			n--;
			ans%=998244353;
		}
	}else if(n==3){
		int ljq=0;
		int zdz=0;
		for(int i=1;i<=n;i++){
			ljq+=a[i];
			zdz=max(zdz,a[i]);
		}
		if(ljq>zdz){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}

//	else{
//		dfs();
//	}
	
	return 0;
} 
