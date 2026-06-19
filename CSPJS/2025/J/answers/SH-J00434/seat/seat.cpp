#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int g[15][15];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int r=a[1];
	int cnt=s;
	sort(a+1,a+s+1);
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				g[i][j]=a[cnt--];
			}
		}
		else{
			for(int j=m;j>=1;j--){
				g[i][j]=a[cnt--];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]==r) cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}
