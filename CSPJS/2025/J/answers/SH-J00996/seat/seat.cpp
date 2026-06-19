#include<bits/stdc++.h>
using namespace std;
const int N=109;
int n,m,a[N],ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int b=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
		if(a[i]==b)
			ans=n*m-i+1;
	int c,r;
	c=(ans-1)/n+1;
	if(c%2!=0){
		if(ans%n!=0) r=ans%n;
		else r=n;
	}
	else{
		if(ans%n!=0) r=n-(ans%n)+1;
		else r=1;
	}
	cout<<c<<" "<<r;
	return 0;
}
