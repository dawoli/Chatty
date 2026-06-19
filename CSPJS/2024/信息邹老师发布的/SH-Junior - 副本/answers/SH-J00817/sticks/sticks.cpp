#include<bits/stdc++.h>
using namespace std;
int st[10]={6,2,5,5,4,5,6,3,7,6},f,k;
long long s=10,j,ans[10000000];
void dfs(int n){
	if(n==0){
		f=1;s=10;
	}
	else if(f==1){
		ans[j]+=n*s;s*=10;
	}
	if(n<0){
		f=2;return;
	}
	if(f==2)return;
	if(f==0){
		for(int i=0;i<=9;i++){
			dfs(n-st[i]);
		}
	}
	if(n==k)j++;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		ans[0]=-1;
		int n;cin>>n;k=n;
		for(int y=0;y<=9;y++){
			dfs(n);
		}
		sort(ans,ans+j);
		cout<<ans[0];
		for(int x=1;x<=j;x++){
			ans[x]=0;
		}
	}
	return 0;
}

