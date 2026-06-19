#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],b[11][11],c[105],cnt=0;
	cin>>n>>m;
	cin>>a[0];
	int xa=a[0];
	for(int i=1;i<n*m;i++)cin>>a[i];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--)c[cnt++]=a[i];
	cnt=0;
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				b[j][i]=c[cnt++];
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				b[j][i]=c[cnt++];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(b[i][j]==xa)cout<<j+1<<' '<<i+1;
		}
	}
	return 0;
}
