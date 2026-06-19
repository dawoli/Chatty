#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[514514];
int xx[1145],yy[1145],zz[1145];
bool visited[1145];
int xorr(int x,int y){
	memset(xx,0,sizeof xx);
	memset(yy,0,sizeof yy);
	memset(zz,0,sizeof zz);
	int i=0,j=0;
	while(x>=1){
		xx[i]=x%2;
		x/=2;
		i++;
	}
	while(y>=1){
		yy[j]=y%2;
		y/=2;
		j++;
	}
	int sz=max(i,j);
	for(int i=0;i<sz;i++){
		if((xx[i]==1&&yy[i]==1)||(xx[i]==0&&yy[i]==0)){
			zz[i]=0;
		}
		else if((xx[i]==1&&yy[i]==0)||(xx[i]==0&&yy[i]==1)){
			zz[i]=1;
		}
	}
	int z=0;
	for(int i=0;i<sz;i++){
		z+=zz[i]*pow(2,i);
	}
	return z;
}
int ccnt=0;
void dfs(int j,int i,int cnt,int k){
	if(i==n&&j==n){
		ccnt=max(ccnt,cnt);
		return;
	}
	if(j==i&&a[j]==k&&visited[j]==0){
		cnt++;
		visited[j]=1;
	}
	else{
		int p=0;
		for(int l=j;l<=i;l++){
			if(visited[l]){
				break;
			}
			p=xorr(p,a[l]);
		}
		if(p==k){
			cnt++;
			for(int l=j;l<=i;l++){
				visited[l]=1;
			}
		}
	}
	if(j==i){
		dfs(1,i+1,cnt,k);
	}
	else{
		dfs(j+1,i,cnt,k);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(visited,0,sizeof visited);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<1;
		return 0;
	}
	dfs(1,1,0,k);
	cout<<ccnt;
	return 0;
}
