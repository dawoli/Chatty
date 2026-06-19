#include<bits/stdc++.h>
using namespace std;
int a[110],b[12][12];
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1];
	
	sort(a+1,a+n*m+1,cmp);
	
	bool flag=0;
	int ct=1;
	for(int j=1;j<=m;j++){
		if(flag==0) flag=1;
		else flag=0;
		if(flag==1){
			for(int i=1;i<=n;i++){
//				b[i][j]=a[ct];
//				cout<<1;
				
				if(a[ct]==c){
					cout<<j<<' '<<i;
					return 0;
				}
				ct++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
//				b[i][j]=a[ct];
//				cout<<2;
				
				if(a[ct]==c){
					cout<<j<<' '<<i;
					return 0;
				}
				ct++;
			}
		}
		
	}
//	cout<<'\n';
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	
	
	return 0;
}
