#include<bits/stdc++.h>
using namespace std;
int cnt,n,m,c,r,a[109],k,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]) cnt=i;
	}
	cnt=n*m+1-cnt;
	if(cnt%n==0) c=cnt/n;
	else c=cnt/n+1;
	k=cnt/n;
	if(cnt%n==0) f=0;
	else f=cnt-k*n;
	if(k==0) r=cnt;
	else if(k%2==1&&(f==0||f==1)) r=n;
	else if(k&2==1&&f>1) r=n-f+1;
	else if(k%2==0&&(f==0||f==1)) r=1;
	else if(k%2==0&&f>1) r=f; 
	cout<<c<<" "<<r;
	return 0;
}
