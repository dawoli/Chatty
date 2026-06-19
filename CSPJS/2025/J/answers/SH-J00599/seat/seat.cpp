#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000],o[1000][1000];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int y=a[1];
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[i-1]){
			int w=a[i];
			a[i]=a[i-1];
			a[i-1]=w;
		}
	}
	
	int p=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				o[i][j]=a[p];
				if(p<m*n){
					p++;	
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				o[i][j]=a[p];
				if(p<m*n){
					p++;	
				}
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(o[i][j]==y){
				cout<<i<<" "<<j;
			}
		}
	}
}

