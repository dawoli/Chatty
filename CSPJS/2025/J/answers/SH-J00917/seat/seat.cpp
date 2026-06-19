#include<bits/stdc++.h>
using namespace std;
	int n,m,r,a[10010],x=1,b[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		x++;
	}
	sort(a+1,a+1+x);
	for(int i=1;i<=m;i++){
		int j;
			if(i%2==0)  j=n;
			else  j=1;
		while(j!=0&&j!=n+1){
			b[i][j]=a[x--];
			if(i%2==0)j--;
			else j++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r==b[i][j]){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
