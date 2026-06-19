#include<bits/stdc++.h>
using namespace std;
int a[100010];
int dfs(int n,int r,int b){
	if(n==1)return 0;
	if(a[n]==r)return dfs(n-1,a[n],b)+r;
	else return dfs(n-1,a[n],b);
	if(a[n]==b)return dfs(n-1,r,a[n])+b;
	else return dfs(n-1,r,a[n]);
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
	int n,cnt;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(n,0,0)<<"\n";
	}
	return 0;
}
