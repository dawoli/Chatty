#include<bits/stdc++.h>
using namespace std;
int s[15][15];
int n,m,mi=1,cnt=0,a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			mi++;
		}
	}sort(a,a+n*m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			s[i][j]=a[cnt];
			cnt++;
			if(cnt==mi){
				if(i%2==0){
					cout<<i<<' '<<n-j+1;
				} 
				else{
					cout<<i<<' '<<j;
				}
			}
		}
	}
	return 0;
}
