#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
int now=0,maxn=0;
int l[5007];
//void dfs(int a,int l,int num){
//	if(a==0){
//		return num;
//	}
//	for(int i=1;i<=2;i++){
//		if(i%2==0) num+=
//	}
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		now+=l[i];
		maxn=max(maxn,l[i]);
	}
	if(now>(maxn*2)) ans++;
	cout<<ans;
	return 0;
}
