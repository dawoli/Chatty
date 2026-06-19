#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1001],b[15][15];
	cin>>n>>m;
	int c;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		if(i==1){
			c=a[1];
		}
	}
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int cnt=0,cmt=1;
	for(int j=1;j<=n;++j){
		if(j%2==1){
			for(int i=1;i<=m;++i){
				b[i][j]=a[i+m*cnt];
			}
			cnt+=2;
		}
		if(j%2==0){
			for(int i=m;i>=1;--i){
				b[i][j]=a[(cmt+1)*m-i+1];
			}
			cmt+=2;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			if(b[i][j]==c){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
