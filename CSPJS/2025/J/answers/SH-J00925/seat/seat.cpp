#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],num,dp[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1);
	int cnt=n*m;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				dp[j][i]=a[cnt];
				cnt--;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				dp[j][i]=a[cnt];
				cnt--;
			}
		}
	}
	int c,r;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]==num){
				c=i;
				r=j;
				break;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
