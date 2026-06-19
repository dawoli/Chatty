#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,pos;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(r==a[i]){
			pos=i;
			break;
		}
	int t=ceil(double(pos)/n);
	if(t%2==1){
		if(pos%n==0)cout<<t<<" "<<n;
		else cout<<t<<" "<<pos%n; 
	}else{
		if(pos%n==0)cout<<t<<" "<<1;
		else cout<<t<<" "<<n-pos%n+1;
	}
} 
