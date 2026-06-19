#include<bits/stdc++.h>
using namespace std;

int n,ans=0,h,f;
int a[5500];

bool check(int a,int b){
	if(a>2*b){
		return 1;
	}
	return 0;
}

void dfs(int mx,int l,int ls){
	if(l==0){
		if(check(h,mx)){
			ans++;
			ans=ans%998244353;
			return;
		}
	}
	if(n-ls<l)return;
	for(int j=ls+1;j<=n;j++){
		h+=a[j];
		dfs(max(mx,a[j]),l-1,j);
		h-=a[j];
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<"0";
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(a[1],i,0);
	}
	cout<<ans;
	return 0;
}
