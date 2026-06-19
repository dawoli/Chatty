#include<bits/stdc++.h>
using namespace std;
int xl[550000],n,k,js=0;
int xr(int a,int b){
	return((a|b)&(0-~(a&b)));
}
void dfs(int sg,int xz,int dx){
	if(xz>=n){
		return;
	}
	int zs=xl[dx];
	for(int i=dx+1;i<=xz;i++){
		zs=xr(zs,xl[i]);
	}
	if(zs==k){
		js++;
		dfs(xz,xz+1,xz+1);
	}
	else {
		if(dx==xz){
			dfs(sg,xz+1,sg+1);
		}
		else{
			dfs(sg,xz,dx+1);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>xl[i];
	}
	dfs(-1,0,0);
	cout<<js;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

