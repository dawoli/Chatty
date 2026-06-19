#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],a1,wz;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a1==a[i])wz=n*m-i+1;
//		cout<<a1<<" "<<a[i]<<" " <<i<<endl;
	}
//	cout<<wz<<endl;
	long long li,ha;
	li=(wz+n-1)/n;
	
	ha=wz%n;
	if(ha==0)ha=n;
	if(li%2==0){
		ha=n-ha+1;
	}
	cout<<li<<" "<<ha;
}
