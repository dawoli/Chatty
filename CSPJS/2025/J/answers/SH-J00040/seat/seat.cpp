#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200];
int num;
int b[20][20];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int nx=1,ny=1,cur=0;
	bool f=0;
	for(int i=1;i<=n;i++){
		if(f==0){
			for(int j=1;j<=m;j++)
				b[i][j]=a[++cur];
			f=1;
		}
		else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[++cur];
			}
			f=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==num){
				cout<<i<<' '<<j<<endl;
				return 0;
			}
		}
	}
}
