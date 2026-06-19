#include<bits/stdc++.h>
using namespace std;

int n,m,p,a[110];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--) if(a[i]==p) p=n*m-i+1;
	if(p%n==0){
		if((p/n)%2==1) cout<<p/n<<" "<<n;
		else cout<<p/n<<" "<<1;
	}
	else{
		if((p/n)%2==1) cout<<p/n+1<<" "<<n-p%n+1;
		else cout<<p/n+1<<" "<<p%n;
	}
	return 0;
}
