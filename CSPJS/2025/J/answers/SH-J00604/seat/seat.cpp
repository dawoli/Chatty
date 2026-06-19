#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15];
int g[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>g[i];
	}
	int v=g[1];
	sort(g+1,g+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=g[(i-1)*n+j];
			}
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=g[(i-1)*n+(n-j+1)];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==v){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}

