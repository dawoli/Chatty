#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,c,d,k;
int a[200];
//int b[20][20];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<n*m;i++){
		if(a[i]==c)d=i; 
	}
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				k++;
				if(k==d){
					cout<<j<<' '<<i<<'\n';
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
//				cout<<i<<' '<<j<<'\n';
//				b[i][j]=k;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				k++;
				if(k==d){
					cout<<j<<' '<<i<<'\n';
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
//				b[i][j]=k;
//				cout<<i<<' '<<j<<'\n';
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
