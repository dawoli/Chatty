#include<bits/stdc++.h>
using namespace std;
int n,m,s[11][11],a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==1)s[i][j]=a[i*n-n+j];
			if(i%2==0)s[i][j]=a[i*n-j+1];
			if(s[i][j]==x){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}
