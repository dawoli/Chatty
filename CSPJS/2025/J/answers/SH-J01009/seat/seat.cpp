#include<bits/stdc++.h>
using namespace std;
const int N=19;
const int MAX=109;

int n,m,a[MAX],d[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	int k=a[1],cnt=m*n;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			d[j][i]=a[cnt];
			cnt--;
		}
		for(int j=n;j>=1;j--){
			if(i+1>m)	break;
			d[j][i+1]=a[cnt];
			cnt--;
		}
		if(i+2>m)	break;	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(d[i][j]==k)	cout<<j<<" "<<i;
		}
	}
	return 0;
} 

