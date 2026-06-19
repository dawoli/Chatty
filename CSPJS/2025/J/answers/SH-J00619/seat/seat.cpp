#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1);
	int cnt=1;
	for(int i=m;i>0;i--)
		for(int j=n;j>0;j--){
			ans[j][i]=a[cnt];
			cnt++;
		}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(ans[j][i]==r)cout<<i<<" "<<j;
	return 0;
}
