#include<bits/stdc++.h>
using namespace std;
long long a[101];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	cin>>a[1];
	long long s=a[1];
	for(long long i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1);
	long long k;
	for(long long i=1;i<=n*m;i++) if(a[i]==s){k=n*m-i;break;}
	cout<<k/n+1<<" "<<(k%(2*n)+1<=n?k%n+1:n-k%n)<<endl;
	return 0;
}
