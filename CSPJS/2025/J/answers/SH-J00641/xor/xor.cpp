#include<bits/stdc++.h>
using namespace std;
int maxn=0,m=0;
int n,k,a[500001];
int x(int l,int r,int ans){
	if(l>=r){
		ans=a[l]|ans;
		return ans;
	}
	ans=a[l]|ans;
	return x(l+1,r,ans);
}
void y(int l,int r,int m){
	for(int i=l;i<=r;i++){
		for(int j=i;j<=r;j++){
			if(x(i,j,0)==k){
				y(j+1,n,m+1);
			}
		}
	}
	maxn=max(maxn,m);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	y(1,n,0);
	cout<<maxn;
	return 0;
} 

