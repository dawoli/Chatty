#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],x,b[15][15],kkksc03;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[++kkksc03];
				if(a[kkksc03]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[++kkksc03];
				if(a[kkksc03]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
