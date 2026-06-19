//RP++
#include <bits/stdc++.h>
#define N 20
using namespace std;
int a[N][N];
int b[400];
bool cmp(int n1,int n2){
	return n1>n2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,k=1;
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	a1=b[1];
	sort(b+1,b+n*m+1,cmp);
	k=1;
	for(int i=1;i<=m;i++){	
		//ÁÐ 
		if(i%2){
			for(int j=1;j<=n;j++,k++){
				//ÐÐ 
				a[j][i]=b[k];
				if(b[k]==a1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--,k++){
				a[j][i]=b[k];
				if(b[k]==a1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	/*
	cout<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<' '; 
		} 
		cout<<endl;
	}
	*/
	return 0;
}
