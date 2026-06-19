#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 110
int n,m,a[N][N],cnt;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			cnt+=(a[i][j]>=a[1][1]); 
		}
	}
	cout<<((cnt-1)/n+1)<<' '<<(((cnt-1)/n%2==0)?((cnt-1)%n+1):(n-(cnt-1)%n))<<'\n';
	return 0;
}
