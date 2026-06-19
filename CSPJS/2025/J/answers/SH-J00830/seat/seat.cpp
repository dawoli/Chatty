#include<bits/stdc++.h>
using namespace std;
int n,m,x;
struct points{
	int po,p;
}a[105];
bool cmp(points a,points b){
	return a.po>b.po;
}
int main(){
	cin>>n>>m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=1;i<=n*m;i++){
		cin>>a[i].po;
		a[i].p=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].p==1){
			x=i;
			continue;
		}
	}
	if(int(ceil(x*1.0/n))%2==1){
		cout<<int(ceil(x*1.0/n))<<' ';
		if(x%n==0) cout<<n;
		else cout<<x%n;
	}
	else if(int(ceil(x*1.0/n))%2==0){
		cout<<int(ceil(x*1.0/n))<<' ';
		if(x%n==0) cout<<1;
		else cout<<n-x%n+1;
	}
	return 0;
}
