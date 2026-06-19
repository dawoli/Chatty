#include<bits/stdc++.h>
using namespace std;
const int N=105;

bool cmp(int a,int b){
	return a>b;
}

int a[N],b[15][15],n,m,target;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	target=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;++j){
		if(j%2==1){
			for(int i=1;i<=n;++i){
				b[i][j]=a[(j-1)*n+i];
			}
		}
		else{
			for(int i=n;i>=1;--i){
				b[i][j]=a[(j-1)*n+n-i+1];
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(b[i][j]==target){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
