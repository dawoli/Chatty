#include<bits/stdc++.h>//T2¿Ï¶¨100·Ö 
using namespace std;
int a[105],seat[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1],pn=n*m;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++) seat[i][j]=a[pn--];
		}
		else{
			for(int j=m;j>=1;j--) seat[i][j]=a[pn--];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r==seat[i][j]) cout<<i<<' '<<j;
		}
	}
	return 0;
}
