#include<bits/stdc++.h>
using namespace std;
long long n,a[111111],c[111111];
long long ans=0;
void b(int x,int y){
	int z=0;
	for(int i=1;i<y;i++){
		z+=c[i];
	}
	if(z>a[x]*2)ans=(ans+1)%998244353;
	
	for(int i=x+1;i<=n;i++){
		c[y]=a[i];
		b(i,y+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3&&a[1]+a[2]+a[3]>a[3]*2){
		cout<<1;
		return 0;
	}
	else if(n==3&&a[1]+a[2]+a[3]<=a[3]*2){
		cout<<0;
		return 0;
	}
	b(0,1);
	cout<<ans;
	return 0;
} 
