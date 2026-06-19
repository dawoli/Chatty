#include<bits/stdc++.h>
using namespace std;
long long n,m,r,a[111111];
bool cmp(const long long&a,const long long&b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	int b=(r-1)/n;
	if(b%2==0){
		cout<<b+1<<" "<<r-b*n;
	}
	else{
		cout<<b+1<<" "<<n-(r-b*n)+1;
	}
	return 0;
} 
