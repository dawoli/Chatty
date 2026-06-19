#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int r;
bool alpha(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);//
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,alpha);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*n+j]==r){
				if(i%2==1){
					cout<<i<<' '<<j;
					return 0;
				}
				else{
					cout<<i<<' '<<n+1-j;
					return 0;
				}
			}
		}
	}
}
