#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,m;
int a[109];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	int y;
	for(int i=1;i<=n*m;i++)
		if(a[i]==x){
			y=n*m-i+1;
			break;
		}
	if(y%n==0){
		cout<<y/n<<" ";
		if((y/n)%2==0)
			cout<<1;
		else
			cout<<n;
	}
	else{
		cout<<y/n+1<<" ";
		if((y/n+1)%2==0)
			cout<<n-y%n+1;
		else
			cout<<y%n;
	}
	return 0;
}

