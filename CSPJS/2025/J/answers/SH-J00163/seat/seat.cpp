#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1],num=1;
	for(int i=2;i<=n*m;i++) if(a[i]>x) num++;
	int ans1=(num+n-1)/n,ans2=num%n;
	if(ans2==0) ans2=n;
	if(ans1%2==1) cout<<ans1<<" "<<ans2;
	else cout<<ans1<<" "<<n-ans2+1;
	return 0;
} 
