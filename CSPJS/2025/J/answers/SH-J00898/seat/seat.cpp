#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],sc;
char ans[105][105];
void fun(int i,int j,int l,int k){//i列 j行 往l走(l1往下，l2往上) a[k]; 
	ans[i][j]=a[k]+'0';
	if(a[k]==sc){
		cout<<i<<' '<<j<<endl;
		return;
	}
	if(l){
		if(j!=n) fun(i,j+1,l,k+1);
		else fun(i+1,j,0,k+1);
	}else{
		if(j!=1) fun(i,j-1,l,k+1);
		else fun(i+1,j,1,k+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	fun(1,1,1,1);
	return 0;
} 
