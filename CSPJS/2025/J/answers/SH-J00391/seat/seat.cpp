#include<bits/stdc++.h>
using namespace std;
int n,m,a[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	a[0]=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--)
		if(a[i]==a[0]){
			a[0]=n*m-i+1;
			break;
		}
	int x=(a[0]+n-1)/n;
	int y=a[0]%n;
	if(y==0)y=n;
	if(x%2==0)y=m-y+1;
	cout<<x<<" "<<y;
	return 0;
}
