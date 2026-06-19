#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b[15][15];
bool cmp(int x,int y){
	return x>y;
}
/*
100 97 96
99 98 95
*/
int main(){
	freeopen("seat.in","r",stdin);
	freeopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int Target=a[1],cnt=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[cnt++];
				if(a[cnt-1]==Target){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[cnt++];
				if(a[cnt-1]==Target){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}	
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}
