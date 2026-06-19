#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001];
int cont=0,cont1=0;
int sum=0,summax=0;
int memo1[1000][1000];
bool vis1[1000][1000];
int memo[1000];
bool vis[1000];
bool check(int l,int r){
	if(vis1[l][r]){
		return memo1[l][r];
	}
	if(l==r){
		if(a[l]==k){
			return true;
		}else{
			return false;
		}
	}
	vis1[l][r]=true;
	int ans=a[l];
	for(int i=l+1;i<=r;i++){
		ans=ans xor a[i];
	}
	if(ans==k){
		memo1[l][r]=true;
		return true;
	}
	memo1[l][r]=false;
	return false;
}
int dfs(int l,int sum){
	if(vis[l]){
		summax=max(summax,sum+memo[l]);
		return memo[l];
	}
	int x=0;
	bool flag=false;
	for(int i=l;i<=n;i++){
		if(check(l,i)){
			flag=true;
			x=max(x,dfs(i+1,sum+1));
		}
	}
	if(flag) x++;
	summax=max(summax,sum+x);
	vis[l]=true;
	memo[l]=x;
	return x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cont++;
		}else if(a[i]==0){
			cont1++;
		}
	}
	if(cont==n&&k==0){
		cout<<n/2;
		return 0;
	}

	dfs(1,0);
	cout<<summax;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
