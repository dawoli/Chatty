#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,ans,sum=1,x,y;
	cin>>n>>m;
	cin>>ans;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>ans)sum++;
	}
	if(sum%n==0)x=sum/n;
	else x=sum/n+1;
	y=sum%n;
	if(y==0)y=n;
	if(x%2==1)cout<<x<<" "<<y;
	else cout<<x<<" "<<n-y+1;
	return 0;
}
