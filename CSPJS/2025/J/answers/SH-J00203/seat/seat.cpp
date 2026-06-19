#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[20][20];
	int x[200];
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
	}
	int r=x[1];
	sort(x+1,x+n*m+1);
	int q=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=x[q];
				q--;
			}	
		}
		else{
			for(int j=n;j>=1;j--){
				a[j][i]=x[q];
				q--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==r){
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
