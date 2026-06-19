#include<bits/stdc++.h>
using namespace std;
int a[1010];
int b[110][110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+1+m*n);
	int i1=1;
	int j1=1;
	for(int i=n*m;i>=1;i--){
		if(i1%2==1 && j1<=m && i1<=n && j1>0 && i1>0){
			b[i1][j1]=a[i];
			j1++;
		}
		if(i1%2==1 && j1==m+1 && i1<=n && j1>0 && i1>0){
			j1--;
			i1++;
			b[i1][j1]=a[i];
			i--;
		}
		if(i1%2==0 && j1<=m && i1<=n && j1>0 && i1>0){
			b[i1][j1]=a[i];
			j1--;
		}
		if(i1%2==0 && j1==0 && i1<=n){
			j1++;
			i1++;
			b[i1][j1]=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(k==b[i][j]) cout<<i<<" "<<j;
		}
	}
	return 0;
}
