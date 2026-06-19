#include <bits/stdc++.h>
using namespace std;
const int N=500009;
int n,k,a[N],xr[N],f[N];
void input(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xr[i]=(xr[i-1] xor a[i]);
	}
	return;
}
int dfs(int p){
	if(f[p]!=-1){
		return f[p];
	}
	for(int i=p-1;i>=0;i--){
		int ans=dfs(i);
		if((xr[p] xor xr[i]) == k){
			ans++;
		}
		if(f[p]<ans){
			f[p]=max(f[p],ans);
		}
	}
	return f[p];
}
void solvebf(){
	for(int i=1;i<=n;i++){
		f[i]=-1;
	}
	f[0]=0;
	if(a[1]==k){
		f[1]=1;
	}else{
		f[1]=0;
	}
	cout<<dfs(n)<<endl;
	return;
}
void solve(){
	solvebf();
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	input();
	if(n<=8000){
		solvebf();
	}else{
		solve();
	}
	return 0;
}
