#include<bits/stdc++.h>
using namespace std;
const int N=19;
int a[N*N],ans[N][N],n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xR=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(j%2!=0){
				ans[i][j]=a[i+(j-1)*n];
			}
			else{
				ans[i][j]=a[n-i+(j-1)*n+1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==xR){
				cout<<j<<" "<<i; 
			}
		}
	}
	return 0;
}
